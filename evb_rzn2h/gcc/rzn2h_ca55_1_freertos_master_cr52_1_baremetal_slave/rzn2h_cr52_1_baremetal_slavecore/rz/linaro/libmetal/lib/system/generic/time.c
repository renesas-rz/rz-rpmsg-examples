/*
 * Copyright (c) 2016, Xilinx Inc. and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * @file    time.c
 * @brief   libmetal time handling.
 */
#ifdef FREERTOSCONFIG_H_
 #include <FreeRTOS.h>
 #include <task.h>
#endif                                 /* FREERTOSCONFIG_H_ */

#include <metal/time.h>

unsigned long long metal_get_timestamp (void)
{
    /* TODO: Implement timestamp for generic system */
#ifdef FREERTOSCONFIG_H_
    return (unsigned long long) xTaskGetTickCount();
#else
    return 0;
#endif                                 /* FREERTOSCONFIG_H_ */
}
