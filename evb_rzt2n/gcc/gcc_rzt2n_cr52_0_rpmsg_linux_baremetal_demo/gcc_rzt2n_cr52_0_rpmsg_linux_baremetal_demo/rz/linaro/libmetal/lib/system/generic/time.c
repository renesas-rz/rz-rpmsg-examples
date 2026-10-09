/*
 * Copyright (c) 2016, Xilinx Inc. and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * @file    generic/time.c
 * @brief   Generic libmetal time handling.
 */

#ifdef FREERTOS_CONFIG_H
 #include <FreeRTOS.h>
 #include <task.h>
#endif                                 /* FREERTOS_CONFIG_H */
#include <metal/time.h>

unsigned long long metal_get_timestamp (void)
{
#ifdef FREERTOS_CONFIG_H
    return (unsigned long long) (1000 * portTICK_PERIOD_MS * xTaskGetTickCount());
#else

    /* TODO: Implement timestamp for generic system */
    return 0;
#endif                                 /* FREERTOS_CONFIG_H */
}
