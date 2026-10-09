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

#include <RM_OpenAMP_App/rm_openamp_app.h>

#define KEY_POS      0
#define VALUE_POS    1
#define KEY_OPTION_NUM  2

/* Global variable endpoint */
static struct rpmsg_endpoint rp_ept[CFG_RPMSG_SVCNO] = {0};

/* Global variable dataRead from callback */
static uint32_t dataRead[OPENAMP_OP_MAX];

/* Global variable plaform */
static void * platform;

/* Global variable rpdev control */
struct rpmsg_device * rpdev_ctrl;

/* Global variable states of OpenAMP App */
rm_openamp_state_t stateOpenAMP_duty;
rm_openamp_state_t stateOpenAMP_led;
uint8_t            openamp_open;

/* Function of remote process msg service bind */
void rpmsg_service_bind(struct rpmsg_device * rdev, const char * name, uint32_t dest);

/* Function of remote process msg service unbind */
void rpmsg_service_unbind(struct rpmsg_endpoint * ept);

/* Function of remote process msg service callback */
int rpmsg_service_cb0(struct rpmsg_endpoint * rp_ept, void * data, size_t len, uint32_t src, void * priv);

extern void cleanup_system(void);
extern int  init_system(void);

/**
 * This function handles cleanup processing when an RPMsg service and endpoint is unbound.
 *
 * @param[out] ept  Pointer to the endpoint of rpmsg.
 *
 * Returns void.
 */
void rpmsg_service_unbind (struct rpmsg_endpoint * ept)
{
    FSP_PARAMETER_NOT_USED(ept);

    /* service 0 */
    rpmsg_destroy_ept(&rp_ept[0]);
    memset(&rp_ept, 0x0, sizeof(struct rpmsg_endpoint));
}

/**
 * This function is called when an RPMsg service is bound.
 *
 * @param[out] rdev  Pointer to the device of remote process msg.
 * @param[out] name  Pointer to the name of device.
 * @param[in] dest  Pointer to the dest of device.
 *
 * Returns void.
 */
void rpmsg_service_bind (struct rpmsg_device * rdev, const char * name, uint32_t dest)
{
    FSP_PARAMETER_NOT_USED(rdev);
    FSP_PARAMETER_NOT_USED(name);
    FSP_PARAMETER_NOT_USED(dest);

    LPRINTF("new endpoint notification is received.\n");
}

/**
 * This function is the receive callback for an RPMsg endpoint.
 *
 * @param[out] cb_rp_ept  Pointer to the endpoint of rpmsg.
 * @param[out] data       Pointer to the received data.
 * @param[in] len         Length of the received data.
 * @param[in] src         Source of the rpmsg.
 * @param[out] priv       Previous of the rpmsg. 
 *
 * Returns FSP_SUCCESS.
 */
int rpmsg_service_cb0 (struct rpmsg_endpoint * cb_rp_ept, void * data, size_t len, uint32_t src, void * priv)
{
    FSP_PARAMETER_NOT_USED(cb_rp_ept);
    FSP_PARAMETER_NOT_USED(src);
    FSP_PARAMETER_NOT_USED(priv);
    FSP_PARAMETER_NOT_USED(len);

    /* Cast data to sizeof(uint32_t) */
    uint32_t * data32 = data;

    if (data32[KEY_POS] == OPENAMP_KEY_DUTY)
    {
        dataRead[OPENAMP_OP_DUTY] = data32[VALUE_POS];

        /* Update state for openamp application */
        stateOpenAMP_duty = OPENAMP_STATE_CALLBACK_DUTY;
    }
    else if (data32[KEY_POS] == OPENAMP_KEY_LED)
    {
        dataRead[OPENAMP_OP_LED] = data32[VALUE_POS];

        /* Update state for openamp application */
        stateOpenAMP_led = OPENAMP_STATE_CALLBACK_LED;
    }
    else
    {
        /* Nothing to do */
    }

    return FSP_SUCCESS;
}

/**
 * This function performs OpenAMP polling processing in a caller context.
 *
 * Returns FSP_SUCCESS.
 */
fsp_err_t RM_OpenAMP_Polling (void)
{
    (void) platform_get_notification(platform);

    return FSP_SUCCESS;
}

/**
 * This function reads the stored data value associated with the specified option.
 *
 * @param[in] option      Point option of input value option
 * @param[out] value      Point option of output value
 *
 * Returns FSP_SUCCESS.
 */
fsp_err_t RM_OpenAMP_Read (rm_openamp_options_t * option, uint32_t * value)
{
    /* Process data reading */
    *value = dataRead[*option];

    return FSP_SUCCESS;
}

/**
 * This function writes a key and value pair to the other core using RPMsg.
 *
 * @param[in] option      Point option of input value option. Input values are limited to 0 and 1.
 * @param[in] value       Point option of input value.
 *
 * Returns FSP_SUCCESS.
 * Returns FSP_ERR_INVALID_ARGUMENT.
 */
fsp_err_t RM_OpenAMP_Write (rm_openamp_options_t * option, uint32_t * value)
{
    if (* option >= KEY_OPTION_NUM)
    {
        return FSP_ERR_INVALID_ARGUMENT;
    } 

    static uint32_t keyOption[] =
    {
        OPENAMP_KEY_DUTY,
        OPENAMP_KEY_LED,
    };
    static uint32_t datarx[2];

    /* Process data writing */
    datarx[0] = keyOption[*option];
    if (*option == 0)
    {
        stateOpenAMP_duty = OPENAMP_STATE_CLEAR;
    }
    else if (*option == 1)
    {
        stateOpenAMP_led = OPENAMP_STATE_CLEAR;
    }

    datarx[1] = *value;
    rpmsg_send(&rp_ept[0], &datarx[0], sizeof(datarx));

    return FSP_SUCCESS;
}

/**
 * This function closes OpenAMP and releases related resources. 
 *
 *
 * Returns FSP_SUCCESS.
 */
fsp_err_t RM_OpenAMP_Close (void)
{
    /* Release vdev */
    platform_release_rpmsg_vdev(platform, rpdev_ctrl);
    LPRINTF("Release rpmsg vdev...\n");

    /* Release platform */
    platform_cleanup(platform);
    LPRINTF("Release platform  cleanup...\n");

    /* Cleanup system */
    cleanup_system();

    /* Close the icu_inter_cpu_irq */
    g_icu_inter_cpu_irq0.p_api->close(g_icu_inter_cpu_irq0.p_ctrl);
    g_icu_inter_cpu_irq1.p_api->close(g_icu_inter_cpu_irq1.p_ctrl);

    return FSP_SUCCESS;
}

/**
 * This function initializes OpenAMP and creates endpoints.
 *
 * @param[in] role        Master/Slave role
 * @param[in] proc_id     Number process ID
 * @param[in] rsc_id      Number resource ID
 *
 * Returns FSP_SUCCESS.
 * Returns FSP_ERR_ABORTED.
 */
fsp_err_t RM_OpenAMP_Open (unsigned int role, unsigned long proc_id, unsigned long rsc_id)
{
    int ret;
    ret = init_system();
    if (ret)
    {
        LPERROR("Failed to init remoteproc device.\n");
        return FSP_ERR_ABORTED;
    }
    else
    {
        ret = platform_init(proc_id, rsc_id, &platform);

        if (ret)
        {
            LPERROR("Failed to create remoteproc device.\n");
            return FSP_ERR_ABORTED;
        }
        else
        {
            rpdev_ctrl = platform_create_rpmsg_vdev(platform, 0x0U, role, NULL, NULL);
            if (!rpdev_ctrl)
            {
                LPERROR("Fail, platform_create_rpmsg_vdev.\n");
                metal_log(METAL_LOG_INFO, "Fail, platform_create_rpmsg_vdev.");

                return FSP_ERR_ABORTED;
            }

            LPRINTF("Remote proc init.\n");
            ret = rpmsg_create_ept((struct rpmsg_endpoint *) rp_ept,
                                   rpdev_ctrl,
                                   CFG_RPMSG_SVC_NAME0,
                                   APP_EPT_ADDR,
                                   RPMSG_ADDR_ANY,
                                   rpmsg_service_cb0,
                                   rpmsg_service_unbind);
            if (ret)
            {
                LPERROR("Failed to create RPMsg endpoint.\n");

                return FSP_ERR_ABORTED;
            }

            LPRINTF("RPMSG endpoint has created.\n");

            while (!is_rpmsg_ept_ready((struct rpmsg_endpoint *) rp_ept))
            {
                platform_poll(platform);
            }
        }
    }

    /* Dummy one time for polling */
    RM_OpenAMP_Polling();
    openamp_open = 1;

    return FSP_SUCCESS;
}
