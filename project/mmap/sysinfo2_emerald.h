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
////////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2006-2009 MStar Semiconductor, Inc.
// All rights reserved.
//
// Unless otherwise stipulated in writing, any and all information contained
// herein regardless in any format shall remain the sole proprietary of
// MStar Semiconductor Inc. and be kept in strict confidence
// (��MStar Confidential Information��) by the recipient.
// Any unauthorized act including without limitation unauthorized disclosure,
// copying, use, reproduction, sale, distribution, modification, disassembling,
// reverse engineering and compiling of the contents of MStar Confidential
// Information is unlawful and strictly prohibited. MStar hereby reserves the
// rights to any and all damages, losses, costs and expenses resulting therefrom.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _SYSINFO_H_
#define _SYSINFO_H_

#include "Board.h"
#include "datatype.h"

//------------------------------------------------------------------------------
// Bank Info
//------------------------------------------------------------------------------
#define SYSTEM_BANK_SIZE            0x10000 // 64k

// Baudrate for UART: 4800 / 9600 / 19200 / 38400
#ifndef UART0_BAUDRATE
    #if XMODEM_DWNLD_ENABLE
    #define UART0_BAUDRATE          115200
    #else
    #define UART0_BAUDRATE          115200    //38400
    #endif
#endif

//#define OSD_USE_GOP1
#ifdef OSD_USE_GOP1
#undef E_GOP_APP
#undef E_GOP_OSD
#undef E_GOP_CAP

#define E_GOP_APP   1   // Subtitle/MHEG5
#define E_GOP_OSD   0
#define E_GOP_CAP   2
#endif

#define  CLK_144MHZ     144000000
#define  CLK_160MHZ     160000000
#define  CLK_172P8MHZ   172800000
#define  CLK_192MHZ     192000000
#define  CLK_216MHZ     216000000

#define  AEON_OPERATE_CLK       172800000

#if ( AEON_OPERATE_CLK == CLK_144MHZ )
  #define       CKG_AEON         0x0c
#elif ( AEON_OPERATE_CLK == CLK_160MHZ )
  #define       CKG_AEON         0x08
#elif ( AEON_OPERATE_CLK == CLK_192MHZ )
  #define       CKG_AEON         0x10
#elif ( AEON_OPERATE_CLK == CLK_216MHZ )
  #define       CKG_AEON         0x00
#else  //172.8Mhz
  #define       CKG_AEON         0x04
#endif

// Memory alignment
#define MemAlignUnit                64UL
#define MemAlign(n, unit)           ((((n)+(unit)-1)/(unit))*(unit))

//------------------------------------------------------------------------------
// DRAM memory map
//------------------------------------------------------------------------------
#ifdef ATSC_SYSTEM

#if ( MEMORY_MAP == MMAP_128_128MB )
    #include "MMAP_ATSCMM_EMERALD_128_128_MIPS.h"
    #include "MIUSEL_EMERALD_2MIU.h"
#elif ( MEMORY_MAP == MMAP_64_64MB )
    #include "MMAP_ATSCMM_EMERALD_64_64_MIPS.h"
    #include "MIUSEL_EMERALD_2MIU.h"
#elif (MEMORY_MAP == MMAP_128MB)
    #include "MMAP_ATSCMM_EMERALD_128_MIPS.h"
    #include "MIUSEL_EMERALD_MIU.h"
#elif (MEMORY_MAP == MMAP_64MB)
    #include "MMAP_ATSCMM_EMERALD_64_MIPS.h"
    #include "MIUSEL_EMERALD_MIU.h"
#else // ( MEMORY_MAP undefined )
    #error "Memory map undefined"
#endif

#else

#if defined(MIPS_CHAKRA)
 #if ( MEMORY_MAP == MMAP_256_256MB )
    #include "MMAP_DTVMM_EMERALD_256_256_MIPS.h"
    #include "MIUSEL_EMERALD_2MIU.h"
 #elif ( MEMORY_MAP == MMAP_128_128MB )
    #include "MMAP_DTVMM_EMERALD_128_128_MIPS.h"
    #include "MIUSEL_EMERALD_2MIU.h"
 #elif ( MEMORY_MAP == MMAP_64_64MB )
    #include "MMAP_DTVMM_EMERALD_64_64_MIPS.h"
    #include "MIUSEL_EMERALD_2MIU.h"
 #elif (MEMORY_MAP == MMAP_256MB)
    #include "MMAP_DTVMM_EMERALD_256_MIPS.h"
    #include "MIUSEL_EMERALD_MIU.h"
 #elif (MEMORY_MAP == MMAP_128MB)
  #if (MS_SW_CUS_SEL==SW_CONFIG_TRUNK_EMERALD_128M_DVBT_CI_PLUS)
    #include "MMAP_DTVMM_EMERALD_128_MIPS_CI.h"
  #elif (MS_SW_CUS_SEL==SW_CONFIG_TRUNK_EMERALD_128M_DVBT_CI_PLUS_T2)
    #include "MMAP_DTVMM_EMERALD_128_MIPS_CI_T2.h"
#elif (MS_SW_CUS_SEL==SW_CONFIG_TRUNK_EMERALD_128M_DVBS)
    #include "MMAP_DTVMM_EMERALD_128_MIPS_DVBS.h"    
  #else
    #include "MMAP_DTVMM_EMERALD_128_MIPS.h"
  #endif
    #include "MIUSEL_EMERALD_MIU.h"
 #elif (MEMORY_MAP == MMAP_64MB)
    #include "MMAP_DTVMM_EMERALD_64_MIPS.h"
    #include "MIUSEL_EMERALD_MIU.h"
 #else // ( MEMORY_MAP undefined )
    #error "Memory map undefined"
 #endif
#else
    #error "Memory map undefined"
#endif
#endif

//=================================================================================================
// Project system define
//=================================================================================================

#endif  // _SYSINFO_H_
