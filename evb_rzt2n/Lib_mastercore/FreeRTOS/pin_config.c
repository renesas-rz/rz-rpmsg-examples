/* generated pin source file - do not edit */
#include "bsp_api.h"
#include "r_ioport_api.h"
#include "r_ioport.h"

extern const ioport_extend_cfg_t g_ioport_cfg_extend;

const ioport_pin_cfg_t g_bsp_pin_cfg_data1[] =
{
    {.pin = BSP_IO_PORT_00_PIN_0, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P000_PFC_0F_ETH3_TXCLK)},
    {.pin = BSP_IO_PORT_00_PIN_1, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P001_PFC_0F_ETH3_TXD0)},
    {.pin = BSP_IO_PORT_00_PIN_2, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P002_PFC_0F_ETH3_TXD1)},
    {.pin = BSP_IO_PORT_00_PIN_3, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P003_PFC_0F_ETH3_TXD2)},
    {.pin = BSP_IO_PORT_00_PIN_4, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P004_PFC_0F_ETH3_TXD3)},
    {.pin = BSP_IO_PORT_00_PIN_5, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_PIN_P005_PFC_0F_ETH3_TXEN)},
    {.pin = BSP_IO_PORT_00_PIN_6, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_PIN_P006_PFC_0F_ETH3_RXCLK)},
    {.pin = BSP_IO_PORT_00_PIN_7, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_PIN_P007_PFC_0F_ETH3_RXD0)},
    {.pin = BSP_IO_PORT_01_PIN_0, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_PIN_P010_PFC_0F_ETH3_RXD1)},
    {.pin = BSP_IO_PORT_01_PIN_1, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_PIN_P011_PFC_0F_ETH3_RXD2)},
    {.pin = BSP_IO_PORT_01_PIN_2, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_PIN_P012_PFC_0F_ETH3_RXD3)},
    {.pin = BSP_IO_PORT_01_PIN_3, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_PIN_P013_PFC_0F_ETH3_RXDV)},
    {.pin = BSP_IO_PORT_01_PIN_4, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_PIN_P014_PFC_02_ETH3_REFCLK)},
    {.pin = BSP_IO_PORT_01_PIN_5, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_PIN_PFC_00_IRQ3)},
    {.pin = BSP_IO_PORT_01_PIN_6, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P016_PFC_0F_ETH4_TXCLK)},
    {.pin = BSP_IO_PORT_01_PIN_7, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P017_PFC_0F_ETH4_TXD0)},
    {.pin = BSP_IO_PORT_02_PIN_0, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P020_PFC_0F_ETH4_TXD1)},
    {.pin = BSP_IO_PORT_02_PIN_1, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P021_PFC_0F_ETH4_TXD2)},
    {.pin = BSP_IO_PORT_02_PIN_2, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P022_PFC_0F_ETH4_TXD3)},
    {.pin = BSP_IO_PORT_02_PIN_3, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_PIN_P023_PFC_0F_ETH4_TXEN)},
    {.pin = BSP_IO_PORT_02_PIN_4, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_PIN_P024_PFC_0F_ETH4_RXCLK)},
    {.pin = BSP_IO_PORT_02_PIN_5, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_PIN_P025_PFC_0F_ETH4_RXD0)},
    {.pin = BSP_IO_PORT_02_PIN_6, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_PIN_P026_PFC_0F_ETH4_RXD1)},
    {.pin = BSP_IO_PORT_02_PIN_7, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_PIN_P027_PFC_0F_ETH4_RXD2)},
    {.pin = BSP_IO_PORT_03_PIN_0, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_PIN_P030_PFC_0F_ETH4_RXD3)},
    {.pin = BSP_IO_PORT_03_PIN_1, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_PIN_P031_PFC_0F_ETH4_RXDV)},
    {.pin = BSP_IO_PORT_03_PIN_2, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P032_PFC_2C_SD1_IOVS)},
    {.pin = BSP_IO_PORT_03_PIN_3, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P033_PFC_2C_SD1_PWEN)},
    {.pin = BSP_IO_PORT_03_PIN_4, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_PIN_P034_PFC_02_ETH4_REFCLK)},
    {.pin = BSP_IO_PORT_03_PIN_6, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P036_PFC_2C_SD1_CLK)},
    {.pin = BSP_IO_PORT_03_PIN_7, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P037_PFC_2C_SD1_CMD)},
    {.pin = BSP_IO_PORT_04_PIN_0, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P040_PFC_2C_SD1_DATA0)},
    {.pin = BSP_IO_PORT_04_PIN_1, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P041_PFC_2C_SD1_DATA1)},
    {.pin = BSP_IO_PORT_04_PIN_2, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P042_PFC_2C_SD1_DATA2)},
    {.pin = BSP_IO_PORT_04_PIN_3, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P043_PFC_2C_SD1_DATA3)},
    {.pin = BSP_IO_PORT_04_PIN_5, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT_INPUT |
                                              (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW)},
    {.pin = BSP_IO_PORT_04_PIN_6, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT_INPUT |
                                              (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW)},
    {.pin = BSP_IO_PORT_04_PIN_7, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT_INPUT |
                                              (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW)},
    {.pin = BSP_IO_PORT_05_PIN_0, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT_INPUT |
                                              (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW)},
    {.pin = BSP_IO_PORT_05_PIN_2, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_INPUT)                         },
    {.pin = BSP_IO_PORT_05_PIN_3, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_INPUT)                         },
    {.pin = BSP_IO_PORT_09_PIN_2, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_PFC_00_IRQ9)},
    {.pin = BSP_IO_PORT_09_PIN_4, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_INPUT |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY)},
    {.pin = BSP_IO_PORT_09_PIN_7, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT_INPUT |
                                              (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY)},
    {.pin = BSP_IO_PORT_10_PIN_1, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT_INPUT |
                                              (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY)},
    {.pin = BSP_IO_PORT_11_PIN_0, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P110_PFC_17_USB_VBUSEN)},
    {.pin = BSP_IO_PORT_11_PIN_1, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P111_PFC_18_RXD1_SCL1_MISO1)},
    {.pin = BSP_IO_PORT_11_PIN_2, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P112_PFC_18_TXD1_SDA1_MOSI1)},
    {.pin = BSP_IO_PORT_11_PIN_3, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P113_PFC_18_RXD0_SCL0_MISO0)},
    {.pin = BSP_IO_PORT_11_PIN_4, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P114_PFC_18_TXD0_SDA0_MOSI0)},
    {.pin = BSP_IO_PORT_11_PIN_6, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P116_PFC_17_USB_OVRCUR)},
    {.pin = BSP_IO_PORT_12_PIN_0, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P120_PFC_01_TMS)},
    {.pin = BSP_IO_PORT_12_PIN_1, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P121_PFC_01_TDI)},
    {.pin = BSP_IO_PORT_12_PIN_2, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P122_PFC_01_TCK)},
    {.pin = BSP_IO_PORT_12_PIN_3, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P123_PFC_01_TDO)},
    {.pin = BSP_IO_PORT_12_PIN_4, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_PFC_00_IRQ12)},
    {.pin = BSP_IO_PORT_14_PIN_1, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT_INPUT |
                                              (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY)},
    {.pin = BSP_IO_PORT_14_PIN_2, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT_INPUT |
                                              (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY)},
    {.pin = BSP_IO_PORT_14_PIN_3, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P143_PFC_17_USB_EXICEN)},
    {.pin = BSP_IO_PORT_14_PIN_4, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_PFC_00_IRQ14)},
    {.pin = BSP_IO_PORT_14_PIN_5, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT_INPUT |
                                              (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY)},
    {.pin = BSP_IO_PORT_14_PIN_6, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT_INPUT |
                                              (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY)},
    {.pin = BSP_IO_PORT_14_PIN_7, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_INPUT |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY)},
    {.pin = BSP_IO_PORT_15_PIN_0, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P150_PFC_2C_SD1_CD)},
    {.pin = BSP_IO_PORT_15_PIN_1, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_PFC_00_IRQ4)},
    {.pin = BSP_IO_PORT_15_PIN_6, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SCHMITT_TRIGGER_ENABLE |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P156_PFC_20_XSPI1_CKP)},
    {.pin = BSP_IO_PORT_15_PIN_7, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SCHMITT_TRIGGER_ENABLE |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P157_PFC_20_XSPI1_CS0)},
    {.pin = BSP_IO_PORT_16_PIN_1, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT_INPUT |
                                              (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY)},
    {.pin = BSP_IO_PORT_16_PIN_2, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SCHMITT_TRIGGER_ENABLE |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P162_PFC_20_XSPI1_IO0)},
    {.pin = BSP_IO_PORT_16_PIN_3, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SCHMITT_TRIGGER_ENABLE |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P163_PFC_20_XSPI1_IO1)},
    {.pin = BSP_IO_PORT_16_PIN_4, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SCHMITT_TRIGGER_ENABLE |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P164_PFC_20_XSPI1_IO2)},
    {.pin = BSP_IO_PORT_16_PIN_5, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SCHMITT_TRIGGER_ENABLE |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P165_PFC_20_XSPI1_IO3)},
    {.pin = BSP_IO_PORT_17_PIN_2, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SCHMITT_TRIGGER_ENABLE |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P172_PFC_20_XSPI0_CKP)},
    {.pin = BSP_IO_PORT_17_PIN_3, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SCHMITT_TRIGGER_ENABLE |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P173_PFC_20_XSPI0_CKN)},
    {.pin = BSP_IO_PORT_17_PIN_4, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SCHMITT_TRIGGER_ENABLE |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P174_PFC_20_XSPI0_CS0)},
    {.pin = BSP_IO_PORT_17_PIN_5, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SCHMITT_TRIGGER_ENABLE |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P175_PFC_20_XSPI0_CS1)},
    {.pin = BSP_IO_PORT_17_PIN_6, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SCHMITT_TRIGGER_ENABLE |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P176_PFC_20_XSPI0_DS)},
    {.pin = BSP_IO_PORT_17_PIN_7, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SCHMITT_TRIGGER_ENABLE |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P177_PFC_20_XSPI0_IO0)},
    {.pin = BSP_IO_PORT_18_PIN_0, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SCHMITT_TRIGGER_ENABLE |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P180_PFC_20_XSPI0_IO1)},
    {.pin = BSP_IO_PORT_18_PIN_1, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SCHMITT_TRIGGER_ENABLE |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P181_PFC_20_XSPI0_IO2)},
    {.pin = BSP_IO_PORT_18_PIN_2, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SCHMITT_TRIGGER_ENABLE |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P182_PFC_20_XSPI0_IO3)},
    {.pin = BSP_IO_PORT_18_PIN_3, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SCHMITT_TRIGGER_ENABLE |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P183_PFC_20_XSPI0_IO4)},
    {.pin = BSP_IO_PORT_18_PIN_4, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SCHMITT_TRIGGER_ENABLE |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P184_PFC_20_XSPI0_IO5)},
    {.pin = BSP_IO_PORT_18_PIN_5, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SCHMITT_TRIGGER_ENABLE |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P185_PFC_20_XSPI0_IO6)},
    {.pin = BSP_IO_PORT_18_PIN_6, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SCHMITT_TRIGGER_ENABLE |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P186_PFC_20_XSPI0_IO7)},
    {.pin = BSP_IO_PORT_18_PIN_7, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P187_PFC_20_XSPI0_RESET0)},
    {.pin = BSP_IO_PORT_19_PIN_0, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P190_PFC_0F_ETH0_TXCLK)},
    {.pin = BSP_IO_PORT_19_PIN_1, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P191_PFC_0F_ETH0_TXD0)},
    {.pin = BSP_IO_PORT_19_PIN_2, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P192_PFC_0F_ETH0_TXD1)},
    {.pin = BSP_IO_PORT_19_PIN_3, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P193_PFC_0F_ETH0_TXD2)},
    {.pin = BSP_IO_PORT_19_PIN_4, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P194_PFC_0F_ETH0_TXD3)},
    {.pin = BSP_IO_PORT_19_PIN_5, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P195_PFC_0F_ETH0_TXEN)},
    {.pin = BSP_IO_PORT_19_PIN_6, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P196_PFC_0F_ETH0_RXCLK)},
    {.pin = BSP_IO_PORT_19_PIN_7, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P197_PFC_0F_ETH0_RXD0)},
    {.pin = BSP_IO_PORT_20_PIN_0, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P200_PFC_0F_ETH0_RXD1)},
    {.pin = BSP_IO_PORT_20_PIN_1, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P201_PFC_0F_ETH0_RXD2)},
    {.pin = BSP_IO_PORT_20_PIN_2, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P202_PFC_0F_ETH0_RXD3)},
    {.pin = BSP_IO_PORT_20_PIN_3, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P203_PFC_0F_ETH0_RXDV)},
    {.pin = BSP_IO_PORT_20_PIN_4, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P204_PFC_11_GMAC0_MDC)},
    {.pin = BSP_IO_PORT_20_PIN_5, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P205_PFC_11_GMAC0_MDIO)},
    {.pin = BSP_IO_PORT_20_PIN_6, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P206_PFC_14_ETHSW_PHYLINK0)},
    {.pin = BSP_IO_PORT_20_PIN_7, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P207_PFC_02_ETH0_REFCLK)},
    {.pin = BSP_IO_PORT_21_PIN_0, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_PFC_00_IRQ0)},
    {.pin = BSP_IO_PORT_21_PIN_1, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P211_PFC_0F_ETH1_TXCLK)},
    {.pin = BSP_IO_PORT_21_PIN_2, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P212_PFC_0F_ETH1_TXD0)},
    {.pin = BSP_IO_PORT_21_PIN_3, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P213_PFC_0F_ETH1_TXD1)},
    {.pin = BSP_IO_PORT_21_PIN_4, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P214_PFC_0F_ETH1_TXD2)},
    {.pin = BSP_IO_PORT_21_PIN_5, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P215_PFC_0F_ETH1_TXD3)},
    {.pin = BSP_IO_PORT_21_PIN_6, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P216_PFC_0F_ETH1_TXEN)},
    {.pin = BSP_IO_PORT_21_PIN_7, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P217_PFC_0F_ETH1_RXCLK)},
    {.pin = BSP_IO_PORT_22_PIN_0, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P220_PFC_0F_ETH1_RXD0)},
    {.pin = BSP_IO_PORT_22_PIN_1, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P221_PFC_0F_ETH1_RXD1)},
    {.pin = BSP_IO_PORT_22_PIN_2, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P222_PFC_0F_ETH1_RXD2)},
    {.pin = BSP_IO_PORT_22_PIN_3, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P223_PFC_0F_ETH1_RXD3)},
    {.pin = BSP_IO_PORT_22_PIN_4, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P224_PFC_0F_ETH1_RXDV)},
    {.pin = BSP_IO_PORT_22_PIN_5, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P225_PFC_14_ETHSW_PHYLINK1)},
    {.pin = BSP_IO_PORT_22_PIN_6, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P226_PFC_02_ETH1_REFCLK)},
    {.pin = BSP_IO_PORT_22_PIN_7, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_PFC_00_IRQ1)},
    {.pin = BSP_IO_PORT_23_PIN_0, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P230_PFC_0F_ETH2_TXCLK)},
    {.pin = BSP_IO_PORT_23_PIN_1, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P231_PFC_0F_ETH2_TXD0)},
    {.pin = BSP_IO_PORT_23_PIN_2, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P232_PFC_0F_ETH2_TXD1)},
    {.pin = BSP_IO_PORT_23_PIN_3, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P233_PFC_0F_ETH2_TXD2)},
    {.pin = BSP_IO_PORT_23_PIN_4, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI |
                                              (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_CFG_SLEW_RATE_FAST |
                                              (uint32_t) IOPORT_PIN_P234_PFC_0F_ETH2_TXD3)},
    {.pin = BSP_IO_PORT_23_PIN_5, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P235_PFC_0F_ETH2_TXEN)},
    {.pin = BSP_IO_PORT_23_PIN_6, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P236_PFC_0F_ETH2_RXCLK)},
    {.pin = BSP_IO_PORT_23_PIN_7, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P237_PFC_0F_ETH2_RXD0)},
    {.pin = BSP_IO_PORT_24_PIN_0, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P240_PFC_0F_ETH2_RXD1)},
    {.pin = BSP_IO_PORT_24_PIN_1, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P241_PFC_0F_ETH2_RXD2)},
    {.pin = BSP_IO_PORT_24_PIN_2, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P242_PFC_0F_ETH2_RXD3)},
    {.pin = BSP_IO_PORT_24_PIN_3, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P243_PFC_0F_ETH2_RXDV)},
    {.pin = BSP_IO_PORT_24_PIN_4, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P244_PFC_02_ETH2_REFCLK)},
    {.pin = BSP_IO_PORT_24_PIN_5, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_PFC_00_IRQ2)},
    {.pin = BSP_IO_PORT_24_PIN_6, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P246_PFC_12_GMAC1_MDC)},
    {.pin = BSP_IO_PORT_24_PIN_7, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P247_PFC_12_GMAC1_MDIO)},
    {.pin = BSP_IO_PORT_25_PIN_0, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY |
                                              (uint32_t) IOPORT_PIN_P250_PFC_14_ETHSW_PHYLINK2)},
};

const ioport_cfg_t g_bsp_pin_cfg1 =
{
    .number_of_pins = sizeof(g_bsp_pin_cfg_data1) / sizeof(ioport_pin_cfg_t),
    .p_pin_cfg_data = &g_bsp_pin_cfg_data1[0],
    .p_extend       = &g_ioport_cfg_extend,
};
