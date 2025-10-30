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
/**
 * @file    sample_rpmsg.c
 * @brief   rpmsg sample program for FreeRTOS
 * @date    2020.03.24
 * @author  Copyright (c) 2020, eForce Co., Ltd. All rights reserved.
 *
 ****************************************************************************
 * @par     History
 *          - rev 1.0 (2020.01.28) Imada
 *            Initial version.
 *          - rev 1.1 (2020.03.24) Imada
 *            Employed a dedicated function to set a string for Shared memory API.
 ****************************************************************************
 */
#include "FreeRTOS.h"
#include "openamp/open_amp.h"
#include "platform_info.h"
#include "rsc_table.h"

/* Payload definition */
struct _payload {
    unsigned long num;
    unsigned long size;
    unsigned char data[];
};

/* Payload information */
struct payload_info {
    int min;
    int max;
    int num;
};

/* Globals */
static struct rpmsg_endpoint rp_ept[CFG_RPMSG_SVCNO] = {0};
static struct _payload *i_payload;
static int rnum = 0;
static int err_cnt = 0;
static char *svc_name = NULL;

/* External functions */
extern int  init_system(void);
extern void cleanup_system(void);

#define SHUTDOWN_MSG     (0xEF56A55A)

/* Local variables */

/*-----------------------------------------------------------------------------*
 *  RPMSG callbacks setup by remoteproc_resource_init()
 *-----------------------------------------------------------------------------*/

/* Local variables */
volatile static int evt_svc_unbind[CFG_RPMSG_SVCNO] = {0};

/**
 *  Callback Function: rpmsg_endpoint_cb
 *
 *  @param[in] rp_svc
 *  @param[in] data
 *  @param[in] len
 *  @param[in] priv
 *  @param[in] src
 */
static int rpmsg_endpoint_cb0 (struct rpmsg_endpoint * cb_rp_ept, void * data, size_t len, uint32_t src, void * priv)
{
    /*  This function will not be used in this example */
    return 0;
}

static int rpmsg_endpoint_cb1 (struct rpmsg_endpoint * cb_rp_ept, void * data, size_t len, uint32_t src, void * priv)
{
#if (CM33_IS_SLAVE == 0)
    /* service 1 */
    (void)cb_rp_ept;
    (void)src;
    (void)priv;
    int i;
    int ret = 0;
    struct _payload *r_payload = (struct _payload *)data;

    LPRINTF(" received payload number %lu of size %lu \r\n",
    r_payload->num, len);

    if (r_payload->size == 0) {
        LPERROR(" Invalid size of package is received.\n");
        err_cnt++;
        return -1;
    }
    /* Validate data buffer integrity. */
    for (i = 0; i < (int)r_payload->size; i++) {
        if (r_payload->data[i] != 0xA5) {
            LPRINTF("Data corruption at index %d\n", i);
            err_cnt++;
            ret = -1;
            break;
        }
    }
    rnum = r_payload->num + 1;
    return ret;
#else
    /* service 1 */
    (void) priv;
    (void) src;

    /* On reception of a shutdown we signal the application to terminate */
    if ((*(unsigned int *) data) == SHUTDOWN_MSG)
    {
        evt_svc_unbind[1] = 1;
        return RPMSG_SUCCESS;
    }

    /* Send data back to master */
    if (rpmsg_send(cb_rp_ept, data, (int) len) < 0)
    {
        LPERROR("rpmsg_send failed\n");
        return -1;
    }

    return RPMSG_SUCCESS;
#endif
}

/**
 *  Callback Function: rpmsg_service_unbind
 *
 *  @param[in] ept
 */
static void rpmsg_service_unbind0 (struct rpmsg_endpoint * ept)
{
    (void) ept;

    /* service 0 */
    rpmsg_destroy_ept(&rp_ept[0]);
    memset(&rp_ept[0], 0x0, sizeof(struct rpmsg_endpoint));
    evt_svc_unbind[0] = 1;
}

static void rpmsg_service_unbind1 (struct rpmsg_endpoint * ept)
{
    (void) ept;

    /* service 1 */
    rpmsg_destroy_ept(&rp_ept[1]);
    memset(&rp_ept[1], 0x0, sizeof(struct rpmsg_endpoint));
    evt_svc_unbind[1] = 1;
}

void rpmsg_service_bind(struct rpmsg_device *rdev, const char *name, uint32_t dest)
{
    LPRINTF("new endpoint notification is received.\n");
    if (strcmp(name, svc_name)) {
        LPERROR("Unexpected name service %s.\n", name);
    }
    else
        (void)rpmsg_create_ept(&rp_ept[1], rdev, svc_name,
                       APP_EPT_ADDR, dest,
                       rpmsg_endpoint_cb1,
                       rpmsg_service_unbind1);
    return ;
}

static int payload_init(struct rpmsg_device *rdev, struct payload_info *pi) {
    int rpmsg_buf_size = 0;

    /* Get the maximum buffer size of a rpmsg packet */
    if ((rpmsg_buf_size = rpmsg_virtio_get_buffer_size(rdev)) <= 0) {
        return rpmsg_buf_size;
    }

    pi->min = 1;
    pi->max = rpmsg_buf_size - 24;
    pi->num = pi->max / pi->min;

    i_payload =
        (struct _payload *)metal_allocate_memory(2 * sizeof(unsigned long) +
                      pi->max);
    if (!i_payload) {
        LPERROR("memory allocation failed.\n");
        return -ENOMEM;
    }

    return 0;
}

/*-----------------------------------------------------------------------------*
 *  Application
 *-----------------------------------------------------------------------------*/
int app (struct rpmsg_device * rdev, void * platform, unsigned long svcno)
{
    int ret;
    int shutdown_msg = SHUTDOWN_MSG;
    int i;
    int size;
    int expect_rnum = 0;
    struct payload_info pi = {0};

#if (CM33_IS_SLAVE == 0)
/* master is needed, slave isn't needed */
    if (svcno == 1UL)
    {
      LPRINTF(" 1 - Send data to remote core, retrieve the echo");
      LPRINTF(" and validate its integrity ..\n");

        /* Initialization of the payload and its related information */
        if ((ret = payload_init(rdev, &pi))) {
            return ret;
        }
    }
#endif

    if (svcno == 0UL)
    {
    	svc_name = CFG_RPMSG_SVC_NAME0;
        ret = rpmsg_create_ept(&rp_ept[0],
                               rdev,
                               svc_name,
                               APP_EPT_ADDR,
                               RPMSG_ADDR_ANY,
                               rpmsg_endpoint_cb0,
                               rpmsg_service_unbind0);
        if (ret)
        {
            LPERROR("Failed to create endpoint.\n");

            return -1;
        }
    }
    else
    {
    	svc_name = CFG_RPMSG_SVC_NAME1;
        ret = rpmsg_create_ept(&rp_ept[1],
                               rdev,
                               svc_name,
                               APP_EPT_ADDR,
                               RPMSG_ADDR_ANY,
                               rpmsg_endpoint_cb1,
                               rpmsg_service_unbind1);
        if (ret)
        {
            LPERROR("Failed to create endpoint.\n");

            return -1;
        }
    }

#if (CM33_IS_SLAVE == 0)
    if (svcno == 0UL)
#else
    if (svcno != 0UL)
#endif
    {
        LPRINTF("Waiting for events...\n");
        while (1)
        {
            vTaskDelay(1);

            /* we got a shutdown request, exit */
            if (evt_svc_unbind[svcno])
            {
                break;
            }
        }

        /* Clear shutdown flag */
        evt_svc_unbind[svcno] = 0;
    }
    else
    {
        while (!is_rpmsg_ept_ready(&rp_ept[1]))
             platform_poll(platform);

        LPRINTF("RPMSG service has created.\n");
        for (i = 0, size = pi.min; i < (int)pi.num; i++, size++) {
            i_payload->num = i;
            i_payload->size = size;

            /* Mark the data buffer. */
            memset(&(i_payload->data[0]), 0xA5, size);

            LPRINTF("sending payload number %lu of size %lu\n",
                 i_payload->num, (2 * sizeof(unsigned long)) + size);

            ret = rpmsg_send(&rp_ept[1], i_payload,
                 (2 * sizeof(unsigned long)) + size);

            if (ret < 0) {
                LPRINTF("Error sending data...%d\n", ret);
            break;
            }
            LPRINTF("echo test: sent : %lu\n", (2 * sizeof(unsigned long)) + size);

            expect_rnum++;
            do {
                platform_poll(platform);
            } while ((rnum < expect_rnum) && !err_cnt);
            vTaskDelay(1);
        }

        LPRINTF("************************************\n");
        LPRINTF(" Test Results: Error count = %d \n", err_cnt);
        LPRINTF("************************************\n");
        /* Send shutdown message to remote */
        rpmsg_send(&rp_ept[1], &shutdown_msg, sizeof(int));
        vTaskDelay(1);
        LPRINTF("Quitting application .. Echo test end\n");

        metal_free_memory(i_payload);
    }
    return 0;
}
