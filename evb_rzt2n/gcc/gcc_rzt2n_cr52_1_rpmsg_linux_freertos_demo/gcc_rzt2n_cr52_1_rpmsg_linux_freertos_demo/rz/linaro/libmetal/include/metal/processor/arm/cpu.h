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

static inline void metal_cpu_yield (void)
{
#if defined(__aarch64__)
    metal_asm volatile ("yield");
#else

    /* fallback to empty */
#endif
}

#endif                                 /* __METAL_ARM_CPU__H__ */
