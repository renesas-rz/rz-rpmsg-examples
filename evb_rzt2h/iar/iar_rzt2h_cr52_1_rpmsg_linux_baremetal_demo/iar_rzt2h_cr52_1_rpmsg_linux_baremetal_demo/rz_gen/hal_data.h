/* generated HAL header file - do not edit */
#ifndef HAL_DATA_H_
#define HAL_DATA_H_
#include <stdint.h>
#include "bsp_api.h"
#include "common_data.h"
#include "r_icu_inter_cpu_irq.h"
#include "r_icu_inter_cpu_irq_api.h"
#include "r_sci_uart.h"
            #include "r_uart_api.h"
FSP_HEADER
/** External IRQ on ICU Instance. */
extern const icu_inter_cpu_irq_instance_t g_icu_inter_cpu_irq11;

/** Access the ICU instance using these structures when calling API functions directly (::p_api is not used). */
extern icu_inter_cpu_irq_instance_ctrl_t g_icu_inter_cpu_irq11_ctrl;
extern const icu_inter_cpu_irq_cfg_t g_icu_inter_cpu_irq11_cfg;

#ifndef sw_reset_callback
void sw_reset_callback(icu_inter_cpu_irq_callback_args_t * p_args);
#endif
/** UART on SCI Instance. */
            extern const uart_instance_t      g_uart0;

            /** Access the UART instance using these structures when calling API functions directly (::p_api is not used). */
            extern sci_uart_instance_ctrl_t     g_uart0_ctrl;
            extern const uart_cfg_t g_uart0_cfg;
            extern const sci_uart_extended_cfg_t g_uart0_cfg_extend;

            #ifndef uart_callback
            void uart_callback(uart_callback_args_t * p_args);
            #endif

            #define FSP_NOT_DEFINED (1)
            #if (FSP_NOT_DEFINED == FSP_NOT_DEFINED)
                #define g_uart0_P_TRANSFER_TX (NULL)
            #else
                #define g_uart0_P_TRANSFER_TX (&FSP_NOT_DEFINED)
            #endif
            #if (FSP_NOT_DEFINED == FSP_NOT_DEFINED)
                #define g_uart0_P_TRANSFER_RX (NULL)
            #else
                #define g_uart0_P_TRANSFER_RX (&FSP_NOT_DEFINED)
            #endif
            #undef FSP_NOT_DEFINED
/** External IRQ on ICU Instance. */
extern const icu_inter_cpu_irq_instance_t g_icu_inter_cpu_irq1;

/** Access the ICU instance using these structures when calling API functions directly (::p_api is not used). */
extern icu_inter_cpu_irq_instance_ctrl_t g_icu_inter_cpu_irq1_ctrl;
extern const icu_inter_cpu_irq_cfg_t g_icu_inter_cpu_irq1_cfg;

#ifndef NULL
void NULL(icu_inter_cpu_irq_callback_args_t * p_args);
#endif
/** External IRQ on ICU Instance. */
extern const icu_inter_cpu_irq_instance_t g_icu_inter_cpu_irq0;

/** Access the ICU instance using these structures when calling API functions directly (::p_api is not used). */
extern icu_inter_cpu_irq_instance_ctrl_t g_icu_inter_cpu_irq0_ctrl;
extern const icu_inter_cpu_irq_cfg_t g_icu_inter_cpu_irq0_cfg;

#ifndef rzt2_callback
void rzt2_callback(icu_inter_cpu_irq_callback_args_t * p_args);
#endif
void hal_entry(void);
void g_hal_init(void);
FSP_FOOTER
#endif /* HAL_DATA_H_ */
