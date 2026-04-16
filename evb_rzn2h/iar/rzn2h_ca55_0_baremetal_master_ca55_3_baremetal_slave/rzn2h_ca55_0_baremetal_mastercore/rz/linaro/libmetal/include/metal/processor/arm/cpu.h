/*
 * Copyright (c) 2015, Xilinx Inc. and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * @file    cpu.h
 * @brief   CPU specific primatives
 */

#ifndef __METAL_ARM_CPU__H__
#define __METAL_ARM_CPU__H__

#ifdef FREERTOSCONFIG_H_
 #include "FreeRTOS.h"
 #include "task.h"
#endif

#ifdef FREERTOSCONFIG_H_
 #define metal_cpu_yield()    taskYIELD()
#else
 #define metal_cpu_yield()
#endif

#endif                                 /* __METAL_ARM_CPU__H__ */
