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
#include "MainTask.h"
/* MainTask#0 entry function */
/* pvParameters contains TaskHandle_t */
#include "openamp/open_amp.h"
#include "platform_info.h"
#include "rsc_table.h"

#define RECONNECT_FLG    (1)           /* 1:reconnect after exit, 0:disconnect after exit */
#define RECONNECT_DLY    (1u)

extern void rpmsg_service_bind(struct rpmsg_device *rdev, const char *name, uint32_t dest);
extern int app (struct rpmsg_device * rdev, void * platform, unsigned long svcno);
void CA55_rpmsg_task(void *arg);

TaskHandle_t CA55_task_id;
#if BSP_CURRENT_CORE == RZG3S_CORE_CM33
TaskHandle_t CM33_FPU_task_id;
#else
TaskHandle_t CM33_task_id;
#endif
TaskHandle_t *task_id;

typedef enum e_role_type
{
    MASTER = VIRTIO_DEV_MASTER,
    SLAVE = VIRTIO_DEV_SLAVE,
} role_type_t;

struct rpmsg_task_arg{
    role_type_t role;
    rpmsg_target_t target;
    unsigned long rsc_id;
};

void rpmsg_task(void *arg)
{
    struct rpmsg_device * rpdev;
    void                * platform;
    struct rpmsg_task_arg * rpmsg_arg = arg;
    unsigned long         proc_id = rpmsg_arg->rsc_id;
    unsigned long         rsc_id  = rpmsg_arg->rsc_id;

    int ret;

    ret = platform_init(proc_id, rsc_id, rpmsg_arg->target, &platform);
    if (ret)
    {
        LPERROR("Failed to create remoteproc device.\n");
    }
    else
    {

        do
       {
            /* RTOS is Master, but this setting must remote in this release. */
            if(rpmsg_arg->role == VIRTIO_DEV_SLAVE){
                rpdev = platform_create_rpmsg_vdev(platform, 0x0U, VIRTIO_DEV_SLAVE, NULL, NULL);
            }
            else{
                rpdev = platform_create_rpmsg_vdev(platform, 0x0U, VIRTIO_DEV_MASTER, NULL, rpmsg_service_bind);
            }

            if (!rpdev)
            {
                LPERROR("Fail, platform_create_rpmsg_vdev.\n");
                metal_log(METAL_LOG_INFO, "Fail, platform_create_rpmsg_vdev.");
                break;
            }

            /* Kick the application */
            (void) app(rpdev, platform, proc_id);

            LPRINTF("De-initializating remoteproc\n");
            platform_release_rpmsg_vdev(platform, rpdev);

            vTaskDelay(1);
       } while (RECONNECT_FLG);

        platform_cleanup(platform);
    }

    vTaskDelete(NULL);
}

void MainTask_entry(void *pvParameters)
{
    int ret;
    BaseType_t xReturned;
    struct rpmsg_task_arg CA55_arg;
    struct rpmsg_task_arg arg;
#if BSP_CURRENT_CORE == RZG3S_CORE_CM33
    char *task_name = "CM33_FPU rpmsg task";
#else
    char *task_name = "CM33 rpmsg task";
#endif

    ret = init_system();
    if (ret)
    {
        LPERROR("Failed to init remoteproc device.\n");
        goto err1;
    }

#ifdef TO_CA55
    CA55_arg.role = MASTER;
    CA55_arg.target = CA55_SLAVE;
    task_id = &CA55_task_id;
    CA55_arg.rsc_id = 1;

    xReturned =
            xTaskCreate(rpmsg_task,
                        "CA55 rpmsg task",
                        0x200U,
                        &CA55_arg,
                        (tskIDLE_PRIORITY + 4),
                        &CA55_task_id);
#endif

#if BSP_CURRENT_CORE == RZG3S_CORE_CM33
    arg.role = SLAVE;
    arg.target = CM33_MASTER;
    task_id = &CM33_task_id;
#else
 #if (CM33_IS_SLAVE == 0)
    arg.role = SLAVE;
    arg.target = CM33_MASTER;
 #else
    arg.role = MASTER;
    arg.target = CM33_SLAVE;
 #endif
    task_id = &CM33_task_id;
#endif
    arg.rsc_id = 1;
    xReturned =
            xTaskCreate(rpmsg_task,
                        task_name,
                        0x200U,
                        &arg,
                        (tskIDLE_PRIORITY + 4),
                        task_id);

err1:
    vTaskDelete(NULL);
}

