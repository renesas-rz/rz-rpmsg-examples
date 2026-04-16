/*
 * Copyright (c) 2019-2020 Renesas Electronics Europe Ltd. All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/*
 *  BASIC INTERRUPT DRIVEN SERIAL PORT DRIVER.
 *
 *  Note1:  This driver is used specifically to provide an interface to the
 *  FreeRTOS+CLI command interpreter.  It is *not* intended to be a generic
 *  serial port driver.  Nor is it intended to be used as an example of an
 *  efficient implementation.  In particular, a queue is used to buffer
 *  received characters, which is fine in this case as key presses arrive
 *  slowly, but a DMA and/or RAM buffer should be used in place of the queue in
 *  applications that expect higher throughput.
 *
 *  Note2:  This driver does not attempt to handle UART errors.
 */

#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <RM_OpenAMP_App/mbed_printf_implementation.h>

#include "hal_data.h"

#define SCIF_FIFO_DEPTH    16

extern uint32_t console_init(void);

/*----------------------------------------------------------------------------*/
static uint32_t xSerialPortInitialized = 0;
static uint32_t flag_tend              = 1;
uart_event_t    g_uart_callback_event;

void uart_callback (uart_callback_args_t * const p_arg)
{
    if (p_arg->event & UART_EVENT_TX_DATA_EMPTY)
    {
        flag_tend = 1;
    }
    else if (p_arg->event & UART_EVENT_RX_COMPLETE)
    {
        g_uart_callback_event = 1;
    }
}

/*----------------------------------------------------------------------------*/
static void outbyte1 (console_t console, char c)
{
    flag_tend = 0;
    g_uart0.p_api->write(g_uart0.p_ctrl, &c, 1);
    while (flag_tend == 0)
    {
#if defined(__ICCARM__)
        __asm("WFI");
#elif defined(__GNUC__)
        __WFI();
#endif
    }
}

void outbyte (console_t console, char c)
{
    if (!xSerialPortInitialized)
    {
        g_uart0.p_api->open(g_uart0.p_ctrl, g_uart0.p_cfg);
        xSerialPortInitialized = 1;
    }

    /* Standard practice to convert \n to \r\n */
    if (c == '\n')
    {
        outbyte1(console, '\r');
    }

    outbyte1(console, c);
}

/* Use a mutex around printf to avoid output from multiple threads mixed */
static char printf_initialised;

int printf (const char * format, ...)
{
    console_t console;
    va_list   args;
    int       ret;

    /* Force the output to be unbuffered */
    console = CONSOLE_RAW;
    va_start(args, format);
    ret = mbed_minimal_formatted_string(NULL, LONG_MAX, format, args, console);
    va_end(args);

    return ret;
}

int printf_buff (const char * format, ...)
{
    console_t console;
    va_list   args;
    int       ret;

    if (!printf_initialised)
    {
        printf_initialised = 1;
    }

    console = CONSOLE_BUFFERED;
    va_start(args, format);
    ret = mbed_minimal_formatted_string(NULL, LONG_MAX, format, args, console);
    va_end(args);

    return ret;
}

/*
 * Special version of printf that does not use any OS resources, it's just sends
 * characters out, blocking until the hardware has accepted all of them.
 */
int printf_raw (const char * format, ...)
{
    console_t console = CONSOLE_RAW;
    va_list   args;
    int       ret;

    va_start(args, format);
    ret = mbed_minimal_formatted_string(NULL, INT_MAX, format, args, console);
    va_end(args);

    return ret;
}

int sprintf_uart (char * buffer, const char * format, ...)
{
    console_t console = CONSOLE_CONVERSION;
    va_list   args;
    int       ret;

    va_start(args, format);
    ret = mbed_minimal_formatted_string(buffer, LONG_MAX, format, args, console);
    va_end(args);

    return ret;
}

int snprintf_uart (char * buffer, size_t length, const char * format, ...)
{
    console_t console = CONSOLE_CONVERSION;
    va_list   args;
    int       ret;

    va_start(args, format);
    ret = mbed_minimal_formatted_string(buffer, length, format, args, console);
    va_end(args);

    return ret;
}
