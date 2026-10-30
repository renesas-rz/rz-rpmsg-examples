/*
 * Copyright (c) 2016, Xilinx Inc. and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * @file    generic/alloc.c
 * @brief   generic libmetal memory allocattion definitions.
 */

#ifndef __METAL_ALLOC__H__
 #error "Include metal/alloc.h instead of metal/generic/alloc.h"
#endif

#ifndef __METAL_GENERIC_ALLOC__H__
 #define __METAL_GENERIC_ALLOC__H__

 #include <stdlib.h>

 #ifdef FREERTOS_CONFIG_H
  #include "FreeRTOS.h"
 #endif

 #ifdef __cplusplus
extern "C" {
 #endif

static inline void * __metal_allocate_memory (unsigned int size)
{
 #if (2 == BSP_CFG_RTOS) && configSUPPORT_DYNAMIC_ALLOCATION
    return pvPortMalloc(size);
 #else
    return malloc(size);
 #endif
}

static inline void __metal_free_memory (void * ptr)
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

#endif                                 /* __METAL_GENERIC_ALLOC__H__ */
