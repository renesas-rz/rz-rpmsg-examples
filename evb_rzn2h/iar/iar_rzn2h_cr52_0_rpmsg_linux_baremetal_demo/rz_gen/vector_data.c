        /* RZN: generated vector source file - do not edit */
        #include "bsp_api.h"
        /* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
        #if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES] =
        {
            [0] = r_icu_inter_cpu_irq_isr, /* INTCPU0 (Software interrupt 0) */
            [10] = r_icu_inter_cpu_irq_isr, /* INTCPU10 (Software interrupt 10) */
            [384] = sci_uart_rxi_isr, /* SCI1_RXI (SCI1 Receive data full) */
            [385] = sci_uart_txi_isr, /* SCI1_TXI (SCI1 Transmit data empty) */
            [386] = sci_uart_tei_isr, /* SCI1_TEI (SCI1 Transmit end) */
            [387] = sci_uart_eri_isr, /* SCI1_ERI (SCI1 Receive error) */
        };
        #if (1 == BSP_FEATURE_BSP_IRQ_CR52_SEL_SUPPORTED)
        /* If the product has an Interrupts Select Register and the selected interrupt is assigned to
         * the Interrupts Select Register, different from the number specified by Event number,
         * the numbers within the range assigned to the Interrupts Select Register will be assigned in order.
         * Products that do not have an Interrupts Select Register and interrupts that cannot be assigned to
         * the Interrupts Select Register are assigned the number specified by Event number. */
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] =
        {
            [0] = BSP_PRV_CR52_SEL_ENUM(EVENT_INTCPU0), /* INTCPU0 (Software interrupt 0) */
            [10] = BSP_PRV_CR52_SEL_ENUM(EVENT_INTCPU10), /* INTCPU10 (Software interrupt 10) */
            [384] = BSP_PRV_CR52_SEL_ENUM(EVENT_SCI1_RXI), /* SCI1_RXI (SCI1 Receive data full) */
            [385] = BSP_PRV_CR52_SEL_ENUM(EVENT_SCI1_TXI), /* SCI1_TXI (SCI1 Transmit data empty) */
            [386] = BSP_PRV_CR52_SEL_ENUM(EVENT_SCI1_TEI), /* SCI1_TEI (SCI1 Transmit end) */
            [387] = BSP_PRV_CR52_SEL_ENUM(EVENT_SCI1_ERI), /* SCI1_ERI (SCI1 Receive error) */
        };
        #endif
        #endif
