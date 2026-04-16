#include "new_thread0.h"
#include "RM_OpenAMP_App/rm_openamp_app.h"
#include "RM_OpenAMP_App/platform_info.h"
#include "RM_OpenAMP_App/rsc_table.h"
#include "openamp/open_amp.h"
#include "openamp/virtio.h"
#include "string.h"

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static void verify_led_from_master(void);

const TickType_t xDelay = 100 / portTICK_PERIOD_MS;

/* New Thread entry function */
/* pvParameters contains TaskHandle_t */
void new_thread0_entry (void * pvParameters)
{
    FSP_PARAMETER_NOT_USED(pvParameters);

    /* Open OpenAMP */
    (void) RM_OpenAMP_Open(VIRTIO_DEV_SLAVE, 0, 0);

    while (1)
    {
        if (stateOpenAMP_led == OPENAMP_STATE_CALLBACK_LED)
        {
            verify_led_from_master();
            vTaskDelay(xDelay);
        }
        else
        {
            /* Do nothing */
        }
    }
}

/**
 * This function is to confirm the led returned from the master.
 *
 * @param[in] This function has no input parameters.
 * @return No return value.
 */
static void verify_led_from_master (void)
{
    uint32_t             led_master;
    uint32_t             led_slave;
    rm_openamp_options_t option_master = OPENAMP_OP_LED;

    RM_OpenAMP_Read(&option_master, &led_master);

    if (led_master == 1)
    {
        R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_23_PIN_1, BSP_IO_LEVEL_HIGH);
        led_slave = 1;
    }
    else if (led_master == 0)
    {
        R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_23_PIN_1, BSP_IO_LEVEL_LOW);
        led_slave = 0;
    }
    else
    {
        /* Nothing to do */
    }

    (void) RM_OpenAMP_Write(&option_master, &led_slave);
}
