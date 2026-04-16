/*
 * Copyright (c) 2018, Xilinx Inc. and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * @file    assert.h
 * @brief   assertion support.
 */
#ifndef __METAL_ASSERT__H__
 #error "Include metal/assert.h instead of generic/assert.h"
#endif

#ifdef double_assert
 #error recursive2
#endif

#define double_asser
#include <assert.h>

#undef double_assert

/**
 * @brief Assertion macro for bare-metal/FreeRTOS applications.
 * @param cond Condition to evaluate.
 */
#define metal_sys_assert(cond)    assert(cond)
