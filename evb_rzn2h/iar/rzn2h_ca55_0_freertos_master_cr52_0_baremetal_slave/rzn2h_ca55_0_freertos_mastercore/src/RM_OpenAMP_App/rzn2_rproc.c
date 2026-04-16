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
 *       rzn2_rproc.c
 *
 * DESCRIPTION
 *
 *       This file defines RZ/N2 remoteproc implementation.
 *
 * @par     History
 *          - rev 1.0 (2024.05.31)
 *            Initial version for RZ/N2.
 *
 **************************************************************************/

#include <metal/atomic.h>
#include <metal/assert.h>
#include <metal/device.h>
#include <metal/irq.h>
#include <metal/list.h>
#include <metal/utilities.h>
#include <openamp/rpmsg_virtio.h>
#include <RM_OpenAMP_App/platform_info.h>
#include "hal_data.h"
#include <RM_OpenAMP_App/rm_openamp_app.h>

extern struct ipi_info ipi;

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

void rzn2_callback (icu_inter_cpu_irq_callback_args_t * p_args)
{
    unsigned int val = 0U;

    /* Get a massage from the mailbox */
    val = *((uint32_t *) (SHM_DEV_BASE + SHM_RX_OFFSET(MBX_RX_CH)));
    if (val >= RSC_MAX_NUM)            /* val should have the notify_id of the sender */
    {
        LPERROR("Invalid message from mail box");
    }

    ipi.notify_id = val;
    atomic_flag_clear(&ipi.sync);

    /* Initialize OpenAMP polling */
    if (openamp_open == 1)
    {
        RM_OpenAMP_Polling();
    }
}

static int rzn2_enable_interrupt (struct remoteproc * rproc, struct metal_device * ipi_dev)
{
    unsigned int irq_vect;
    int          ret = 0;

    if (!ipi.registered)
    {
        /* Register interrupt handler and enable interrupt for RZ/N2 */
        irq_vect = (uintptr_t) ipi_dev->irq_info;
        ret      = metal_irq_register((int) irq_vect, 0, ipi_dev, rproc);
        if (ret)
        {
            LPRINTF("metal_irq_register() failed with %d", ret);

            return ret;
        }

        metal_irq_enable(irq_vect);
    }

    return ret;
}

static void rzn2_disable_interrupt (struct remoteproc * rproc)
{
    (void) rproc;
    struct metal_device * dev;
    int ret;

    dev = ipi.dev;
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
        ipi.registered = 0;
    }
}

static struct remoteproc * rzn2_proc_init (struct remoteproc * rproc, struct remoteproc_ops * ops, void * arg)
{
    struct remoteproc_priv * prproc = arg;
    struct metal_device    * dev;
    int ret;

    /* Initialize ICU driver */
    g_icu_inter_cpu_irq0.p_api->open(g_icu_inter_cpu_irq0.p_ctrl, g_icu_inter_cpu_irq0.p_cfg);
    g_icu_inter_cpu_irq1.p_api->open(g_icu_inter_cpu_irq1.p_ctrl, g_icu_inter_cpu_irq1.p_cfg);

    if ((!rproc) || (!prproc) || (!ops))
    {
        return NULL;
    }

    rproc->priv = prproc;
    rproc->ops  = ops;

    if (!ipi.registered)
    {
        /* Get an IPI device (Mailbox) */
        ret = metal_device_open(ipi.bus_name, ipi.name, &dev);
        if (ret)
        {
            LPERROR("Failed to open ipi device: %d.\n", ret);

            return NULL;
        }

        ipi.dev = dev;
        ipi.io  = metal_device_io_region(dev, 0x0U);
        if (!ipi.io)
        {
            goto err1;
        }

        LPRINTF("Successfully probed IPI device\n");
    }

    ret = rzn2_enable_interrupt(rproc, ipi.dev);

    if (ret)
    {
        LPERROR("Failed to register the interrupt handler.\n");
        goto err1;
    }

    ipi.registered++;

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
    metal_device_close(ipi.dev);

    return NULL;
}

static void rzn2_proc_remove (struct remoteproc * rproc)
{
    if (!rproc)
    {
        return;
    }

    if (ipi.registered > 1)
    {
        ipi.registered--;

        return;
    }

    /* Disable interrupts */
    rzn2_disable_interrupt(rproc);
}

static int rzn2_proc_notify (struct remoteproc * rproc, uint32_t id)
{
    struct remoteproc_priv * prproc = rproc->priv;

    *((uint32_t *) (SHM_DEV_BASE + SHM_TX_OFFSET(MBX_TX_CH))) = prproc->notify_id;
    g_icu_inter_cpu_irq0.p_api->generate(g_icu_inter_cpu_irq0.p_ctrl);

    return 0;
}

/* processor operations in rzn2. It defines
 * notification operation and remote processor management operations. */
struct remoteproc_ops rzn2_proc_ops =
{
    .init     = rzn2_proc_init,
    .remove   = rzn2_proc_remove,
    .mmap     = NULL,
    .start    = NULL,
    .stop     = NULL,
    .shutdown = NULL,
    .notify   = rzn2_proc_notify,
};
