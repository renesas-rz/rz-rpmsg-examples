/*
 * Copyright (c) 2016, Xilinx Inc. and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * @file    generic/condition.h
 * @brief   Generic condition variable primitives for libmetal.
 */

#ifndef __METAL_CONDITION__H__
 #error "Include metal/condition.h instead of generic/condition.h"
#endif

#include <metal/atomic.h>

#ifndef FREERTOSCONFIG_H_
 #include <stdint.h>
 #include <limits.h>
 #include <metal/errno.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif
#ifdef FREERTOSCONFIG_H_
struct metal_condition
{
    metal_mutex_t * m;                 /**< mutex.
                                        *   The condition variable is attached to
                                        *   this mutex when it is waiting.
                                        *   It is also used to check correctness
                                        *   in case there are multiple waiters. */

    atomic_int v;                      /**< condition variable value. */
};

/** Static metal condition variable initialization. */
 #define METAL_CONDITION_INIT    {NULL, ATOMIC_VAR_INIT(0)}

static inline void metal_condition_init (struct metal_condition * cv)
{
    /* TODO: Implement condition variable for FreeRTOS */
    (void) cv;
}

static inline int metal_condition_signal (struct metal_condition * cv)
{
    /* TODO: Implement condition variable for FreeRTOS */
    (void) cv;

    return 0;
}

static inline int metal_condition_broadcast (struct metal_condition * cv)
{
    /* TODO: Implement condition variable for FreeRTOS */
    (void) cv;

    return 0;
}

#endif                                 /* ifdef FREERTOSCONFIG_H_ */

#ifndef FREERTOSCONFIG_H_
struct metal_condition
{
    atomic_uintptr_t mptr;             /**< mutex pointer.
                                        * The condition variable is attached to
                                        * this mutex when it is waiting.
                                        * It is also used to check correctness
                                        * in case there are multiple waiters.
                                        */

    atomic_int v;                      /**< condition variable value. */
};

/** Static metal condition variable initialization. */
 #define METAL_CONDITION_INIT    {ATOMIC_VAR_INIT(0), ATOMIC_VAR_INIT(0)}

static inline void metal_condition_init (struct metal_condition * cv)
{
    atomic_init(&cv->mptr, 0);
    atomic_init(&cv->v, 0);
}

static inline int metal_condition_signal (struct metal_condition * cv)
{
    if (!cv)
    {
        return -EINVAL;
    }

    /** wake up waiters if there are any. */
    atomic_fetch_add(&cv->v, 1);

    return 0;
}

static inline int metal_condition_broadcast (struct metal_condition * cv)
{
    return metal_condition_signal(cv);
}

#endif                                 /* Ifndef FREERTOSCONFIG_H_ */

#ifdef __cplusplus
}
#endif
