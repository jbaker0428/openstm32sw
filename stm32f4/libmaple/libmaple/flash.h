/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2010 Perry Hung.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *****************************************************************************/

/**
 * @file flash.h
 * @brief STM32F Medium and high density and STM32L Flash register map and setup
 * routines
 */

#include "libmaple_types.h"

#ifndef _FLASH_H_
#define _FLASH_H_

#ifdef __cplusplus
extern "C"{
#endif

/** Flash register map type */
#ifndef STM32L1
typedef struct flash_reg_map {
    __io uint32 ACR;            /**< Access control register */
    __io uint32 KEYR;           /**< Key register */
    __io uint32 OPTKEYR;        /**< OPTKEY register */
    __io uint32 SR;             /**< Status register */
    __io uint32 CR;             /**< Control register */
    __io uint32 AR;             /**< Address register */
    __io uint32 OBR;            /**< Option byte register */
    __io uint32 WRPR;           /**< Write protection register */
} flash_reg_map;
#else
typedef struct flash_reg_map {
    __io uint32 ACR;            /**< Access control register */
    __io uint32 PECR;
    __io uint32 PDKEYR;           /**< Key register */
    __io uint32 PEKEYR;           /**< Key register */
    __io uint32 PRGKEYR;           /**< Key register */
    __io uint32 OPTKEYR;        /**< OPTKEY register */
    __io uint32 SR;             /**< Status register */
    __io uint32 CR;             /**< Control register */
    __io uint32 AR;             /**< Address register */
    __io uint32 OBR;            /**< Option byte register */
    __io uint32 WRPR;           /**< Write protection register */
} flash_reg_map;
#endif

/** Flash register map base pointer */
#ifndef STM32L1
#define FLASH_BASE                      ((struct flash_reg_map*)0x40022000)
#else
#define FLASH_BASE                      ((struct flash_reg_map*)0x40023C00)
#endif

/*
 * Register bit definitions
 */

/* Access control register */
#ifndef STM32L1
#define FLASH_ACR_PRFTBS_BIT            5
#define FLASH_ACR_PRFTBE_BIT            4
#define FLASH_ACR_HLFCYA_BIT            3

#define FLASH_ACR_PRFTBS                BIT(FLASH_ACR_PRFTBS_BIT)
#define FLASH_ACR_PRFTBE                BIT(FLASH_ACR_PRFTBE_BIT)
#define FLASH_ACR_HLFCYA                BIT(FLASH_ACR_HLFCYA_BIT)

#else
#define FLASH_ACR_RUN_PD_BIT            4
#define FLASH_ACR_SLEEP_PD_BIT          3
#define FLASH_ACR_ACC64_PD_BIT          2
#define FLASH_ACR_PRFTEN_BIT      	    1

#define FLASH_ACR_RUN_PD                BIT(FLASH_ACR_RUN_PD_BIT)
#define FLASH_ACR_SLEEP_PD              BIT(FLASH_ACR_SLEEP_PD_BIT)
#define FLASH_ACR_ACC64_PD              BIT(FLASH_ACR_ACC64_PD_BIT)
#define FLASH_ACR_PRFTEN	          	BIT(FLASH_ACR_PRFTEN_BIT)
#endif
#define FLASH_ACR_LATENCY               0x7

#ifdef STM32L1
/** Program/erase control register */
#define FLASH_PECR_OBL_LAUNCH_BIT		18
#define FLASH_PECR_ERRIE_BIT			17
#define FLASH_PECR_EOPIE_BIT			16
#define FLASH_PECR_FPRG_BIT				10
#define FLASH_PECR_ERASE_BIT			9
#define FLASH_PECR_FTDW_BIT				8
#define FLASH_PECR_DATA_BIT				4
#define FLASH_PECR_PROG_BIT				3
#define FLASH_PECR_OPTLOCK_BIT			2
#define FLASH_PECR_PROGLOCK_BIT			1
#define FLASH_PECR_PELOCK_BIT			0

#define FLASH_PECR_OBL_LAUNCH			BIT(FLASH_PECR_OBL_LAUNCH_BIT)
#define FLASH_PECR_ERRIE				BIT(FLASH_PECR_ERRIE_BIT)
#define FLASH_PECR_EOPIE				BIT(FLASH_PECR_EOPIE_BIT)
#define FLASH_PECR_FPRG					BIT(FLASH_PECR_FPRG_BIT	)
#define FLASH_PECR_ERASE				BIT(FLASH_PECR_ERASE_BIT)
#define FLASH_PECR_FTDW					BIT(FLASH_PECR_FTDW_BIT)
#define FLASH_PECR_DATA					BIT(FLASH_PECR_DATA_BIT)
#define FLASH_PECR_PROG					BIT(FLASH_PECR_PROG_BIT)
#define FLASH_PECR_OPTLOCK				BIT(FLASH_PECR_OPTLOCK_BIT)
#define FLASH_PECR_PROGLOCK				BIT(FLASH_PECR_PROGLOCK_BIT)
#define FLASH_PECR_PELOCK				BIT(FLASH_PECR_PELOCK_BIT)
#endif

/* Status register */
#ifndef STM32L1
#define FLASH_SR_EOP_BIT                5
#define FLASH_SR_WRPRTERR_BIT           4
#define FLASH_SR_PGERR_BIT              2
#define FLASH_SR_BSY_BIT                0

#define FLASH_SR_EOP                    BIT(FLASH_SR_EOP_BIT)
#define FLASH_SR_WRPRTERR               BIT(FLASH_SR_WRPRTERR_BIT)
#define FLASH_SR_PGERR                  BIT(FLASH_SR_PGERR_BIT)
#define FLASH_SR_BSY                    BIT(FLASH_SR_BSY_BIT)

#else
#define FLASH_SR_OPTVERR_BIT			11
#define FLASH_SR_SIZERR_BIT				10
#define FLASH_SR_PGAERR_BIT				9
#define FLASH_SR_WRPERR_BIT				8
#define FLASH_SR_READY_BIT				3
#define FLASH_SR_ENDHV_BIT				2
#define FLASH_SR_EOP_BIT				1
#define FLASH_SR_BSY_BIT				0

#define FLASH_SR_OPTVERR				BIT(FLASH_SR_OPTVERR_BIT)
#define FLASH_SR_SIZERR					BIT(FLASH_SR_SIZERR_BIT)
#define FLASH_SR_PGAERR					BIT(FLASH_SR_PGAER_BIT)
#define FLASH_SR_WRPERR					BIT(FLASH_SR_WRPERR_BIT)
#define FLASH_SR_READY					BIT(FLASH_SR_READY_BIT)
#define FLASH_SR_ENDHV					BIT(FLASH_SR_ENDHV_BIT)
#define FLASH_SR_EOP					BIT(FLASH_SR_EOP_BIT)
#define FLASH_SR_BSY					BIT(FLASH_SR_BSY_BIT)
#endif

#ifndef STM32L1
/* Control register */

#define FLASH_CR_EOPIE_BIT              12
#define FLASH_CR_ERRIE_BIT              10
#define FLASH_CR_OPTWRE_BIT             9
#define FLASH_CR_LOCK_BIT               7
#define FLASH_CR_STRT_BIT               6
#define FLASH_CR_OPTER_BIT              5
#define FLASH_CR_OPTPG_BIT              4
#define FLASH_CR_MER_BIT                2
#define FLASH_CR_PER_BIT                1
#define FLASH_CR_PG_BIT                 0

#define FLASH_CR_EOPIE                  BIT(FLASH_CR_EOPIE_BIT)
#define FLASH_CR_ERRIE                  BIT(FLASH_CR_ERRIE_BIT)
#define FLASH_CR_OPTWRE                 BIT(FLASH_CR_OPTWRE_BIT)
#define FLASH_CR_LOCK                   BIT(FLASH_CR_LOCK_BIT)
#define FLASH_CR_STRT                   BIT(FLASH_CR_STRT_BIT)
#define FLASH_CR_OPTER                  BIT(FLASH_CR_OPTER_BIT)
#define FLASH_CR_OPTPG                  BIT(FLASH_CR_OPTPG_BIT)
#define FLASH_CR_MER                    BIT(FLASH_CR_MER_BIT)
#define FLASH_CR_PER                    BIT(FLASH_CR_PER_BIT)
#define FLASH_CR_PG                     BIT(FLASH_CR_PG_BIT)

#endif

/* Option byte register */

#ifndef STM32L1
#define FLASH_OBR_nRST_STDBY_BIT        4
#define FLASH_OBR_nRST_STOP_BIT         3
#define FLASH_OBR_WDG_SW_BIT            2
#define FLASH_OBR_RDPRT_BIT             1
#define FLASH_OBR_OPTERR_BIT            0

#define FLASH_OBR_DATA1                 (0xFF << 18)
#define FLASH_OBR_DATA0                 (0xFF << 10)
#define FLASH_OBR_USER                  0x3FF
#define FLASH_OBR_nRST_STDBY            BIT(FLASH_OBR_nRST_STDBY_BIT)
#define FLASH_OBR_nRST_STOP             BIT(FLASH_OBR_nRST_STOP_BIT)
#define FLASH_OBR_WDG_SW                BIT(FLASH_OBR_WDG_SW_BIT)
#define FLASH_OBR_RDPRT                 BIT(FLASH_OBR_RDPRT_BIT)
#define FLASH_OBR_OPTERR                BIT(FLASH_OBR_OPTERR_BIT)

#else
#define FLASH_OBR_nRST_STDBY_BIT        22
#define FLASH_OBR_nRST_STOP_BIT         21
#define FLASH_OBR_IWDG_SW_BIT           20
#define FLASH_OBR_BOR_LEV_BIT			16
#define FLASH_OBR_RDPRT_BIT             0

#define FLASH_OBR_nRST_STDBY	        BIT(FLASH_OBR_nRST_STDBY_BIT)
#define FLASH_OBR_nRST_STOP     	    BIT(FLASH_OBR_nRST_STOP_BIT)
#define FLASH_OBR_IWDG_SW      	    	BIT(FLASH_OBR_IWDG_SW_BIT)
#define FLASH_OBR_BOR_LEV				BIT(FLASH_OBR_BOR_LEV_BIT)
#define FLASH_OBR_RDPRT_BIT             (0xFF)
#endif

/*
 * Setup routines
 */

#define FLASH_WAIT_STATE_0              0x0
#define FLASH_WAIT_STATE_1              0x1
#ifndef STM32L1
#define FLASH_WAIT_STATE_2              0x2
#endif

void flash_enable_prefetch(void);
void flash_set_latency(uint32 wait_states);

#ifdef __cplusplus
}
#endif

#endif


