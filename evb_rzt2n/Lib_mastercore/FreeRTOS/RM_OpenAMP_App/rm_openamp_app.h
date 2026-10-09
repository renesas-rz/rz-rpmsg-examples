/***********************************************************************************************************************
 * Copyright [2024] Renesas Electronics Corporation and/or its affiliates.  All Rights Reserved.
 *
 * This software and documentation are supplied by Renesas Electronics Corporation and/or its affiliates and may only
 * be used with products of Renesas Electronics Corp. and its affiliates ("Renesas").  No other uses are authorized.
 * Renesas products are sold pursuant to Renesas terms and conditions of sale.  Purchasers are solely responsible for
 * the selection and use of Renesas products and Renesas assumes no liability.  No license, express or implied, to any
 * intellectual property right is granted by Renesas.  This software is protected under all applicable laws, including
 * copyright laws. Renesas reserves the right to change or discontinue this software and/or this documentation.
 * THE SOFTWARE AND DOCUMENTATION IS DELIVERED TO YOU "AS IS," AND RENESAS MAKES NO REPRESENTATIONS OR WARRANTIES, AND
 * TO THE FULLEST EXTENT PERMISSIBLE UNDER APPLICABLE LAW, DISCLAIMS ALL WARRANTIES, WHETHER EXPLICITLY OR IMPLICITLY,
 * INCLUDING WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT, WITH RESPECT TO THE
 * SOFTWARE OR DOCUMENTATION.  RENESAS SHALL HAVE NO LIABILITY ARISING OUT OF ANY SECURITY VULNERABILITY OR BREACH.
 * TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT WILL RENESAS BE LIABLE TO YOU IN CONNECTION WITH THE SOFTWARE OR
 * DOCUMENTATION (OR ANY PERSON OR ENTITY CLAIMING RIGHTS DERIVED FROM YOU) FOR ANY LOSS, DAMAGES, OR CLAIMS WHATSOEVER,
 * INCLUDING, WITHOUT LIMITATION, ANY DIRECT, CONSEQUENTIAL, SPECIAL, INDIRECT, PUNITIVE, OR INCIDENTAL DAMAGES; ANY
 * LOST PROFITS, OTHER ECONOMIC DAMAGE, PROPERTY DAMAGE, OR PERSONAL INJURY; AND EVEN IF RENESAS HAS BEEN ADVISED OF THE
 * POSSIBILITY OF SUCH LOSS, DAMAGES, CLAIMS OR COSTS.
 **********************************************************************************************************************/

#ifndef RM_OPENAMP_APP_OPENAMP_APP_H_
#define RM_OPENAMP_APP_OPENAMP_APP_H_

#include "hal_data.h"
#include <openamp/virtio.h>
#include <RM_OpenAMP_App/platform_info.h>
#include <stdbool.h>

/** Options to configure pin functions  */
typedef enum e_rm_openamp_options
{
    OPENAMP_OP_DUTY = 0,
    OPENAMP_OP_LED,
    OPENAMP_OP_MAX
} rm_openamp_options_t;

/** Options to configure pin functions  */
typedef enum e_rm_openamp_keys
{
    OPENAMP_KEY_DUTY = 0x43210A00,
    OPENAMP_KEY_LED  = 0x43210C00,
    OPENAMP_KEY_MAX  = 0xFFFFFFFF,
} rm_openamp_keys_t;

typedef enum e_rm_openamp_state
{
    OPENAMP_STATE_CLEAR = 0,
    OPENAMP_STATE_CALLBACK_DUTY,
    OPENAMP_STATE_CALLBACK_LED,
} rm_openamp_state_t;

/** States that can be set and read for individual openamps */
typedef enum e_rm_openamp_states
{
    OPENAMP_STATE_OFF = 0,             ///< ON
    OPENAMP_STATE_ON                   ///< OFF
} rm_openamp_states_t;

/* Global variable states of OpenAMP App */
extern rm_openamp_state_t stateOpenAMP_duty;
extern rm_openamp_state_t stateOpenAMP_led;
extern uint8_t            openamp_open;

/* Declare function OpenAMP App Open */
fsp_err_t RM_OpenAMP_Open(unsigned int role, unsigned long proc_id, unsigned long rsc_id);

/* Declare function OpenAMP App writing */
fsp_err_t RM_OpenAMP_Write(rm_openamp_options_t * option, uint32_t * value);

/* Declare function OpenAMP App reading */
fsp_err_t RM_OpenAMP_Read(rm_openamp_options_t * option, uint32_t * value);

/* Declare function OpenAMP App Polling */
fsp_err_t RM_OpenAMP_Polling(void);

/* Declare function OpenAMP App close */
fsp_err_t RM_OpenAMP_Close(void);

#endif                                 /* RM_OPENAMP_APP_OPENAMP_APP_H_ */
