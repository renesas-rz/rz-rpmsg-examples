#include "new_thread0.h"
#include "RM_OpenAMP_App/rm_openamp_app.h"
#include "RM_OpenAMP_App/platform_info.h"
#include "RM_OpenAMP_App/rsc_table.h"
#include "openamp/open_amp.h"
#include "openamp/virtio.h"
#include "string.h"

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/
static rm_openamp_options_t option;
char led_on[8]  = "43210C01";
char led_off[8] = "43210C00";
char rx_data[8];

extern uart_event_t g_uart_callback_event;
const TickType_t    xDelay = 350 / portTICK_PERIOD_MS;

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
uint8_t string_cmp(char * data0, char * data1, uint8_t len);

/* New Thread entry function */
/* pvParameters contains TaskHandle_t */
void new_thread0_entry (void * pvParameters)
{
    FSP_PARAMETER_NOT_USED(pvParameters);

    static uint32_t pre_led  = 0;
    uint32_t        ledstate = 0;
    uint32_t        led_send = 0;

    /* Open OpenAMP */
    (void) RM_OpenAMP_Open(VIRTIO_DEV_MASTER, 0, 0);

    /* Initialize the buffer data of UART */
    R_SCI_UART_Read(&g_uart0_ctrl, (uint8_t *) rx_data, 8);

    while (1)
    {
        if (stateOpenAMP_led == OPENAMP_STATE_CALLBACK_LED)
        {
            option = OPENAMP_OP_LED;
            RM_OpenAMP_Read(&option, &led_send);

            if (led_send != pre_led)
            {
                pre_led = led_send;
                if (led_send == 0)
                {
                    LPRINTF("SLave turned off LED\n");
                }
                else if (led_send == 1)
                {
                    LPRINTF("Slave turned on LED\n");
                }
            }
        }

        /* Check event uart RX completing */
        if (g_uart_callback_event == 1)
        {
            LPRINTF("Received data from UART\n");
            if (string_cmp(rx_data, led_on, 8) == 0)
            {
                ledstate = 1;
            }
            else if (string_cmp(rx_data, led_off, 8) == 0)
            {
                ledstate = 0;
            }
            else
            {
                /* Nothing to do */
            }

            /* Check previous led with led from slave */
            if (ledstate != led_send)
            {
                option = OPENAMP_OP_LED;
                RM_OpenAMP_Write(&option, &ledstate);
            }
            else
            {
                /* Nothing to do */
            }

            /* Re-initialize for new buffer data of UART */
            R_SCI_UART_Read(&g_uart0_ctrl, (uint8_t *) rx_data, 8);
            g_uart_callback_event = 0;
            vTaskDelay(xDelay);
        }
        else
        {
            /* Nothing to do */
        }
    }
}

/**
 * This function is to compare two strings with length.
 *
 * @param[in] string array data0.
 * @param[in] string array data1.
 * @param[in] length of string comparing.
 * @return return 0/1 (Equal/NotEqual).
 */
uint8_t string_cmp (char * data0, char * data1, uint8_t len)
{
    for (uint8_t index = 0; index < len; index++)
    {
        if (data0[index] != data1[index])
        {
            return 1;
        }
    }

    return 0;
}
