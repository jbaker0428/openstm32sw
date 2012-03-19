/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2010 LeafLabs, LLC.
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
 * @file pwr.h
 * @brief Power control (PWR) defines.
 */

#include "libmaple.h"

#ifdef __cplusplus
extern "C" {
#endif

/** Power interface register map. */
typedef struct pwr_reg_map {
    __io uint32 CR;      /**< Control register */
    __io uint32 CSR;     /**< Control and status register */
} pwr_reg_map;

/** Power peripheral register map base pointer. */
#define PWR_BASE                        ((struct pwr_reg_map*)0x40007000)

/*
 * Register bit definitions
 */

/* Control register */

#ifdef STM32L1
#define PWR_CR_LPRUN_BIT			14	/** Low power run mode */
#define PWR_CR_VOS_BIT				11	/** Voltage scaling range selection */
#define PWR_CR_FWU_BIT				10	/** Fast wakeup */
#define PWR_CR_ULP_BIT				9	/** Ultralow power mode */
#endif
/** Disable backup domain write protection bit */
#define PWR_CR_DBP_BIT  			8
/** Power voltage detector level selection bit */
#define PWR_CR_PLS_BIT				5
/** Power voltage detector enable bit */
#define PWR_CR_PVDE_BIT 			4
/** Clear standby flag bit */
#define PWR_CR_CSBF_BIT 			3
/** Clear wakeup flag bit */
#define PWR_CR_CWUF_BIT 			2
/** Power down deepsleep bit */
#define PWR_CR_PDDS_BIT 			1
/** Low-power deepsleep bit */
#define PWR_CR_LPDS_BIT				0

#ifdef STM32L1
#define PWR_CR_LPRUN				BIT(PWR_CR_LPRUN_BIT)
#define PWR_CR_VOS					BIT(PWR_CR_VOS_BIT)
#define PWR_CR_FWU					BIT(PWR_CR_FWU_BIT)
#define PWR_CR_ULP					BIT(PWR_CR_ULP_BIT)
#endif
#define PWR_CR_DBP  				BIT(PWR_CR_DBP_BIT)
#define PWR_CR_PLS					(0x7 << PWR_CR_PLS_BIT)
#define PWR_CR_PVDE 				BIT(PWR_CR_PVDE_BIT)
#define PWR_CR_CSBF 				BIT(PWR_CR_CSBF_BIT)
#define PWR_CR_CWUF 				BIT(PWR_CR_CWUF_BIT)
#define PWR_CR_PDDS 				BIT(PWR_CR_PDDS_BIT)
#define PWR_CR_LPDS					BIT(PWR_CR_LPDS_BIT)

/* Control and status register */
#ifdef STM32L1
/** Enable wakeup pin 3 bit */
#define PWR_CSR_EWUP1_BIT			10
/** Enable wakeup pin 2 bit */
#define PWR_CSR_EWUP2_BIT			9
/** Enable wakeup pin 1 bit */
#define PWR_CSR_EWUP1_BIT			8
#else
/** Enable wakeup pin bit */
#define PWR_CSR_EWUP_BIT			8
#endif
#ifdef STM32L1
/** Regulator LP flag bit */
#define PWR_CSR_REGLPF_BIT			5
/** Voltage Scaling select flag bit */
#define PWR_CSR_VOSF_BIT			4
/** Internal voltage reference (V_REFINT) ready flag bit */
#define PWR_CSR_VREFINTRDYF_BIT		3
#endif
/** PVD output bit */
#define PWR_CSR_PVDO_BIT			2
/** Standby flag bit */
#define PWR_CSR_SBF_BIT				1
/** Wakeup flag bit */
#define PWR_CSR_WUF_BIT				0

#ifdef STM32L1
#define PWR_CSR_EWUP1				BIT(PWR_CSR_EWUP1_BIT)
#define PWR_CSR_EWUP2				BIT(PWR_CSR_EWUP2_BIT)
#define PWR_CSR_EWUP1				BIT(PWR_CSR_EWUP1_BIT)
#else
/** Enable wakeup pin bit */
#define PWR_CSR_EWUP				BIT(PWR_CSR_EWUP_BIT)
#endif
#ifdef STM32L1
#define PWR_CSR_REGLPF				BIT(PWR_CSR_REGLPF_BIT)
#define PWR_CSR_VOSF				BIT(PWR_CSR_VOSF_BIT)
#define PWR_CSR_VREFINTRDYF			BIT(PWR_CSR_VREFINTRDYF_BIT)
#endif
#define PWR_CSR_PVDO				BIT(PWR_CSR_EWUP_BIT)
#define PWR_CSR_SBF					BIT(PWR_CSR_EWUP_BIT)
#define PWR_CSR_WUF					BIT(PWR_CSR_EWUP_BIT)

/*
 * Convenience functions
 */

void pwr_init(void);

#ifdef __cplusplus
}
#endif
