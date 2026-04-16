#include "new_thread0.h"
#include "hal_data.h"
#include "RM_OpenAMP_App/platform_info.h"
#include "RM_OpenAMP_App/rsc_table.h"
#include "openamp/virtio.h"
#include "openamp/open_amp.h"

#define RECONNECT_FLG    (1)           /* 1:reconnect after exit, 0:disconnect after exit */
#define RECONNECT_DLY    (10000u)

extern int  init_system(void);
extern int  app(struct rpmsg_device * rdev, void * platform, unsigned long svcno);
extern void cleanup_system(void);

/* New Thread entry function */
/* pvParameters contains TaskHandle_t */
void new_thread0_entry (void * pvParameters)
{
    FSP_PARAMETER_NOT_USED(pvParameters);

    R_IOPORT_PinCfg(&g_ioport_ctrl,
                    BSP_IO_PORT_16_PIN_3,
                    ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                     (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                     (uint32_t) IOPORT_PIN_P163_PFC_14_RXD5_SCL5_MISO5));
    R_IOPORT_PinCfg(&g_ioport_ctrl,
                    BSP_IO_PORT_16_PIN_4,
                    ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                     (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                     (uint32_t) IOPORT_PIN_P164_PFC_14_TXD5_SDA5_MOSI5));

    unsigned long         proc_id = 0;
    unsigned long         rsc_id  = 0;
    struct rpmsg_device * rpdev;
    void                * platform;
    int ret;

    LPRINTF("****************  CA55_3 FreeRTOS  ******************\n", 0);
    LPRINTF("*****************************************************\n");
    ret = init_system();

    if (ret)
    {
        LPERROR("Failed to init remoteproc device.\n");
        goto err1;
    }

    ret = platform_init(proc_id, rsc_id, &platform);

    if (ret)
    {
        LPERROR("Failed to create remoteproc device.\n");
        goto err1;
    }
    else
    {
        do
        {
            /* RTOS is Master, but this setting must remote in this release. */
            rpdev = platform_create_rpmsg_vdev(platform, 0x0U, VIRTIO_DEV_SLAVE, NULL, NULL);

            if (!rpdev)
            {
                LPERROR("Fail, platform_create_rpmsg_vdev.\n");
                metal_log(METAL_LOG_INFO, "Fail, platform_create_rpmsg_vdev.");
                goto err2;
            }

            g_icu_inter_cpu_irq0.p_api->generate(g_icu_inter_cpu_irq0.p_ctrl);

            /* Kick the application */
            (void) app(rpdev, platform, proc_id);

            LPRINTF("De-initializating remoteproc\n");
            platform_release_rpmsg_vdev(platform, rpdev);

            vTaskDelay(RECONNECT_FLG);
        } while (RECONNECT_FLG);
    }

    platform_cleanup(platform);
    cleanup_system();

    /* Closes the icu_inter_cpu_irq */
    g_icu_inter_cpu_irq0.p_api->close(g_icu_inter_cpu_irq0.p_ctrl);
    g_icu_inter_cpu_irq1.p_api->close(g_icu_inter_cpu_irq1.p_ctrl);
err2:
    platform_cleanup(platform);
err1:
    while (1)
    {
        ;
    }
}
