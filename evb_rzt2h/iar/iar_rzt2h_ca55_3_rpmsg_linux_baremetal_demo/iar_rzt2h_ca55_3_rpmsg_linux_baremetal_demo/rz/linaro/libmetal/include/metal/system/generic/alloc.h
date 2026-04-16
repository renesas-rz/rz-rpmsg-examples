/*
 * Copyright (c) 2016, Xilinx Inc. and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * @file    alloc.c
 * @brief   libmetal memory allocattion definitions.
 */

#ifndef __METAL_ALLOC__H__
 #error "Include metal/alloc.h instead of generic/alloc.h"
#endif

#include <stdlib.h>

#ifdef FREERTOSCONFIG_H_
 #include "FreeRTOS.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

static inline void * metal_allocate_memory (unsigned int size)
{
#if (2 == BSP_CFG_RTOS) && configSUPPORT_DYNAMIC_ALLOCATION
    return pvPortMalloc(size);
#else
    return malloc(size);
#endif
}

static inline void metal_free_memory (void * ptr)
{
#if (2 == BSP_CFG_RTOS) && configSUPPORT_DYNAMIC_ALLOCATION
    vPortFree(ptr);
#else
    free(ptr);
#endif
}

#ifdef __cplusplus
}
#endif
