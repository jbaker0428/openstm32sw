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
 *  @file adc.h
 *
 *  @brief Analog-to-Digital Conversion (ADC) header.
 */

#ifndef _ADC_H_
#define _ADC_H_

#include "libmaple.h"
#include "bitband.h"
#include "rcc.h"

#ifdef __cplusplus
extern "C"{
#endif


#ifdef STM32F2
  typedef struct
  {
    __io uint32 CSR;    /*!< ADC Common status register,                  Address offset: ADC1 base address + 0x300 */
    __io uint32 CCR;    /*!< ADC common control register,                 Address offset: ADC1 base address + 0x304 */
    __io uint32 CDR;    /*!< ADC common regular data register for dual
                             AND triple modes,                            Address offset: ADC1 base address + 0x308 */
  } ADC_Common_TypeDef;
#define ADC_COMMON  ((ADC_Common_TypeDef *) 0x40012300)

#endif

/** ADC register map type. */
typedef struct adc_reg_map {
    __io uint32 SR;             ///< Status register
    __io uint32 CR1;            ///< Control register 1
    __io uint32 CR2;            ///< Control register 2
#ifdef STM32L1
    __io uint32 SMPR3;          ///< Sample time register 3
#endif
    __io uint32 SMPR1;          ///< Sample time register 1
    __io uint32 SMPR2;          ///< Sample time register 2
    __io uint32 JOFR1;          ///< Injected channel data offset register 1
    __io uint32 JOFR2;          ///< Injected channel data offset register 2
    __io uint32 JOFR3;          ///< Injected channel data offset register 3
    __io uint32 JOFR4;          ///< Injected channel data offset register 4
    __io uint32 HTR;            ///< Watchdog high threshold register
    __io uint32 LTR;            ///< Watchdog low threshold register
    __io uint32 SQR1;           ///< Regular sequence register 1
    __io uint32 SQR2;           ///< Regular sequence register 2
    __io uint32 SQR3;           ///< Regular sequence register 3
#ifdef STM32L1
    __io uint32 SQR4;           ///< Regular sequence register 4
    __io uint32 SQR5;           ///< Regular sequence register 5
#endif
    __io uint32 JSQR;           ///< Injected sequence register
    __io uint32 JDR1;           ///< Injected data register 1
    __io uint32 JDR2;           ///< Injected data register 2
    __io uint32 JDR3;           ///< Injected data register 3
    __io uint32 JDR4;           ///< Injected data register 4
    __io uint32 DR;             ///< Regular data register
#ifdef STM32L1
    __io uint32 CSR;            ///< Common status register
    __io uint32 CCR;            ///< Common control register
#endif
} adc_reg_map;

/** ADC device type. */
typedef struct adc_dev {
    adc_reg_map *regs; /**< Register map */
    rcc_clk_id clk_id; /**< RCC clock information */
} adc_dev;

extern const adc_dev *ADC1;
#ifndef STM32L1
extern const adc_dev *ADC2;
#endif
#ifdef STM32_HIGH_DENSITY
extern const adc_dev *ADC3;
#endif

/*
 * Register map base pointers
 */

#ifdef STM32F2
	/** ADC1 register map base pointer. */
	#define ADC1_BASE                       ((struct adc_reg_map*)0x40012000)
	/** ADC2 register map base pointer. */
	#define ADC2_BASE                       ((struct adc_reg_map*)0x40012100)
  /** ADC3 register map base pointer. */
  #define ADC3_BASE                       ((struct adc_reg_map*)0x40012200)
#elif defined(STM32L1)
	#define ADC1_BASE                       ((struct adc_reg_map*)0x40012400)
#else
	/** ADC1 register map base pointer. */
	#define ADC1_BASE                       ((struct adc_reg_map*)0x40012400)
	/** ADC2 register map base pointer. */
	#define ADC2_BASE                       ((struct adc_reg_map*)0x40012800)
	#ifdef STM32_HIGH_DENSITY
  	/** ADC3 register map base pointer. */
	  #define ADC3_BASE                       ((struct adc_reg_map*)0x40013C00)
  #endif
#endif

/*
 * Register bit definitions
 */

/* Status register */

#define ADC_SR_AWD_BIT                  0
#define ADC_SR_EOC_BIT                  1
#define ADC_SR_JEOC_BIT                 2
#define ADC_SR_JSTRT_BIT                3
#define ADC_SR_STRT_BIT                 4
#ifdef STM32L1
#define ADC_SR_OVR_BIT                  5
#define ADC_SR_ADONS_BIT                6
#define ADC_SR_RCNR_BIT                 8
#define ADC_SR_JCNR_BIT                 9
#endif

#define ADC_SR_AWD                      BIT(ADC_SR_AWD_BIT)
#define ADC_SR_EOC                      BIT(ADC_SR_EOC_BIT)
#define ADC_SR_JEOC                     BIT(ADC_SR_JEOC_BIT)
#define ADC_SR_JSTRT                    BIT(ADC_SR_JSTRT_BIT)
#define ADC_SR_STRT                     BIT(ADC_SR_STRT_BIT)
#ifdef STM32L1
#define ADC_SR_OVR                      BIT(ADC_SR_OVR_BIT)
#define ADC_SR_ADONS                    BIT(ADC_SR_ADONS_BIT)
#define ADC_SR_RCNR                     BIT(ADC_SR_RCNR_BIT)
#define ADC_SR_JCNR                     BIT(ADC_SR_JCNR_BIT)
#endif

/* Control register 1 */

#ifdef STM32L1
#define ADC_CR1_AWDCH_BIT               0
#define ADC_CR1_EOCIE_BIT               5
#define ADC_CR1_AWDIE_BIT               6
#define ADC_CR1_JEOCIE_BIT              7
#define ADC_CR1_SCAN_BIT                8
#define ADC_CR1_AWDSGL_BIT              9
#define ADC_CR1_JAUTO_BIT               10
#define ADC_CR1_DISCEN_BIT              11
#define ADC_CR1_JDISCEN_BIT             12
#define ADC_CR1_DISCNUM_BIT             13
#define ADC_CR1_PDD_BIT                 16
#define ADC_CR1_PDI_BIT                 17
#define ADC_CR1_JAWDEN_BIT              22
#define ADC_CR1_AWDEN_BIT               23
#define ADC_CR1_RES_BIT                 24
#define ADC_CR1_OVRIE_BIT               26

#define ADC_CR1_AWDCH                   (0x1F)
#define ADC_CR1_EOCIE                   BIT(ADC_CR1_EOCIE_BIT)
#define ADC_CR1_AWDIE                   BIT(ADC_CR1_AWDIE_BIT)
#define ADC_CR1_JEOCIE                  BIT(ADC_CR1_JEOCIE_BIT)
#define ADC_CR1_SCAN                    BIT(ADC_CR1_SCAN_BIT)
#define ADC_CR1_AWDSGL                  BIT(ADC_CR1_AWDSGL_BIT)
#define ADC_CR1_JAUTO                   BIT(ADC_CR1_JAUTO_BIT)
#define ADC_CR1_DISCEN                  BIT(ADC_CR1_DISCEN_BIT)
#define ADC_CR1_JDISCEN                 BIT(ADC_CR1_JDISCEN_BIT)
#define ADC_CR1_DISCNUM                 (0xE000)
#define ADC_CR1_PDD                     BIT(ADC_CR1_PDD_BIT)
#define ADC_CR1_PDI                     BIT(ADC_CR1_PDI_BIT)
#define ADC_CR1_JAWDEN                  BIT(ADC_CR1_JAWDEN_BIT)
#define ADC_CR1_AWDEN                   BIT(ADC_CR1_AWDEN_BIT)
#define ADC_CR1_RES                     (0x3 << 24)
#define ADC_CR1_OVRIE                   BIT(ADC_CR1_OVRIE_BIT)

#else	// STM32F*
#define ADC_CR1_EOCIE_BIT               5
#define ADC_CR1_AWDIE_BIT               6
#define ADC_CR1_JEOCIE_BIT              7
#define ADC_CR1_SCAN_BIT                8
#define ADC_CR1_AWDSGL_BIT              9
#define ADC_CR1_JAUTO_BIT               10
#define ADC_CR1_DISCEN_BIT              11
#define ADC_CR1_JDISCEN_BIT             12
#define ADC_CR1_JAWDEN_BIT              22
#define ADC_CR1_AWDEN_BIT               23

#define ADC_CR1_AWDCH                   (0x1F)
#define ADC_CR1_EOCIE                   BIT(ADC_CR1_EOCIE_BIT)
#define ADC_CR1_AWDIE                   BIT(ADC_CR1_AWDIE_BIT)
#define ADC_CR1_JEOCIE                  BIT(ADC_CR1_JEOCIE_BIT)
#define ADC_CR1_SCAN                    BIT(ADC_CR1_SCAN_BIT)
#define ADC_CR1_AWDSGL                  BIT(ADC_CR1_AWDSGL_BIT)
#define ADC_CR1_JAUTO                   BIT(ADC_CR1_JAUTO_BIT)
#define ADC_CR1_DISCEN                  BIT(ADC_CR1_DISCEN_BIT)
#define ADC_CR1_JDISCEN                 BIT(ADC_CR1_JDISCEN_BIT)
#define ADC_CR1_DISCNUM                 (0xE000)
#define ADC_CR1_JAWDEN                  BIT(ADC_CR1_JAWDEN_BIT)
#define ADC_CR1_AWDEN                   BIT(ADC_CR1_AWDEN_BIT)
#endif

/* Control register 2 */
#ifdef STM32L1
#define ADC_CR2_ADON_BIT                0
#define ADC_CR2_CONT_BIT                1
#define ADC_CR2_DELS_BIT                4
#define ADC_CR2_DMA_BIT                 8
#define ADC_CR2_DDS_BIT                 9
#define ADC_CR2_EOCS_BIT                10
#define ADC_CR2_ALIGN_BIT               11
#define ADC_CR2_JEXTSEL_BIT             16
#define ADC_CR2_JEXTEN_BIT              20
#define ADC_CR2_JSWSTART_BIT            22
#define ADC_CR2_EXTSEL_BIT              24
#define ADC_CR2_EXTEN_BIT               28
#define ADC_CR2_SWSTART_BIT             30

#define ADC_CR2_ADON                    BIT(ADC_CR2_ADON_BIT)
#define ADC_CR2_CONT                    BIT(ADC_CR2_CONT_BIT)
#define ADC_CR2_DELS					(0x7 << 4)
#define ADC_CR2_DMA                     BIT(ADC_CR2_DMA_BIT)
#define ADC_CR2_DDS                     BIT(ADC_CR2_DDS_BIT)
#define ADC_CR2_EOCS                    BIT(ADC_CR2_EOCS_BIT)
#define ADC_CR2_ALIGN                   BIT(ADC_CR2_ALIGN_BIT)
#define ADC_CR2_JEXTSEL                 (0xF << 16)
#define ADC_CR2_JEXTEN                  (0x3 << 20)
#define ADC_CR2_JSWSTART                BIT(ADC_CR2_JSWSTART_BIT)
#define ADC_CR2_EXTSEL                  (0xF << 24)
#define ADC_CR2_EXTEN                   (0x3 << 28)
#define ADC_CR2_SWSTART                 BIT(ADC_CR2_SWSTART_BIT)

#else	// STM32F*
#define ADC_CR2_ADON_BIT                0
#define ADC_CR2_CONT_BIT                1
#define ADC_CR2_CAL_BIT                 2
#define ADC_CR2_RSTCAL_BIT              3
#define ADC_CR2_DMA_BIT                 8
#define ADC_CR2_ALIGN_BIT               11
#define ADC_CR2_JEXTTRIG_BIT            15
#define ADC_CR2_EXTTRIG_BIT             20
#define ADC_CR2_TSEREFE_BIT             23
#ifdef STM32F2
	#define ADC_CR2_JSWSTART_BIT            22
	#define ADC_CR2_SWSTART_BIT             30
	#define ADC_CR2_EXTSEL                  (0x0F000000)
	#define ADC_CR2_JEXTSEL                 (0x000F0000)
#else
	#define ADC_CR2_JSWSTART_BIT            21
	#define ADC_CR2_SWSTART_BIT             22
	#define ADC_CR2_EXTSEL                  (0x000E0000)
	#define ADC_CR2_JEXTSEL                 (0x00007000)
#endif

#define ADC_CR2_ADON                    BIT(ADC_CR2_ADON_BIT)
#define ADC_CR2_CONT                    BIT(ADC_CR2_CONT_BIT)
#define ADC_CR2_CAL                     BIT(ADC_CR2_CAL_BIT)
#define ADC_CR2_RSTCAL                  BIT(ADC_CR2_RSTCAL_BIT)
#define ADC_CR2_DMA                     BIT(ADC_CR2_DMA_BIT)
#define ADC_CR2_ALIGN                   BIT(ADC_CR2_ALIGN_BIT)
#define ADC_CR2_JEXTTRIG                BIT(ADC_CR2_JEXTTRIG_BIT)
#define ADC_CR2_EXTTRIG                 BIT(ADC_CR2_EXTTRIG_BIT)
#define ADC_CR2_JSWSTART                BIT(ADC_CR2_JSWSTART_BIT)
#define ADC_CR2_SWSTART                 BIT(ADC_CR2_SWSTART_BIT)
#define ADC_CR2_TSEREFE                 BIT(ADC_CR2_TSEREFE_BIT)
#endif

/* Sample time registers */
#ifdef STM32L1
/* Sample time register 1 */

#define ADC_SMPR1_SMP25                 (0x7 << 15)
#define ADC_SMPR1_SMP24                 (0x7 << 12)
#define ADC_SMPR1_SMP23                 (0x7 << 9)
#define ADC_SMPR1_SMP22                 (0x7 << 6)
#define ADC_SMPR1_SMP21                 (0x7 << 3)
#define ADC_SMPR1_SMP20                 0x7

/* Sample time register 2 */

#define ADC_SMPR2_SMP19                  (0x7 << 27)
#define ADC_SMPR2_SMP18                  (0x7 << 24)
#define ADC_SMPR2_SMP17                  (0x7 << 21)
#define ADC_SMPR2_SMP16                  (0x7 << 18)
#define ADC_SMPR2_SMP15                  (0x7 << 15)
#define ADC_SMPR2_SMP14                  (0x7 << 12)
#define ADC_SMPR2_SMP13                  (0x7 << 9)
#define ADC_SMPR2_SMP12                  (0x7 << 6)
#define ADC_SMPR2_SMP11                  (0x7 << 3)
#define ADC_SMPR2_SMP10                  0x7

/* Sample time register 3 */

#define ADC_SMPR3_SMP9                  (0x7 << 27)
#define ADC_SMPR3_SMP8                  (0x7 << 24)
#define ADC_SMPR3_SMP7                  (0x7 << 21)
#define ADC_SMPR3_SMP6                  (0x7 << 18)
#define ADC_SMPR3_SMP5                  (0x7 << 15)
#define ADC_SMPR3_SMP4                  (0x7 << 12)
#define ADC_SMPR3_SMP3                  (0x7 << 9)
#define ADC_SMPR3_SMP2                  (0x7 << 6)
#define ADC_SMPR3_SMP1                  (0x7 << 3)
#define ADC_SMPR3_SMP0                  0x7

#else	// STM32F*
/* Sample time register 1 */

#define ADC_SMPR1_SMP17                 (0x7 << 21)
#define ADC_SMPR1_SMP16                 (0x7 << 18)
#define ADC_SMPR1_SMP15                 (0x7 << 15)
#define ADC_SMPR1_SMP14                 (0x7 << 12)
#define ADC_SMPR1_SMP13                 (0x7 << 9)
#define ADC_SMPR1_SMP12                 (0x7 << 6)
#define ADC_SMPR1_SMP11                 (0x7 << 3)
#define ADC_SMPR1_SMP10                 0x7

/* Sample time register 2 */

#define ADC_SMPR2_SMP9                  (0x7 << 27)
#define ADC_SMPR2_SMP8                  (0x7 << 24)
#define ADC_SMPR2_SMP7                  (0x7 << 21)
#define ADC_SMPR2_SMP6                  (0x7 << 18)
#define ADC_SMPR2_SMP5                  (0x7 << 15)
#define ADC_SMPR2_SMP4                  (0x7 << 12)
#define ADC_SMPR2_SMP3                  (0x7 << 9)
#define ADC_SMPR2_SMP2                  (0x7 << 6)
#define ADC_SMPR2_SMP1                  (0x7 << 3)
#define ADC_SMPR2_SMP0                  0x7

#endif

/* Injected channel data offset register */

#define ADC_JOFR_JOFFSET                0x3FF

/* Watchdog high threshold register */

#define ADC_HTR_HT                      0x3FF

/* Watchdog low threshold register */

#define ADC_LTR_LT                      0x3FF

/* Regular sequence registers */
#ifdef STM32L1
/* Regular sequence register 1 */

#define ADC_SQR1_L                      (0x1F << 20)
#define ADC_SQR1_SQ27                   (0x1F << 10)
#define ADC_SQR1_SQ26                   (0x1F << 5)
#define ADC_SQR1_SQ25                   0x1F

/* Regular sequence register 2 */

#define ADC_SQR2_SQ24                   (0x1F << 25)
#define ADC_SQR2_SQ23                   (0x1F << 20)
#define ADC_SQR2_SQ22                   (0x1F << 16)
#define ADC_SQR2_SQ21                   (0x1F << 10)
#define ADC_SQR2_SQ20                   (0x1F << 5)
#define ADC_SQR2_SQ19                   0x1F

/* Regular sequence register 3 */

#define ADC_SQR3_SQ18                   (0x1F << 25)
#define ADC_SQR3_SQ17                   (0x1F << 20)
#define ADC_SQR3_SQ16                   (0x1F << 16)
#define ADC_SQR3_SQ15                   (0x1F << 10)
#define ADC_SQR3_SQ14                   (0x1F << 5)
#define ADC_SQR3_SQ13                    0x1F

/* Regular sequence register 4 */

#define ADC_SQR4_SQ12                   (0x1F << 25)
#define ADC_SQR4_SQ11                   (0x1F << 20)
#define ADC_SQR4_SQ10                   (0x1F << 16)
#define ADC_SQR4_SQ9                    (0x1F << 10)
#define ADC_SQR4_SQ8                    (0x1F << 5)
#define ADC_SQR4_SQ7                    0x1F

/* Regular sequence register 5 */

#define ADC_SQR5_SQ6                    (0x1F << 25)
#define ADC_SQR5_SQ5                    (0x1F << 20)
#define ADC_SQR5_SQ4                    (0x1F << 16)
#define ADC_SQR5_SQ3                    (0x1F << 10)
#define ADC_SQR5_SQ2                    (0x1F << 5)
#define ADC_SQR5_SQ1                    0x1F

#else	// STM32F*
/* Regular sequence register 1 */

#define ADC_SQR1_L                      (0x1F << 20)
#define ADC_SQR1_SQ16                   (0x1F << 15)
#define ADC_SQR1_SQ15                   (0x1F << 10)
#define ADC_SQR1_SQ14                   (0x1F << 5)
#define ADC_SQR1_SQ13                   0x1F

/* Regular sequence register 2 */

#define ADC_SQR2_SQ12                   (0x1F << 25)
#define ADC_SQR2_SQ11                   (0x1F << 20)
#define ADC_SQR2_SQ10                   (0x1F << 16)
#define ADC_SQR2_SQ9                    (0x1F << 10)
#define ADC_SQR2_SQ8                    (0x1F << 5)
#define ADC_SQR2_SQ7                    0x1F

/* Regular sequence register 3 */

#define ADC_SQR3_SQ6                    (0x1F << 25)
#define ADC_SQR3_SQ5                    (0x1F << 20)
#define ADC_SQR3_SQ4                    (0x1F << 16)
#define ADC_SQR3_SQ3                    (0x1F << 10)
#define ADC_SQR3_SQ2                    (0x1F << 5)
#define ADC_SQR3_SQ1                    0x1F

#endif

/* Injected sequence register */

#define ADC_JSQR_JL                     (0x3 << 20)
#define ADC_JSQR_JL_1CONV               (0x0 << 20)
#define ADC_JSQR_JL_2CONV               (0x1 << 20)
#define ADC_JSQR_JL_3CONV               (0x2 << 20)
#define ADC_JSQR_JL_4CONV               (0x3 << 20)
#define ADC_JSQR_JSQ4                   (0x1F << 15)
#define ADC_JSQR_JSQ3                   (0x1F << 10)
#define ADC_JSQR_JSQ2                   (0x1F << 5)
#define ADC_JSQR_JSQ1                   0x1F

/* Injected data registers */

#define ADC_JDR_JDATA                   0xFFFF

/* Regular data register */

#define ADC_DR_ADC2DATA                 (0xFFFF << 16)
#define ADC_DR_DATA                     0xFFFF

#ifdef STM32L1
/* Common status register */

#define ADC_CSR_AWD1_BIT                0
#define ADC_CSR_EOC1_BIT                1
#define ADC_CSR_JEOC1_BIT               2
#define ADC_CSR_JSTRT1_BIT              3
#define ADC_CSR_STRT1_BIT               4
#define ADC_CSR_OVR1_BIT                5
#define ADC_CSR_ADONS1_BIT              6

#define ADC_CSR_AWD1                    BIT(ADC_CSR_AWD1_BIT)
#define ADC_CSR_EOC1                    BIT(ADC_CSR_EOC1_BIT)
#define ADC_CSR_JEOC1                   BIT(ADC_CSR_JEOC1_BIT)
#define ADC_CSR_JSTRT1                  BIT(ADC_CSR_JSTRT1_BIT)
#define ADC_CSR_STRT1                   BIT(ADC_CSR_STRT1_BIT)
#define ADC_CSR_OVR1                    BIT(ADC_CSR_OVR1_BIT)
#define ADC_CSR_ADONS1                  BIT(ADC_CSR_ADONS1_BIT)

/* Common control register */
#define ADC_CCR_TSVREFE_BIT             23
#endif

void adc_init(const adc_dev *dev);

/**
 * @brief External event selector for regular group conversion.
 * @see adc_set_extsel
 */
#ifdef STM32L1
typedef enum adc_extsel_event {
    ADC_ADC12_TIM9_CC2  = (0 << 24), /**< ADC: Timer 9 CC2 event */
    ADC_ADC12_TIM9_TRGO = (1 << 24), /**< ADC: Timer 9 TRGO event */
    ADC_ADC12_TIM2_CC3  = (2 << 24), /**< ADC: Timer 2 CC3 event */
    ADC_ADC12_TIM2_CC2  = (3 << 24), /**< ADC: Timer 2 CC2 event */
    ADC_ADC12_TIM4_CC4  = (4 << 24), /**< ADC: Timer 4 CC4 event */
    ADC_ADC12_TIM2_TRGO = (5 << 24), /**< ADC: Timer 2 TRGO event */
    ADC_ADC12_TIM3_CC1  = (6 << 24), /**< ADC: Timer 3 CC1 event */
    ADC_ADC12_TIM3_CC3  = (7 << 24), /**< ADC: Timer 3 CC3 event */
    ADC_ADC12_TIM4_TRGO = (8 << 24), /**< ADC: Timer 4 TRGO event */
    ADC_ADC12_TIM6_TRGO = (9 << 24), /**< ADC: Timer 6 TRGO event */
    ADC_ADC12_EXTI11    = (0xF << 24), /**< ADC: EXTI 11 event */
} adc_extsel_event;

#else	// STM32F*
typedef enum adc_extsel_event {
    ADC_ADC12_TIM1_CC1  = (0 << 17), /**< ADC1 and ADC2: Timer 1 CC1 event */
    ADC_ADC12_TIM1_CC2  = (1 << 17), /**< ADC1 and ADC2: Timer 1 CC2 event */
    ADC_ADC12_TIM1_CC3  = (2 << 17), /**< ADC1 and ADC2: Timer 1 CC3 event */
    ADC_ADC12_TIM2_CC2  = (3 << 17), /**< ADC1 and ADC2: Timer 2 CC2 event */
    ADC_ADC12_TIM3_TRGO = (4 << 17), /**< ADC1 and ADC2: Timer 3 TRGO event */
    ADC_ADC12_TIM4_CC4  = (5 << 17), /**< ADC1 and ADC2: Timer 4 CC4 event */
    ADC_ADC12_EXTI11    = (6 << 17), /**< ADC1 and ADC2: EXTI11 event */
#ifdef STM32_HIGH_DENSITY
    ADC_ADC12_TIM8_TRGO = (6 << 17), /**< ADC1 and ADC2: Timer 8 TRGO
                                        event (high density only) */
#endif
    ADC_ADC12_SWSTART   = (7 << 17), /**< ADC1 and ADC2: Software start */
#ifdef STM32_HIGH_DENSITY
    ADC_ADC3_TIM3_CC1   = (0 << 17), /**< ADC3: Timer 3 CC1 event
                                        (high density only) */
    ADC_ADC3_TIM2_CC3   = (1 << 17), /**< ADC3: Timer 2 CC3 event
                                        (high density only) */
    ADC_ADC3_TIM1_CC3   = (2 << 17), /**< ADC3: Timer 1 CC3 event
                                        (high density only) */
    ADC_ADC3_TIM8_CC1   = (3 << 17), /**< ADC3: Timer 8 CC1 event
                                        (high density only) */
    ADC_ADC3_TIM8_TRGO  = (4 << 17), /**< ADC3: Timer 8 TRGO event
                                        (high density only) */
    ADC_ADC3_TIM5_CC1   = (5 << 17), /**< ADC3: Timer 5 CC1 event
                                        (high density only) */
    ADC_ADC3_TIM5_CC3   = (6 << 17), /**< ADC3: Timer 5 CC3 event
                                        (high density only) */
    ADC_ADC3_SWSTART    = (7 << 17), /**< ADC3: Software start (high
                                        density only) */
#endif
    ADC_SWSTART         = (7 << 17) /**< ADC1, ADC2, ADC3: Software start */
} adc_extsel_event;
#endif

void adc_set_extsel(const adc_dev *dev, adc_extsel_event event);
void adc_foreach(void (*fn)(const adc_dev*));

/**
 * @brief ADC sample times, in ADC clock cycles
 *
 * These control the amount of time spent sampling the input voltage.
 */
typedef enum {
    ADC_SMPR_1_5,               /**< 1.5 ADC cycles */
    ADC_SMPR_7_5,               /**< 7.5 ADC cycles */
    ADC_SMPR_13_5,              /**< 13.5 ADC cycles */
    ADC_SMPR_28_5,              /**< 28.5 ADC cycles */
    ADC_SMPR_41_5,              /**< 41.5 ADC cycles */
    ADC_SMPR_55_5,              /**< 55.5 ADC cycles */
    ADC_SMPR_71_5,              /**< 71.5 ADC cycles */
    ADC_SMPR_239_5              /**< 239.5 ADC cycles */
} adc_smp_rate;

void adc_set_sample_rate(const adc_dev *dev, adc_smp_rate smp_rate);
void adc_calibrate(const adc_dev *dev);
uint16 adc_read(const adc_dev *dev, uint8 channel);

/**
 * @brief Set the regular channel sequence length.
 *
 * Defines the total number of conversions in the regular channel
 * conversion sequence.
 *
 * @param dev ADC device.
 * @param length Regular channel sequence length, from 1 to 16.
 */
static inline void adc_set_reg_seqlen(const adc_dev *dev, uint8 length) {
    uint32 tmp = dev->regs->SQR1;
    tmp &= ~ADC_SQR1_L;
    tmp |= (length - 1) << 20;
    dev->regs->SQR1 = tmp;
}

/**
 * @brief Set external trigger conversion mode event for regular channels
 * @param dev    ADC device
 * @param enable If 1, conversion on external events is enabled; if 0,
 *               disabled.
 */
static inline void adc_set_exttrig(const adc_dev *dev, uint8 enable) {
    *bb_perip(&dev->regs->CR2, ADC_CR2_EXTTRIG_BIT) = !!enable;
}

/**
 * @brief Enable an adc peripheral
 * @param dev ADC device to enable
 */
static inline void adc_enable(const adc_dev *dev) {
    *bb_perip(&dev->regs->CR2, ADC_CR2_ADON_BIT) = 1;
}

/**
 * @brief Disable an ADC peripheral
 * @param dev ADC device to disable
 */
static inline void adc_disable(const adc_dev *dev) {
    *bb_perip(&dev->regs->CR2, ADC_CR2_ADON_BIT) = 0;
}

/**
 * @brief Disable all ADC peripherals.
 */
static inline void adc_disable_all(void) {
    adc_foreach(adc_disable);
}

void setupADC_F2();

#ifdef __cplusplus
} // extern "C"
#endif

#endif
