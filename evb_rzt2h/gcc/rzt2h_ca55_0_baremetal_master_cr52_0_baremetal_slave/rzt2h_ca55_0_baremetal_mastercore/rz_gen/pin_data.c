/* RZT: generated pin source file - do not edit */
#include "bsp_api.h"
#include "r_ioport_api.h"
#include "r_ioport.h"

extern const ioport_extend_cfg_t  g_ioport_cfg_extend;


const ioport_pin_cfg_t g_bsp_pin_cfg_data[] = {
    {
        .pin = BSP_IO_PORT_00_PIN_0,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_PIN_P000_PFC_13_USB_VBUSEN)
    },
    {
        .pin = BSP_IO_PORT_00_PIN_1,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_PIN_P001_PFC_13_USB_OVRCUR)
    },
    {
        .pin = BSP_IO_PORT_00_PIN_3,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_PIN_P003_PFC_00_IRQ2)
    },
    {
        .pin = BSP_IO_PORT_01_PIN_0,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SCHMITT_TRIGGER_ENABLE | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P010_PFC_1C_XSPI1_CKP)
    },
    {
        .pin = BSP_IO_PORT_01_PIN_1,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SCHMITT_TRIGGER_ENABLE | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P011_PFC_1C_XSPI1_CS0)
    },
    {
        .pin = BSP_IO_PORT_01_PIN_4,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SCHMITT_TRIGGER_ENABLE | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P014_PFC_1C_XSPI1_IO0)
    },
    {
        .pin = BSP_IO_PORT_01_PIN_5,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SCHMITT_TRIGGER_ENABLE | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P015_PFC_1C_XSPI1_IO1)
    },
    {
        .pin = BSP_IO_PORT_01_PIN_6,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SCHMITT_TRIGGER_ENABLE | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P016_PFC_1C_XSPI1_IO2)
    },
    {
        .pin = BSP_IO_PORT_01_PIN_7,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SCHMITT_TRIGGER_ENABLE | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P017_PFC_1C_XSPI1_IO3)
    },
    {
        .pin = BSP_IO_PORT_04_PIN_7,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_PIN_P047_PFC_17_IIC_SCL1)
    },
    {
        .pin = BSP_IO_PORT_05_PIN_0,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_PIN_P050_PFC_17_IIC_SDA1)
    },
    {
        .pin = BSP_IO_PORT_05_PIN_1,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P051_PFC_1C_XSPI0_CKP)
    },
    {
        .pin = BSP_IO_PORT_05_PIN_2,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P052_PFC_1C_XSPI0_CKN)
    },
    {
        .pin = BSP_IO_PORT_05_PIN_3,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P053_PFC_1C_XSPI0_CS0)
    },
    {
        .pin = BSP_IO_PORT_05_PIN_4,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P054_PFC_1C_XSPI0_CS1)
    },
    {
        .pin = BSP_IO_PORT_05_PIN_5,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P055_PFC_1C_XSPI0_DS)
    },
    {
        .pin = BSP_IO_PORT_05_PIN_6,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P056_PFC_1C_XSPI0_IO0)
    },
    {
        .pin = BSP_IO_PORT_05_PIN_7,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P057_PFC_1C_XSPI0_IO1)
    },
    {
        .pin = BSP_IO_PORT_06_PIN_0,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P060_PFC_1C_XSPI0_IO2)
    },
    {
        .pin = BSP_IO_PORT_06_PIN_1,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P061_PFC_1C_XSPI0_IO3)
    },
    {
        .pin = BSP_IO_PORT_06_PIN_2,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P062_PFC_1C_XSPI0_IO4)
    },
    {
        .pin = BSP_IO_PORT_06_PIN_3,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P063_PFC_1C_XSPI0_IO5)
    },
    {
        .pin = BSP_IO_PORT_06_PIN_4,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P064_PFC_1C_XSPI0_IO6)
    },
    {
        .pin = BSP_IO_PORT_06_PIN_5,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P065_PFC_1C_XSPI0_IO7)
    },
    {
        .pin = BSP_IO_PORT_06_PIN_6,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_PIN_P066_PFC_1C_XSPI0_RESET0)
    },
    {
        .pin = BSP_IO_PORT_06_PIN_7,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT | (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW)
    },
    {
        .pin = BSP_IO_PORT_07_PIN_0,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_PIN_P070_PFC_1C_XSPI0_RESET1)
    },
    {
        .pin = BSP_IO_PORT_07_PIN_5,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_PIN_P075_PFC_1C_XSPI0_ECS0)
    },
    {
        .pin = BSP_IO_PORT_08_PIN_1,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P081_PFC_01_TMS)
    },
    {
        .pin = BSP_IO_PORT_08_PIN_2,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SCHMITT_TRIGGER_ENABLE | (uint32_t) IOPORT_PIN_P082_PFC_01_TDI)
    },
    {
        .pin = BSP_IO_PORT_08_PIN_3,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SCHMITT_TRIGGER_ENABLE | (uint32_t) IOPORT_PIN_P083_PFC_01_TCK)
    },
    {
        .pin = BSP_IO_PORT_08_PIN_4,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P084_PFC_01_TDO)
    },
    {
        .pin = BSP_IO_PORT_08_PIN_5,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P085_PFC_29_SD1_PWEN)
    },
    {
        .pin = BSP_IO_PORT_08_PIN_6,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P086_PFC_29_SD1_IOVS)
    },
    {
        .pin = BSP_IO_PORT_08_PIN_7,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_PIN_P087_PFC_00_IRQ0)
    },
    {
        .pin = BSP_IO_PORT_11_PIN_0,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT | (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW)
    },
    {
        .pin = BSP_IO_PORT_12_PIN_0,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P120_PFC_29_SD0_CLK)
    },
    {
        .pin = BSP_IO_PORT_12_PIN_1,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P121_PFC_29_SD0_CMD)
    },
    {
        .pin = BSP_IO_PORT_12_PIN_2,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P122_PFC_29_SD0_DATA0)
    },
    {
        .pin = BSP_IO_PORT_12_PIN_3,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P123_PFC_29_SD0_DATA1)
    },
    {
        .pin = BSP_IO_PORT_12_PIN_4,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P124_PFC_29_SD0_DATA2)
    },
    {
        .pin = BSP_IO_PORT_12_PIN_5,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P125_PFC_29_SD0_DATA3)
    },
    {
        .pin = BSP_IO_PORT_12_PIN_6,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P126_PFC_29_SD0_DATA4)
    },
    {
        .pin = BSP_IO_PORT_12_PIN_7,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P127_PFC_29_SD0_DATA5)
    },
    {
        .pin = BSP_IO_PORT_13_PIN_0,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P130_PFC_29_SD0_DATA6)
    },
    {
        .pin = BSP_IO_PORT_13_PIN_1,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P131_PFC_29_SD0_DATA7)
    },
    {
        .pin = BSP_IO_PORT_13_PIN_2,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P132_PFC_29_SD0_RST)
    },
    {
        .pin = BSP_IO_PORT_13_PIN_4,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P134_PFC_14_RXD3_SCL3_MISO3)
    },
    {
        .pin = BSP_IO_PORT_13_PIN_5,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P135_PFC_14_TXD3_SDA3_MOSI3)
    },
    {
        .pin = BSP_IO_PORT_14_PIN_0,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P140_PFC_14_DE3)
    },
    {
        .pin = BSP_IO_PORT_16_PIN_3,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P163_PFC_14_RXD5_SCL5_MISO5)
    },
    {
        .pin = BSP_IO_PORT_16_PIN_4,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P164_PFC_14_TXD5_SDA5_MOSI5)
    },
    {
        .pin = BSP_IO_PORT_16_PIN_5,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P165_PFC_29_SD1_CLK)
    },
    {
        .pin = BSP_IO_PORT_16_PIN_6,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P166_PFC_29_SD1_CMD)
    },
    {
        .pin = BSP_IO_PORT_16_PIN_7,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P167_PFC_29_SD1_DATA0)
    },
    {
        .pin = BSP_IO_PORT_17_PIN_0,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P170_PFC_29_SD1_DATA1)
    },
    {
        .pin = BSP_IO_PORT_17_PIN_1,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P171_PFC_29_SD1_DATA2)
    },
    {
        .pin = BSP_IO_PORT_17_PIN_2,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P172_PFC_29_SD1_DATA3)
    },
    {
        .pin = BSP_IO_PORT_17_PIN_4,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P174_PFC_29_SD1_CD)
    },
    {
        .pin = BSP_IO_PORT_18_PIN_0,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT | (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW | (uint32_t) IOPORT_CFG_REGION_NSAFETY)
    },
    {
        .pin = BSP_IO_PORT_18_PIN_1,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT | (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW | (uint32_t) IOPORT_CFG_REGION_NSAFETY)
    },
    {
        .pin = BSP_IO_PORT_20_PIN_0,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_UHIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P200_PFC_0F_ETH0_TXCLK)
    },
    {
        .pin = BSP_IO_PORT_20_PIN_1,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P201_PFC_0F_ETH0_TXD0)
    },
    {
        .pin = BSP_IO_PORT_20_PIN_2,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P202_PFC_0F_ETH0_TXD1)
    },
    {
        .pin = BSP_IO_PORT_20_PIN_3,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P203_PFC_0F_ETH0_TXD2)
    },
    {
        .pin = BSP_IO_PORT_20_PIN_4,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P204_PFC_0F_ETH0_TXD3)
    },
    {
        .pin = BSP_IO_PORT_20_PIN_5,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P205_PFC_0F_ETH0_TXEN)
    },
    {
        .pin = BSP_IO_PORT_20_PIN_6,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P206_PFC_0F_ETH0_RXCLK)
    },
    {
        .pin = BSP_IO_PORT_20_PIN_7,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P207_PFC_0F_ETH0_RXD0)
    },
    {
        .pin = BSP_IO_PORT_21_PIN_0,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P210_PFC_0F_ETH0_RXD1)
    },
    {
        .pin = BSP_IO_PORT_21_PIN_1,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P211_PFC_0F_ETH0_RXD2)
    },
    {
        .pin = BSP_IO_PORT_21_PIN_2,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P212_PFC_0F_ETH0_RXD3)
    },
    {
        .pin = BSP_IO_PORT_21_PIN_3,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P213_PFC_0F_ETH0_RXDV)
    },
    {
        .pin = BSP_IO_PORT_21_PIN_4,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P214_PFC_10_GMAC0_MDC)
    },
    {
        .pin = BSP_IO_PORT_21_PIN_5,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P215_PFC_10_GMAC0_MDIO)
    },
    {
        .pin = BSP_IO_PORT_21_PIN_7,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P217_PFC_02_ETH0_REFCLK)
    },
    {
        .pin = BSP_IO_PORT_22_PIN_1,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P221_PFC_0F_ETH0_TXER)
    },
    {
        .pin = BSP_IO_PORT_22_PIN_2,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P222_PFC_0F_ETH0_RXER)
    },
    {
        .pin = BSP_IO_PORT_22_PIN_3,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P223_PFC_0F_ETH0_CRS)
    },
    {
        .pin = BSP_IO_PORT_22_PIN_4,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P224_PFC_0F_ETH0_COL)
    },
    {
        .pin = BSP_IO_PORT_22_PIN_7,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT | (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW | (uint32_t) IOPORT_CFG_REGION_NSAFETY)
    },
    {
        .pin = BSP_IO_PORT_23_PIN_0,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT | (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW | (uint32_t) IOPORT_CFG_REGION_NSAFETY)
    },
    {
        .pin = BSP_IO_PORT_23_PIN_1,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT | (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW | (uint32_t) IOPORT_CFG_REGION_NSAFETY)
    },
    {
        .pin = BSP_IO_PORT_23_PIN_3,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P233_PFC_17_IIC_SCL0)
    },
    {
        .pin = BSP_IO_PORT_23_PIN_4,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P234_PFC_17_IIC_SDA0)
    },
    {
        .pin = BSP_IO_PORT_23_PIN_5,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT | (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW | (uint32_t) IOPORT_CFG_REGION_NSAFETY)
    },
    {
        .pin = BSP_IO_PORT_24_PIN_3,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P243_PFC_19_CANRX0)
    },
    {
        .pin = BSP_IO_PORT_24_PIN_4,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P244_PFC_19_CANTX0)
    },
    {
        .pin = BSP_IO_PORT_24_PIN_5,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_UHIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P245_PFC_0F_ETH1_TXCLK)
    },
    {
        .pin = BSP_IO_PORT_24_PIN_6,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P246_PFC_0F_ETH1_TXD0)
    },
    {
        .pin = BSP_IO_PORT_24_PIN_7,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P247_PFC_0F_ETH1_TXD1)
    },
    {
        .pin = BSP_IO_PORT_25_PIN_0,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P250_PFC_0F_ETH1_TXD2)
    },
    {
        .pin = BSP_IO_PORT_25_PIN_1,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P251_PFC_0F_ETH1_TXD3)
    },
    {
        .pin = BSP_IO_PORT_25_PIN_2,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P252_PFC_0F_ETH1_TXEN)
    },
    {
        .pin = BSP_IO_PORT_25_PIN_3,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P253_PFC_0F_ETH1_RXCLK)
    },
    {
        .pin = BSP_IO_PORT_25_PIN_4,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P254_PFC_0F_ETH1_RXD0)
    },
    {
        .pin = BSP_IO_PORT_25_PIN_5,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P255_PFC_0F_ETH1_RXD1)
    },
    {
        .pin = BSP_IO_PORT_25_PIN_6,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P256_PFC_0F_ETH1_RXD2)
    },
    {
        .pin = BSP_IO_PORT_25_PIN_7,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P257_PFC_0F_ETH1_RXD3)
    },
    {
        .pin = BSP_IO_PORT_26_PIN_0,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P260_PFC_0F_ETH1_RXDV)
    },
    {
        .pin = BSP_IO_PORT_26_PIN_1,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P261_PFC_10_GMAC1_MDC)
    },
    {
        .pin = BSP_IO_PORT_26_PIN_2,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P262_PFC_10_GMAC1_MDIO)
    },
    {
        .pin = BSP_IO_PORT_26_PIN_4,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P264_PFC_02_ETH1_REFCLK)
    },
    {
        .pin = BSP_IO_PORT_26_PIN_6,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P266_PFC_0F_ETH1_TXER)
    },
    {
        .pin = BSP_IO_PORT_26_PIN_7,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P267_PFC_0F_ETH1_RXER)
    },
    {
        .pin = BSP_IO_PORT_27_PIN_0,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P270_PFC_0F_ETH1_CRS)
    },
    {
        .pin = BSP_IO_PORT_27_PIN_1,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P271_PFC_0F_ETH1_COL)
    },
    {
        .pin = BSP_IO_PORT_27_PIN_4,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P274_PFC_14_RXD0_SCL0_MISO0)
    },
    {
        .pin = BSP_IO_PORT_27_PIN_5,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P275_PFC_14_TXD0_SDA0_MOSI0)
    },
    {
        .pin = BSP_IO_PORT_29_PIN_1,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_UHIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P291_PFC_0F_ETH2_TXCLK)
    },
    {
        .pin = BSP_IO_PORT_29_PIN_2,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_UHIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P292_PFC_0F_ETH2_TXD0)
    },
    {
        .pin = BSP_IO_PORT_29_PIN_3,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_UHIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P293_PFC_0F_ETH2_TXD1)
    },
    {
        .pin = BSP_IO_PORT_29_PIN_4,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_UHIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P294_PFC_0F_ETH2_TXD2)
    },
    {
        .pin = BSP_IO_PORT_29_PIN_5,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_UHIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P295_PFC_0F_ETH2_TXD3)
    },
    {
        .pin = BSP_IO_PORT_29_PIN_6,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_UHIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P296_PFC_0F_ETH2_TXEN)
    },
    {
        .pin = BSP_IO_PORT_29_PIN_7,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P297_PFC_0F_ETH2_RXCLK)
    },
    {
        .pin = BSP_IO_PORT_30_PIN_0,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P300_PFC_0F_ETH2_RXD0)
    },
    {
        .pin = BSP_IO_PORT_30_PIN_1,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P301_PFC_0F_ETH2_RXD1)
    },
    {
        .pin = BSP_IO_PORT_30_PIN_2,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P302_PFC_0F_ETH2_RXD2)
    },
    {
        .pin = BSP_IO_PORT_30_PIN_3,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P303_PFC_0F_ETH2_RXD3)
    },
    {
        .pin = BSP_IO_PORT_30_PIN_4,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P304_PFC_0F_ETH2_RXDV)
    },
    {
        .pin = BSP_IO_PORT_31_PIN_0,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P310_PFC_02_ETH2_REFCLK)
    },
    {
        .pin = BSP_IO_PORT_32_PIN_2,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT | (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW | (uint32_t) IOPORT_CFG_REGION_NSAFETY)
    },
    {
        .pin = BSP_IO_PORT_32_PIN_3,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P323_PFC_1A_SPI_RSPCK1)
    },
    {
        .pin = BSP_IO_PORT_32_PIN_4,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P324_PFC_1A_SPI_MOSI1)
    },
    {
        .pin = BSP_IO_PORT_32_PIN_5,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P325_PFC_1A_SPI_MISO1)
    },
    {
        .pin = BSP_IO_PORT_32_PIN_6,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P326_PFC_1A_SPI_SSL10)
    },
    {
        .pin = BSP_IO_PORT_33_PIN_2,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_UHIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P332_PFC_0F_ETH3_TXCLK)
    },
    {
        .pin = BSP_IO_PORT_33_PIN_3,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_UHIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P333_PFC_0F_ETH3_TXD0)
    },
    {
        .pin = BSP_IO_PORT_33_PIN_4,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_UHIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P334_PFC_0F_ETH3_TXD1)
    },
    {
        .pin = BSP_IO_PORT_33_PIN_5,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_UHIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P335_PFC_0F_ETH3_TXD2)
    },
    {
        .pin = BSP_IO_PORT_33_PIN_6,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_UHIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P336_PFC_0F_ETH3_TXD3)
    },
    {
        .pin = BSP_IO_PORT_33_PIN_7,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_UHIGH | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P337_PFC_0F_ETH3_TXEN)
    },
    {
        .pin = BSP_IO_PORT_34_PIN_0,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P340_PFC_0F_ETH3_RXCLK)
    },
    {
        .pin = BSP_IO_PORT_34_PIN_1,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P341_PFC_0F_ETH3_RXD0)
    },
    {
        .pin = BSP_IO_PORT_34_PIN_2,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P342_PFC_0F_ETH3_RXD1)
    },
    {
        .pin = BSP_IO_PORT_34_PIN_3,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P343_PFC_0F_ETH3_RXD2)
    },
    {
        .pin = BSP_IO_PORT_34_PIN_4,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P344_PFC_0F_ETH3_RXD3)
    },
    {
        .pin = BSP_IO_PORT_34_PIN_5,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_PIN_P345_PFC_0F_ETH3_RXDV)
    },
    {
        .pin = BSP_IO_PORT_34_PIN_6,
        .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_MID | (uint32_t) IOPORT_CFG_PORT_PERI | (uint32_t) IOPORT_CFG_REGION_NSAFETY | (uint32_t) IOPORT_CFG_SLEW_RATE_FAST | (uint32_t) IOPORT_PIN_P346_PFC_02_ETH3_REFCLK)
    },
    {
        .pin = BSP_IO_PORT_35_PIN_3,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_INPUT | (uint32_t) IOPORT_CFG_REGION_NSAFETY)
    },
    {
        .pin = BSP_IO_PORT_35_PIN_4,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_INPUT | (uint32_t) IOPORT_CFG_REGION_NSAFETY)
    },
    {
        .pin = BSP_IO_PORT_35_PIN_5,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_INPUT | (uint32_t) IOPORT_CFG_REGION_NSAFETY)
    },
    {
        .pin = BSP_IO_PORT_35_PIN_6,
        .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_INPUT | (uint32_t) IOPORT_CFG_REGION_NSAFETY)
    },
};

const ioport_cfg_t g_bsp_pin_cfg = {
    .number_of_pins = sizeof(g_bsp_pin_cfg_data)/sizeof(ioport_pin_cfg_t),
    .p_pin_cfg_data = &g_bsp_pin_cfg_data[0],
    .p_extend = &g_ioport_cfg_extend,
};
