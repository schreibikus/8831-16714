//<MStar Software>
//******************************************************************************
// MStar Software
// Copyright (c) 2010 - 2012 MStar Semiconductor, Inc. All rights reserved.
// All software, firmware and related documentation herein ("MStar Software") are
// intellectual property of MStar Semiconductor, Inc. ("MStar") and protected by
// law, including, but not limited to, copyright law and international treaties.
// Any use, modification, reproduction, retransmission, or republication of all
// or part of MStar Software is expressly prohibited, unless prior written
// permission has been granted by MStar.
//
// By accessing, browsing and/or using MStar Software, you acknowledge that you
// have read, understood, and agree, to be bound by below terms ("Terms") and to
// comply with all applicable laws and regulations:
//
// 1. MStar shall retain any and all right, ownership and interest to MStar
//    Software and any modification/derivatives thereof.
//    No right, ownership, or interest to MStar Software and any
//    modification/derivatives thereof is transferred to you under Terms.
//
// 2. You understand that MStar Software might include, incorporate or be
//    supplied together with third party`s software and the use of MStar
//    Software may require additional licenses from third parties.
//    Therefore, you hereby agree it is your sole responsibility to separately
//    obtain any and all third party right and license necessary for your use of
//    such third party`s software.
//
// 3. MStar Software and any modification/derivatives thereof shall be deemed as
//    MStar`s confidential information and you agree to keep MStar`s
//    confidential information in strictest confidence and not disclose to any
//    third party.
//
// 4. MStar Software is provided on an "AS IS" basis without warranties of any
//    kind. Any warranties are hereby expressly disclaimed by MStar, including
//    without limitation, any warranties of merchantability, non-infringement of
//    intellectual property rights, fitness for a particular purpose, error free
//    and in conformity with any international standard.  You agree to waive any
//    claim against MStar for any loss, damage, cost or expense that you may
//    incur related to your use of MStar Software.
//    In no event shall MStar be liable for any direct, indirect, incidental or
//    consequential damages, including without limitation, lost of profit or
//    revenues, lost or damage of data, and unauthorized system use.
//    You agree that this Section 4 shall still apply without being affected
//    even if MStar Software has been modified by MStar in accordance with your
//    request or instruction for your use, except otherwise agreed by both
//    parties in writing.
//
// 5. If requested, MStar may from time to time provide technical supports or
//    services in relation with MStar Software to you for your use of
//    MStar Software in conjunction with your or your customer`s product
//    ("Services").
//    You understand and agree that, except otherwise agreed by both parties in
//    writing, Services are provided on an "AS IS" basis and the warranty
//    disclaimer set forth in Section 4 above shall apply.
//
// 6. Nothing contained herein shall be construed as by implication, estoppels
//    or otherwise:
//    (a) conferring any license or right to use MStar name, trademark, service
//        mark, symbol or any other identification;
//    (b) obligating MStar or any of its affiliates to furnish any person,
//        including without limitation, you and your customers, any assistance
//        of any kind whatsoever, or any information; or
//    (c) conferring any license or right under any intellectual property right.
//
// 7. These terms shall be governed by and construed in accordance with the laws
//    of Taiwan, R.O.C., excluding its conflict of law rules.
//    Any and all dispute arising out hereof or related hereto shall be finally
//    settled by arbitration referred to the Chinese Arbitration Association,
//    Taipei in accordance with the ROC Arbitration Law and the Arbitration
//    Rules of the Association by three (3) arbitrators appointed in accordance
//    with the said Rules.
//    The place of arbitration shall be in Taipei, Taiwan and the language shall
//    be English.
//    The arbitration award shall be final and binding to both parties.
//
//******************************************************************************
//<MStar Software>
///////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file   msAPI_CEC_StateMachine.h
/// @author MStar Semiconductor Inc.
/// @brief  CEC API Interface
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _MSAPI_CEC_STATEMACHINE_H_
#define _MSAPI_CEC_STATEMACHINE_H_

/*************************************************************************************************/

#include "datatype.h"
#include "apiCEC.h"

/*************************************************************************************************/

typedef struct _CECSTATEMSG
{
    MsCEC_DEVICELA enDevice;
    MsCEC_MSGLIST enOpcode;
    MS_U8 u8OrigPhyAddress[2], u8NewPhyAddress[2];

} CECSTATEMSG;

typedef CECSTATEMSG* PCECSTATEMSG;


#define E_CEC_STATE_IDLE    0

typedef enum
{
    E_CEC_STATE_7_IDLE = E_CEC_STATE_IDLE,
        E_CEC_STATE_7_SEND_ROUTING_CHANGE,
        E_CEC_STATE_7_WAIT_FOR_ROUTING_INFORMATION,
        E_CEC_STATE_7_SENT_GIVE_DEVICE_POWER_STATES,
        E_CEC_STATE_7_WAIT_FOR_REPORT_POWER_STATE,
        E_CEC_STATE_7_CONTINUTE_GIVE_DEVICE_POWER_STATE_PER_6S,
        E_CEC_STATE_7_SENT_SET_STREAM_PATH,
        E_CEC_STATE_7_SENT_USER_CONTROL_PRESSED,

    E_CEC_STATE_DONE,

} EN_CEC_CASE_STATE;
typedef enum
{
    E_CEC_STATE_6_3_3_2_IDLE = E_CEC_STATE_IDLE,

    E_CEC_STATE_6_3_3_2_SEND_ROUTING_CHANGE,
    E_CEC_STATE_6_3_3_2_WAIT_FOR_ROUTING_INFORMATION,
    E_CEC_STATE_6_3_3_2_SET_STREAM_PATH_AFTER_500MS,
    E_CEC_STATE_6_3_3_2_REPORT_POWER_STATUS,
    E_CEC_STATE_6_3_3_2_5,
    E_CEC_STATE_6_3_3_2_6,
    E_CEC_STATE_6_3_3_2_7,
    E_CEC_STATE_6_3_3_2_8,

    E_CEC_STATE_6_3_3_2_DONE,

} EN_CEC_CASE_6_3_3_2_STATE;


typedef enum
{
    E_CEC_STATE_XX_IDLE = E_CEC_STATE_IDLE,

    E_CEC_STATE_XX_1,
    E_CEC_STATE_XX_2,

    E_CEC_STATE_XX_DONE,

} EN_CEC_CASE_2_STATE;





/*************************************************************************************************/
#endif // #ifndef _MSAPI_CEC_STATEMACHINE_H_

