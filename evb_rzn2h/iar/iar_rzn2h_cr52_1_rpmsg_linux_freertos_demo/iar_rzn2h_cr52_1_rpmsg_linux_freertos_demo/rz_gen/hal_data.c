/* generated HAL source file - do not edit */
#include "hal_data.h"
icu_inter_cpu_irq_instance_ctrl_t g_icu_inter_cpu_irq11_ctrl;

const icu_inter_cpu_irq_cfg_t g_icu_inter_cpu_irq11_cfg =
{
    .channel             = 11,
    .p_callback          = sw_reset_callback,
    .p_context           = NULL,
    .p_extend            = NULL,
    .ipl                 = (30),
#if defined(VECTOR_NUMBER_INTCPU11)
    .irq                 = VECTOR_NUMBER_INTCPU11,
#else
    .irq                 = FSP_INVALID_VECTOR,
#endif
};
/* Instance structure to use this module. */
const icu_inter_cpu_irq_instance_t g_icu_inter_cpu_irq11 =
{
    .p_ctrl        = &g_icu_inter_cpu_irq11_ctrl,
    .p_cfg         = &g_icu_inter_cpu_irq11_cfg,
    .p_api         = &g_icu_inter_cpu_irq_on_icu
};
sci_uart_instance_ctrl_t     g_uart0_ctrl;

            #define FSP_NOT_DEFINED (1)
            #if (FSP_NOT_DEFINED) != (FSP_NOT_DEFINED)

            /* If the transfer module is DMAC, define a DMAC transfer callback. */
            extern void sci_uart_tx_dmac_callback(sci_uart_instance_ctrl_t * p_instance_ctrl);

            void g_uart0_tx_transfer_callback (transfer_callback_args_t * p_args)
            {
                FSP_PARAMETER_NOT_USED(p_args);
                sci_uart_tx_dmac_callback(&g_uart0_ctrl);
            }
            #endif

            #if (FSP_NOT_DEFINED) != (FSP_NOT_DEFINED)

            /* If the transfer module is DMAC, define a DMAC transfer callback. */
            extern void sci_uart_rx_dmac_callback(sci_uart_instance_ctrl_t * p_instance_ctrl);

            void g_uart0_rx_transfer_callback (transfer_callback_args_t * p_args)
            {
                FSP_PARAMETER_NOT_USED(p_args);
                sci_uart_rx_dmac_callback(&g_uart0_ctrl);
            }
            #endif
            #undef FSP_NOT_DEFINED

            sci_baud_setting_t           g_uart0_baud_setting =
            {
                /* Baud rate calculated with 1.219% error. */ .baudrate_bits_b.abcse = 0, .baudrate_bits_b.abcs = 0, .baudrate_bits_b.bgdm = 1, .baudrate_bits_b.cks = 0, .baudrate_bits_b.brr = 66, .baudrate_bits_b.mddr = (uint8_t) 256, .baudrate_bits_b.brme = false
            };

            /** UART extended configuration for UARTonSCI HAL driver */
            const sci_uart_extended_cfg_t g_uart0_cfg_extend =
            {
                .clock                = SCI_UART_CLOCK_INT,
                .rx_edge_start          = SCI_UART_START_BIT_FALLING_EDGE,
                .noise_cancel         = SCI_UART_NOISE_CANCELLATION_DISABLE,
                .rx_fifo_trigger        = SCI_UART_RX_FIFO_TRIGGER_MAX,
                .p_baud_setting         = &g_uart0_baud_setting,
#if 0
                .clock_source           = SCI_UART_CLOCK_SOURCE_SCI1ASYNCCLK,
#else
                .clock_source           = SCI_UART_CLOCK_SOURCE_PCLKM,
#endif
                .flow_control           = SCI_UART_FLOW_CONTROL_RTS,
                .flow_control_pin       = (bsp_io_port_pin_t) UINT16_MAX,
                .rs485_setting          = {
                    .enable = SCI_UART_RS485_DISABLE,
                    .polarity = SCI_UART_RS485_DE_POLARITY_HIGH,
                    .assertion_time = 1,
                    .negation_time = 1,
                },
            };

            /** UART interface configuration */
            const uart_cfg_t g_uart0_cfg =
            {
                .channel             = 1,
                .data_bits           = UART_DATA_BITS_8,
                .parity              = UART_PARITY_OFF,
                .stop_bits           = UART_STOP_BITS_1,
                .p_callback          = uart_callback,
                .p_context           = NULL,
                .p_extend            = &g_uart0_cfg_extend,
                .p_transfer_tx       = g_uart0_P_TRANSFER_TX,
                .p_transfer_rx       = g_uart0_P_TRANSFER_RX,
                .rxi_ipl             = (12),
                .txi_ipl             = (12),
                .tei_ipl             = (12),
                .eri_ipl             = (12),
#if defined(VECTOR_NUMBER_SCI1_RXI)
                .rxi_irq             = VECTOR_NUMBER_SCI1_RXI,
#else
                .rxi_irq             = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI1_TXI)
                .txi_irq             = VECTOR_NUMBER_SCI1_TXI,
#else
                .txi_irq             = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI1_TEI)
                .tei_irq             = VECTOR_NUMBER_SCI1_TEI,
#else
                .tei_irq             = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI1_ERI)
                .eri_irq             = VECTOR_NUMBER_SCI1_ERI,
#else
                .eri_irq             = FSP_INVALID_VECTOR,
#endif
            };

/* Instance structure to use this module. */
const uart_instance_t g_uart0 =
{
    .p_ctrl        = &g_uart0_ctrl,
    .p_cfg         = &g_uart0_cfg,
    .p_api         = &g_uart_on_sci
};
icu_inter_cpu_irq_instance_ctrl_t g_icu_inter_cpu_irq1_ctrl;

const icu_inter_cpu_irq_cfg_t g_icu_inter_cpu_irq1_cfg =
{
    .channel             = 1,
    .p_callback          = NULL,
    .p_context           = NULL,
    .p_extend            = NULL,
    .ipl                 = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_INTCPU1)
    .irq                 = VECTOR_NUMBER_INTCPU1,
#else
    .irq                 = FSP_INVALID_VECTOR,
#endif
};
/* Instance structure to use this module. */
const icu_inter_cpu_irq_instance_t g_icu_inter_cpu_irq1 =
{
    .p_ctrl        = &g_icu_inter_cpu_irq1_ctrl,
    .p_cfg         = &g_icu_inter_cpu_irq1_cfg,
    .p_api         = &g_icu_inter_cpu_irq_on_icu
};
icu_inter_cpu_irq_instance_ctrl_t g_icu_inter_cpu_irq0_ctrl;

const icu_inter_cpu_irq_cfg_t g_icu_inter_cpu_irq0_cfg =
{
    .channel             = 0,
    .p_callback          = rzn2_callback,
    .p_context           = NULL,
    .p_extend            = NULL,
    .ipl                 = (30),
#if defined(VECTOR_NUMBER_INTCPU0)
    .irq                 = VECTOR_NUMBER_INTCPU0,
#else
    .irq                 = FSP_INVALID_VECTOR,
#endif
};
/* Instance structure to use this module. */
const icu_inter_cpu_irq_instance_t g_icu_inter_cpu_irq0 =
{
    .p_ctrl        = &g_icu_inter_cpu_irq0_ctrl,
    .p_cfg         = &g_icu_inter_cpu_irq0_cfg,
    .p_api         = &g_icu_inter_cpu_irq_on_icu
};
void g_hal_init(void) {
g_common_init();
}
