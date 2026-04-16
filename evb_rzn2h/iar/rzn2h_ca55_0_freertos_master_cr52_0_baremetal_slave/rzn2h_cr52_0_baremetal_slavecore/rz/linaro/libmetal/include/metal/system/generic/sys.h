/*
 * Copyright (c) 2015, Xilinx Inc. and Contributors. All rights reserved.
 * Copyright (c) 2017-2020, eForce Co Ltd. and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * @file    sys.h
 * @brief   system primitives for libmetal.
 */

#ifndef __METAL_SYS__H__
 #error "Include metal/sys.h instead of generic/sys.h"
#endif

#include <metal/errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "./rz/sys.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef METAL_MAX_DEVICE_REGIONS
 #define METAL_MAX_DEVICE_REGIONS    1
#endif

/** Structure for libmetal runtime state. */
struct metal_state
{
    /** Common (system independent) data. */
    struct metal_common_state common;
};

#ifdef METAL_INTERNAL

/**
 * @brief restore interrupts to state before disable_global_interrupt()
 */
void sys_irq_restore_enable(unsigned int flags);

/**
 * @brief disable all interrupts
 */
unsigned int sys_irq_save_disable(void);

#endif                                 /* METAL_INTERNAL */

#ifdef __cplusplus
}
#endif
