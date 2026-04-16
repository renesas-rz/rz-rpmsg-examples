        /* RZN: generated vector header file - do not edit */
        #ifndef VECTOR_DATA_H
        #define VECTOR_DATA_H
        #include "bsp_api.h"

        /** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
        FSP_HEADER

        /* Number of interrupts allocated */
        #ifndef VECTOR_DATA_IRQ_COUNT
        #define VECTOR_DATA_IRQ_COUNT    (6)
        #endif
        /* ISR prototypes */
        void r_icu_inter_cpu_irq_isr(void);
        void sci_uart_rxi_isr(void);
        void sci_uart_txi_isr(void);
        void sci_uart_tei_isr(void);
        void sci_uart_eri_isr(void);

        /* Vector table allocations */
        #define VECTOR_NUMBER_INTCPU0 ((IRQn_Type) 0) /* INTCPU0 (Software interrupt 0) */
        #define VECTOR_NUMBER_INTCPU10 ((IRQn_Type) 10) /* INTCPU10 (Software interrupt 10) */
        #define VECTOR_NUMBER_SCI1_RXI ((IRQn_Type) 384) /* SCI1_RXI (SCI1 Receive data full) */
        #define VECTOR_NUMBER_SCI1_TXI ((IRQn_Type) 385) /* SCI1_TXI (SCI1 Transmit data empty) */
        #define VECTOR_NUMBER_SCI1_TEI ((IRQn_Type) 386) /* SCI1_TEI (SCI1 Transmit end) */
        #define VECTOR_NUMBER_SCI1_ERI ((IRQn_Type) 387) /* SCI1_ERI (SCI1 Receive error) */
        typedef enum IRQn {
            SoftwareGeneratedInt0 = -32,
            SoftwareGeneratedInt1 = -31,
            SoftwareGeneratedInt2 = -30,
            SoftwareGeneratedInt3 = -29,
            SoftwareGeneratedInt4 = -28,
            SoftwareGeneratedInt5 = -27,
            SoftwareGeneratedInt6 = -26,
            SoftwareGeneratedInt7 = -25,
            SoftwareGeneratedInt8 = -24,
            SoftwareGeneratedInt9 = -23,
            SoftwareGeneratedInt10 = -22,
            SoftwareGeneratedInt11 = -21,
            SoftwareGeneratedInt12 = -20,
            SoftwareGeneratedInt13 = -19,
            SoftwareGeneratedInt14 = -18,
            SoftwareGeneratedInt15 = -17,
            DebugCommunicationsChannelInt = -10,
            PerformanceMonitorCounterOverflowInt = -9,
            CrossTriggerInterfaceInt = -8,
            VritualCPUInterfaceMaintenanceInt = -7,
            HypervisorTimerInt = -6,
            VirtualTimerInt = -5,
            NonSecurePhysicalTimerInt = -2,
            INTCPU0_IRQn = 0, /* INTCPU0 (Software interrupt 0) */
            INTCPU10_IRQn = 10, /* INTCPU10 (Software interrupt 10) */
            SCI1_RXI_IRQn = 384, /* SCI1_RXI (SCI1 Receive data full) */
            SCI1_TXI_IRQn = 385, /* SCI1_TXI (SCI1 Transmit data empty) */
            SCI1_TEI_IRQn = 386, /* SCI1_TEI (SCI1 Transmit end) */
            SCI1_ERI_IRQn = 387, /* SCI1_ERI (SCI1 Receive error) */
            SHARED_PERIPHERAL_INTERRUPTS_MAX_ENTRIES = BSP_VECTOR_TABLE_MAX_ENTRIES
        } IRQn_Type;

        /** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
        FSP_FOOTER

        #endif /* VECTOR_DATA_H */
