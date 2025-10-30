/***********************************************************************************************************************
 * Copyright [2020-2021] Renesas Electronics Corporation and/or its affiliates.  All Rights Reserved.
 *
 * This software and documentation are supplied by Renesas Electronics Corporation and/or its affiliates and may only
 * be used with products of Renesas Electronics Corp. and its affiliates ("Renesas").  No other uses are authorized.
 * Renesas products are sold pursuant to Renesas terms and conditions of sale.  Purchasers are solely responsible for
 * the selection and use of Renesas products and Renesas assumes no liability.  No license, express or implied, to any
 * intellectual property right is granted by Renesas.  This software is protected under all applicable laws, including
 * copyright laws. Renesas reserves the right to change or discontinue this software and/or this documentation.
 * THE SOFTWARE AND DOCUMENTATION IS DELIVERED TO YOU "AS IS," AND RENESAS MAKES NO REPRESENTATIONS OR WARRANTIES, AND
 * TO THE FULLEST EXTENT PERMISSIBLE UNDER APPLICABLE LAW, DISCLAIMS ALL WARRANTIES, WHETHER EXPLICITLY OR IMPLICITLY,
 * INCLUDING WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT, WITH RESPECT TO THE
 * SOFTWARE OR DOCUMENTATION.  RENESAS SHALL HAVE NO LIABILITY ARISING OUT OF ANY SECURITY VULNERABILITY OR BREACH.
 * TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT WILL RENESAS BE LIABLE TO YOU IN CONNECTION WITH THE SOFTWARE OR
 * DOCUMENTATION (OR ANY PERSON OR ENTITY CLAIMING RIGHTS DERIVED FROM YOU) FOR ANY LOSS, DAMAGES, OR CLAIMS WHATSOEVER,
 * INCLUDING, WITHOUT LIMITATION, ANY DIRECT, CONSEQUENTIAL, SPECIAL, INDIRECT, PUNITIVE, OR INCIDENTAL DAMAGES; ANY
 * LOST PROFITS, OTHER ECONOMIC DAMAGE, PROPERTY DAMAGE, OR PERSONAL INJURY; AND EVEN IF RENESAS HAS BEEN ADVISED OF THE
 * POSSIBILITY OF SUCH LOSS, DAMAGES, CLAIMS OR COSTS.
 **********************************************************************************************************************/
/*
 * Copyright (c) 2014, Mentor Graphics Corporation
 * All rights reserved.
 * Copyright (c) 2017 Xilinx, Inc.
 * Copyright (c) 2020, eForce Co., Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**************************************************************************
 * FILE NAME
 *
 *       rzg3_rproc.c
 *
 * DESCRIPTION
 *
 *       This file defines RZ/G2 CA5X/CR7 remoteproc implementation.
 *
 * @par  History
 *       - rev 1.0 (2020.10.21) Imada
 *         Initial version.
 *
 **************************************************************************/

#include <metal/atomic.h>
#include <metal/assert.h>
#include <metal/device.h>
#include <metal/irq.h>
#include <metal/list.h>
#include <metal/utilities.h>
#include <openamp/rpmsg_virtio.h>
#include "platform_info.h"
#include "semphr.h"
#include "hal_data.h"

extern struct ipi_info ipi[];
extern struct mbx_channel chn_info[];

/* Inline functions to add accessing address check to corresponding
 * libmetal functions to avoid accessing a reserved region.
 * They are mainly required because of larger (uio) mmap size due the
 * 4KB page size on Verified Linux. They are also utilized for FreeRTOS because
 * accessing a reserved area of registers can cause system failure.
 */
static int init_memory_device (struct remoteproc * rproc, struct shm_info * info) {
    struct metal_device * dev;
    metal_phys_addr_t     mem_pa;
    int ret;

    ret = metal_device_open(info->bus_name, info->name, &dev);
    if (ret)
    {
        LPERROR("Failed to open uio device %s: %d.\n", info->name, ret);
        goto err;
    }

    LPRINTF("Successfully open uio device: %s.\n", info->name);

    info->dev = dev;
    info->io  = metal_device_io_region(dev, 0x0U);
    if (!info->io)
    {
        goto err;
    }

    mem_pa = metal_io_phys(info->io, 0x0U);
    remoteproc_init_mem(&info->mem, info->name, mem_pa, mem_pa, metal_io_region_size(info->io), info->io);
    remoteproc_add_mem(rproc, &info->mem);
    LPRINTF("Successfully added memory device %s.\n", info->name);

    return 0;
err:
    if (info->dev)
    {
        metal_device_close(info->dev);
    }

    return ret;
}

static int rzg3_mhu_master_callback (mhu_callback_args_t * p_args)
{
	unsigned int		val = 0U;
	unsigned int		*mbx_chn_id = p_args->p_context;
	atomic_flag *sync;
	BaseType_t taskWoken;

	val = p_args->msg;
	if (val >= RSC_MAX_NUM || *mbx_chn_id >= MBX_CH_NUM)
	{
		return METAL_IRQ_NOT_HANDLED; /* Invalid message arrived */
	}

	ipi[*mbx_chn_id].notify_id = val;
	sync = &(ipi[*mbx_chn_id].sync);
	atomic_flag_clear(sync);
	xTaskNotifyFromISR(*task_id, 0x0001, eSetBits, taskWoken);

	return METAL_IRQ_HANDLED;
}

static int rzg3_mhu_slave_callback (mhu_callback_args_t * p_args)
{
	unsigned int		val = 0U;
	unsigned int		*mbx_chn_id = p_args->p_context;
	signed portBASE_TYPE xHigherPriorityTaskWoken;

    val = p_args->msg;

    if (val >= RSC_MAX_NUM || *mbx_chn_id >= MBX_CH_NUM)     /* val should have the notify_id of the sender */
    {
        return METAL_IRQ_NOT_HANDLED;  /* Invalid message arrived */
    }

   if (ipi[*mbx_chn_id].ipi_sem_id[val] != NULL)
    {
       xSemaphoreGiveFromISR(ipi[*mbx_chn_id].ipi_sem_id[val], &xHigherPriorityTaskWoken);
    }

    return METAL_IRQ_HANDLED;
}

static int rzg3_enable_interrupt (struct remoteproc * rproc, struct metal_device * ipi_dev)
{
    unsigned int irq_vect;
    int          ret = 0;
    struct remoteproc_priv		* prproc = rproc->priv;

    if (!ipi[prproc->mbx_chn_id].registered)
    {
        /* Register interrupt handler and enable interrupt for RZ/G2 CA5X or CR7 */
        irq_vect = (uintptr_t) ipi_dev->irq_info;
        ret      = metal_irq_register((int) irq_vect, R_MHU_NS_IsrSub, ipi_dev, rproc);
        if (ret)
        {
            LPRINTF("metal_irq_register() failed with %d", ret);

            return ret;
        }

        metal_irq_enable(irq_vect);
    }

    return ret;
}

static void rzg3_disable_interrupt (struct remoteproc * rproc)
{
    struct remoteproc_priv		* prproc = rproc->priv;
    struct metal_device * dev;
    int ret;

    dev = ipi[prproc->mbx_chn_id].dev;
    if (dev)
    {
        metal_irq_disable((uintptr_t) dev->irq_info);
        ret = metal_irq_unregister((int) dev->irq_info, NULL, NULL, NULL);
        if (ret)
        {
            LPRINTF("metal_irq_unregister() failed with %d", ret);

            return;
        }

        metal_device_close(dev);
        ipi[prproc->mbx_chn_id].registered = 0;
    }
}

static struct remoteproc * rzg3_proc_init (struct remoteproc * rproc, struct remoteproc_ops * ops, void * arg)
{
	unsigned int			irq = 0U;
    struct remoteproc_priv 	* prproc = arg;
    struct metal_device    	* dev;
    int ret;

#ifndef __linux__ 		/* FreeRTOS */
    mhu_instance_t* mhu = chn_info[prproc->mbx_chn_id].mhu;

    /* Initialize MHU driver */
    mhu->p_api->open(mhu->p_ctrl, mhu->p_cfg);

    irq = mhu->p_cfg->rx_irq;

    if((irq < MHU2_NS_IRQn) || (irq > MHU3_NS_IRQn))
    {
        mhu->p_api->callbackSet(mhu->p_ctrl, rzg3_mhu_slave_callback, &(prproc->mbx_chn_id), NULL);
    } else
    {
        mhu->p_api->callbackSet(mhu->p_ctrl, rzg3_mhu_master_callback, &(prproc->mbx_chn_id), NULL);
    }
#endif
    if ((!rproc) || (!prproc) || (!ops))
    {
        return NULL;
    }

    rproc->priv = prproc;
    rproc->ops  = ops;

    if (!ipi[prproc->mbx_chn_id].registered)
    {
        /* Get an IPI device (Mailbox) */
        ret = metal_device_open(ipi[prproc->mbx_chn_id].bus_name, ipi[prproc->mbx_chn_id].name, &dev);
        if (ret)
        {
            LPERROR("Failed to open ipi device: %d.\n", ret);

            return NULL;
        }

        ipi[prproc->mbx_chn_id].dev = dev;
        ipi[prproc->mbx_chn_id].io  = metal_device_io_region(dev, 0x0U);
        if (!ipi[prproc->mbx_chn_id].io)
        {
            goto err1;
        }

#ifdef __linux__
        atomic_flag_test_and_set(&ipi.sync);
#endif

        LPRINTF("Successfully probed IPI device\n");
    }

#ifdef _linux_
	ipi[prproc->mbx_chn_id].irq_info = chn_info[prproc->mbx_chn_id].irq_info;
#else
	ipi[prproc->mbx_chn_id].irq_info = mhu->p_cfg->rx_irq;
#endif
    ipi[prproc->mbx_chn_id].mbx_chn = chn_info[prproc->mbx_chn_id];

    ret = rzg3_enable_interrupt(rproc, ipi[prproc->mbx_chn_id].dev);
    if (ret)
    {
        LPERROR("Failed to register the interrupt handler.\n");
        goto err1;
    }

    ipi[prproc->mbx_chn_id].registered++;

    /* Get the resource table device */
    if (init_memory_device(rproc, &prproc->vr_info->rsc))
    {
        goto err1;
    }

    /* Get VRING related devices */
    if (init_memory_device(rproc, &prproc->vr_info->ctl))
    {
        goto err1;
    }

    if (init_memory_device(rproc, &prproc->vr_info->shm))
    {
        goto err1;
    }

    return rproc;
err1:
    metal_device_close(ipi[prproc->mbx_chn_id].dev);

    return NULL;
}

static void rzg3_proc_remove (struct remoteproc * rproc)
{
	struct remoteproc_priv		* prproc = rproc->priv;

    if (!rproc)
    {
        return;
    }

    if (ipi[prproc->mbx_chn_id].registered > 1)
    {
        ipi[prproc->mbx_chn_id].registered--;

        return;
    }

    /* Disable interrupts */
    rzg3_disable_interrupt(rproc);
}

static int rzg3_proc_notify (struct remoteproc * rproc, uint32_t id)
{
    struct remoteproc_priv * prproc = rproc->priv;
    unsigned int val = 0U;

#ifdef __linux__

    /* Put a message saying "This is the notify_id of mine!" */
    metal_io_write32_with_check(ipi.io, MBX_MSG_REG(MBX_NO), (uint64_t) prproc->notify_id);

    /* Send notification */
    metal_io_write32_with_check(ipi.io, MBX_CTRL_LOCAL_REG(MBX_NO), 0x1U);
#else
    ipi[prproc->mbx_chn_id].mbx_chn.mhu->p_api->msgSend(ipi[prproc->mbx_chn_id].mbx_chn.mhu->p_ctrl, prproc->notify_id);
#endif

    return 0;
}

#ifdef __linux__
static void * rzg3_proc_mmap (struct remoteproc       * rproc,
                              metal_phys_addr_t       * pa,
                              metal_phys_addr_t       * da,
                              size_t                    size,
                              unsigned int              attribute,
                              struct metal_io_region ** io)
{
    metal_phys_addr_t        lpa, lda;
    struct metal_io_region * tmpio;
    struct remoteproc_priv * prproc;
    (void) attribute;
    (void) size;

    if (!rproc)
    {
        return NULL;
    }

    prproc = rproc->priv;

    lpa = *pa;
    lda = *da;

    if ((lpa == METAL_BAD_PHYS) && (lda == METAL_BAD_PHYS))
    {
        return NULL;
    }

    if (lpa == METAL_BAD_PHYS)
    {
        lpa = lda;
    }

    if (lda == METAL_BAD_PHYS)
    {
        lda = lpa;
    }

    tmpio = prproc->vr_info->rsc.io;   /* We consider the resource table device only */
    if (!tmpio)
    {
        return NULL;
    }

    *pa = lpa;
    *da = lda;
    if (io)
    {
        *io = tmpio;
    }

    return metal_io_phys_to_virt(tmpio, lpa);
}

#endif

/* processor operations in rzg2. It defines
 * notification operation and remote processor managementi operations. */
struct remoteproc_ops rzg3_proc_ops =
{
    .init   = rzg3_proc_init,
    .remove = rzg3_proc_remove,
#ifdef __linux__
    .mmap     = rzg3_proc_mmap,
#else
    .mmap     = NULL,
#endif
    .notify   = rzg3_proc_notify,
    .start    = NULL,
    .stop     = NULL,
    .shutdown = NULL,
};
