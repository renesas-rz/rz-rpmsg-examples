/*
 * Copyright (c) 2018, Linaro Limited. and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * @file    generic/sleep.h
 * @brief   Generic sleep primitives for libmetal.
 */

#ifndef __METAL_SLEEP__H__
 #error "Include metal/sleep.h instead of generic/sleep.h"
#endif

#ifdef FREERTOSCONFIG_H_
 #include <FreeRTOS.h>
 #include <task.h>
#else
 #include <metal/utilities.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

static inline int __metal_sleep_usec (unsigned int usec)
{
#ifdef FREERTOSCONFIG_H_
    const TickType_t xDelay = usec / portTICK_PERIOD_MS;
    vTaskDelay(xDelay);
#else
    metal_unused(usec);

    /* Fix me */
#endif

    return 0;
}

/** @} */

#ifdef __cplusplus
}
#endif
