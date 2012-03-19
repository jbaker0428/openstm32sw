/*
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
 *  @file gpio.h
 *
 *  @brief General purpose I/O (GPIO) and Alternate Function I/O
 *         (AFIO) prototypes, defines, and inlined access functions.
 */

#ifndef _GPIO_H_
#define _GPIO_H_

#include "libmaple.h"
#include "rcc.h"

#ifdef __cplusplus
extern "C"{
#endif

/*
 * GPIO register maps and devices
 */

/** GPIO register map type */
typedef struct gpio_reg_map {
	__io uint32 MODER;	  /**< Port mode register */
	__io uint32 OTYPER;	  /**< Port output type register */
	__io uint32 OSPEEDR;  /**< Port output speed register */
	__io uint32 PUPDR;    /**< Port pupp-up/pull-down register */
	__io uint32 IDR;      /**< Port input data register */
	__io uint32 ODR;      /**< Port output data register */
	__io uint32 BSRR;     /**< Port bit set/reset register */
	__io uint32 LCKR;     /**< Port configuration lock register */
	__io uint32 AFRL;     /**< Port alternate function low register */
	__io uint32 AFRH;     /**< Port alternate function high register */
} gpio_reg_map;

/** GPIO device type */
typedef struct gpio_dev {
    gpio_reg_map *regs;       /**< Register map */
    rcc_clk_id clk_id;        /**< RCC clock information */
} gpio_dev;

extern gpio_dev gpioa;
extern gpio_dev* const GPIOA;
extern gpio_dev gpiob;
extern gpio_dev* const GPIOB;
extern gpio_dev gpioc;
extern gpio_dev* const GPIOC;
extern gpio_dev gpiod;
extern gpio_dev* const GPIOD;
extern gpio_dev gpioe;
extern gpio_dev* const GPIOE;
extern gpio_dev gpioh;
extern gpio_dev* const GPIOH;

/** GPIO port A register map base pointer */
#define GPIOA_BASE                      ((struct gpio_reg_map*)0x40020000)
/** GPIO port B register map base pointer */
#define GPIOB_BASE                      ((struct gpio_reg_map*)0x40020400)
/** GPIO port C register map base pointer */
#define GPIOC_BASE                      ((struct gpio_reg_map*)0x40020800)
/** GPIO port D register map base pointer */
#define GPIOD_BASE                      ((struct gpio_reg_map*)0x40020C00)
/** GPIO port E register map base pointer */
#define GPIOE_BASE                      ((struct gpio_reg_map*)0x40021000)
/** GPIO port H register map base pointer */
#define GPIOH_BASE                      ((struct gpio_reg_map*)0x40021400)

/*
 * GPIO register bit definitions
 */

/* Mode register */
#define GPIO_MODER_15_BIT				30
#define GPIO_MODER_14_BIT				28
#define GPIO_MODER_13_BIT				26
#define GPIO_MODER_12_BIT				24
#define GPIO_MODER_11_BIT				22
#define GPIO_MODER_10_BIT				20
#define GPIO_MODER_9_BIT				18
#define GPIO_MODER_8_BIT				16
#define GPIO_MODER_7_BIT				14
#define GPIO_MODER_6_BIT				12
#define GPIO_MODER_5_BIT				10
#define GPIO_MODER_4_BIT				8
#define GPIO_MODER_3_BIT				6
#define GPIO_MODER_2_BIT				4
#define GPIO_MODER_1_BIT				2
#define GPIO_MODER_0_BIT				0

#define GPIO_MODER_15					(0x3 << GPIO_MODER_15_BIT)
#define GPIO_MODER_14					(0x3 << GPIO_MODER_14_BIT)
#define GPIO_MODER_13					(0x3 << GPIO_MODER_13_BIT)
#define GPIO_MODER_12					(0x3 << GPIO_MODER_12_BIT)
#define GPIO_MODER_11					(0x3 << GPIO_MODER_11_BIT)
#define GPIO_MODER_10					(0x3 << GPIO_MODER_10_BIT)
#define GPIO_MODER_9					(0x3 << GPIO_MODER_9_BIT)
#define GPIO_MODER_8					(0x3 << GPIO_MODER_8_BIT)
#define GPIO_MODER_7					(0x3 << GPIO_MODER_7_BIT)
#define GPIO_MODER_6					(0x3 << GPIO_MODER_6_BIT)
#define GPIO_MODER_5					(0x3 << GPIO_MODER_5_BIT)
#define GPIO_MODER_4					(0x3 << GPIO_MODER_4_BIT)
#define GPIO_MODER_3					(0x3 << GPIO_MODER_3_BIT)
#define GPIO_MODER_2					(0x3 << GPIO_MODER_2_BIT)
#define GPIO_MODER_1					(0x3 << GPIO_MODER_1_BIT)
#define GPIO_MODER_0					(0x3 << GPIO_MODER_0_BIT)

#define GPIO_MODE_INPUT					0
#define GPIO_MODE_AF					1
#define GPIO_MODE_GPO					2
#define GPIO_MODE_ANA					3

/* Output type config */
#define GPIO_OTYPE_PP					0
#define GPIO_OTYPE_OD					1

/* Output speed register */
#define GPIO_OSPEEDR_15_BIT				30
#define GPIO_OSPEEDR_14_BIT				28
#define GPIO_OSPEEDR_13_BIT				26
#define GPIO_OSPEEDR_12_BIT				24
#define GPIO_OSPEEDR_11_BIT				22
#define GPIO_OSPEEDR_10_BIT				20
#define GPIO_OSPEEDR_9_BIT				18
#define GPIO_OSPEEDR_8_BIT				16
#define GPIO_OSPEEDR_7_BIT				14
#define GPIO_OSPEEDR_6_BIT				12
#define GPIO_OSPEEDR_5_BIT				10
#define GPIO_OSPEEDR_4_BIT				8
#define GPIO_OSPEEDR_3_BIT				6
#define GPIO_OSPEEDR_2_BIT				4
#define GPIO_OSPEEDR_1_BIT				2
#define GPIO_OSPEEDR_0_BIT				0

#define GPIO_OSPEEDR_15					(0x3 << GPIO_OSPEEDR_15_BIT)
#define GPIO_OSPEEDR_14					(0x3 << GPIO_OSPEEDR_14_BIT)
#define GPIO_OSPEEDR_13					(0x3 << GPIO_OSPEEDR_13_BIT)
#define GPIO_OSPEEDR_12					(0x3 << GPIO_OSPEEDR_12_BIT)
#define GPIO_OSPEEDR_11					(0x3 << GPIO_OSPEEDR_11_BIT)
#define GPIO_OSPEEDR_10					(0x3 << GPIO_OSPEEDR_10_BIT)
#define GPIO_OSPEEDR_9					(0x3 << GPIO_OSPEEDR_9_BIT)
#define GPIO_OSPEEDR_8					(0x3 << GPIO_OSPEEDR_8_BIT)
#define GPIO_OSPEEDR_7					(0x3 << GPIO_OSPEEDR_7_BIT)
#define GPIO_OSPEEDR_6					(0x3 << GPIO_OSPEEDR_6_BIT)
#define GPIO_OSPEEDR_5					(0x3 << GPIO_OSPEEDR_5_BIT)
#define GPIO_OSPEEDR_4					(0x3 << GPIO_OSPEEDR_4_BIT)
#define GPIO_OSPEEDR_3					(0x3 << GPIO_OSPEEDR_3_BIT)
#define GPIO_OSPEEDR_2					(0x3 << GPIO_OSPEEDR_2_BIT)
#define GPIO_OSPEEDR_1					(0x3 << GPIO_OSPEEDR_1_BIT)
#define GPIO_OSPEEDR_0					(0x3 << GPIO_OSPEEDR_0_BIT)

#define GPIO_OSPEED_400KHZ				0
#define GPIO_OSPEED_2MHZ				1
#define GPIO_OSPEED_10MHZ				2
#define GPIO_OSPEED_40MHZ				3
/* High-speed mode: 40MHz on 50pF Loads, 50MHz on 30 pF loads */

/* Pull-up/pull-down register */
#define GPIO_PUPDR_15_BIT				30
#define GPIO_PUPDR_14_BIT				28
#define GPIO_PUPDR_13_BIT				26
#define GPIO_PUPDR_12_BIT				24
#define GPIO_PUPDR_11_BIT				22
#define GPIO_PUPDR_10_BIT				20
#define GPIO_PUPDR_9_BIT				18
#define GPIO_PUPDR_8_BIT				16
#define GPIO_PUPDR_7_BIT				14
#define GPIO_PUPDR_6_BIT				12
#define GPIO_PUPDR_5_BIT				10
#define GPIO_PUPDR_4_BIT				8
#define GPIO_PUPDR_3_BIT				6
#define GPIO_PUPDR_2_BIT				4
#define GPIO_PUPDR_1_BIT				2
#define GPIO_PUPDR_0_BIT				0

#define GPIO_PUPDR_15					(0x3 << GPIO_PUPDR_15_BIT)
#define GPIO_PUPDR_14					(0x3 << GPIO_PUPDR_14_BIT)
#define GPIO_PUPDR_13					(0x3 << GPIO_PUPDR_13_BIT)
#define GPIO_PUPDR_12					(0x3 << GPIO_PUPDR_12_BIT)
#define GPIO_PUPDR_11					(0x3 << GPIO_PUPDR_11_BIT)
#define GPIO_PUPDR_10					(0x3 << GPIO_PUPDR_10_BIT)
#define GPIO_PUPDR_9					(0x3 << GPIO_PUPDR_9_BIT)
#define GPIO_PUPDR_8					(0x3 << GPIO_PUPDR_8_BIT)
#define GPIO_PUPDR_7					(0x3 << GPIO_PUPDR_7_BIT)
#define GPIO_PUPDR_6					(0x3 << GPIO_PUPDR_6_BIT)
#define GPIO_PUPDR_5					(0x3 << GPIO_PUPDR_5_BIT)
#define GPIO_PUPDR_4					(0x3 << GPIO_PUPDR_4_BIT)
#define GPIO_PUPDR_3					(0x3 << GPIO_PUPDR_3_BIT)
#define GPIO_PUPDR_2					(0x3 << GPIO_PUPDR_2_BIT)
#define GPIO_PUPDR_1					(0x3 << GPIO_PUPDR_1_BIT)
#define GPIO_PUPDR_0					(0x3 << GPIO_PUPDR_0_BIT)

#define GPIO_PUPD_NONE					0
#define GPIO_PUPD_PU					1
#define GPIO_PUPD_PD					2

/* Alternate function registers (low and high) */
#define GPIO_AFRH_15_BIT				28
#define GPIO_AFRH_14_BIT				24
#define GPIO_AFRH_13_BIT				20
#define GPIO_AFRH_12_BIT				16
#define GPIO_AFRH_11_BIT				12
#define GPIO_AFRH_10_BIT				8
#define GPIO_AFRH_9_BIT					4
#define GPIO_AFRH_8_BIT					0

#define GPIO_AFRH_15					(0xF << GPIO_AFRH_15_BIT)
#define GPIO_AFRH_14					(0xF << GPIO_AFRH_14_BIT)
#define GPIO_AFRH_13					(0xF << GPIO_AFRH_13_BIT)
#define GPIO_AFRH_12					(0xF << GPIO_AFRH_12_BIT)
#define GPIO_AFRH_11					(0xF << GPIO_AFRH_11_BIT)
#define GPIO_AFRH_10					(0xF << GPIO_AFRH_10_BIT)
#define GPIO_AFRH_9						(0xF << GPIO_AFRH_9_BIT)
#define GPIO_AFRH_8						(0xF << GPIO_AFRH_8_BIT)

#define GPIO_AFRL_7_BIT					28
#define GPIO_AFRL_6_BIT					24
#define GPIO_AFRL_5_BIT					20
#define GPIO_AFRL_4_BIT					16
#define GPIO_AFRL_3_BIT					12
#define GPIO_AFRL_2_BIT					8
#define GPIO_AFRL_1_BIT					4
#define GPIO_AFRL_0_BIT					0

#define GPIO_AFRL_7						(0xF << GPIO_AFRL_7_BIT)
#define GPIO_AFRL_6						(0xF << GPIO_AFRL_6_BIT)
#define GPIO_AFRL_5						(0xF << GPIO_AFRL_5_BIT)
#define GPIO_AFRL_4						(0xF << GPIO_AFRL_4_BIT)
#define GPIO_AFRL_3						(0xF << GPIO_AFRL_3_BIT)
#define GPIO_AFRL_2						(0xF << GPIO_AFRL_2_BIT)
#define GPIO_AFRL_1						(0xF << GPIO_AFRL_1_BIT)
#define GPIO_AFRL_0						(0xF << GPIO_AFRL_0_BIT)

#define GPIO_AF0						0
#define GPIO_AF1						1
#define GPIO_AF2						2
#define GPIO_AF3						3
#define GPIO_AF4						4
#define GPIO_AF5						5
#define GPIO_AF6						6
#define GPIO_AF7						7
#define GPIO_AF8						8
#define GPIO_AF9						9
#define GPIO_AF10						10
#define GPIO_AF11						11
#define GPIO_AF12						12
#define GPIO_AF13						13
#define GPIO_AF14						14
#define GPIO_AF15						15

/**
 * @brief GPIO Pin modes.
 *
 */


typedef struct gpio_pin_mode {
	/**< Mode register bits value:
	 * (GPIO_MODE_INPUT | GPIO_MODE_AF | GPIO_MODE_GPO | GPIO_MODE_ANA) */
	__io uint8 GPIO_MODE;
	/**< Output push-pull register bit value:
	 * (GPIO_OTYPE_PP | GPIO_OTYPE_OD) */
	__io uint8 GPIO_OTYPE;
	/**< Output speed register bits value:
	 * (GPIO_OSPEED_400KHZ | GPIO_OSPEED_2MHZ |
	 	 GPIO_OSPEED_10MHZ | GPIO_OSPEED_40MHZ) */
	__io uint8 GPIO_OSPEED;
	 /**< Alternate function register bits value:
	  * (GPIO_AF0 | GPIO_AF1 | GPIO_AF2 | GPIO_AF3 | GPIO_AF4 | GPIO_AF5 |
    		GPIO_AF6 | GPIO_AF7 | GPIO_AF8 | GPIO_AF9 | GPIO_AF10 | GPIO_AF11 |
    		GPIO_AF12 | GPIO_AF13 | GPIO_AF14 | GPIO_AF15) */
	__io uint8 GPIO_AF;
	/**< Input pull-up/pull-down register bits value:
	 * (GPIO_PUPD_NONE | GPIO_PUPD_PU | GPIO_PUPD_PD) */
	__io uint8 GPIO_PUPD;
} gpio_pin_mode;

/*
 * GPIO Convenience routines
 */

void gpio_init(gpio_dev *dev);
void gpio_init_all(void);
void gpio_set_mode(gpio_dev *dev, uint8 pin, gpio_pin_mode mode);

/**
 * Set or reset a GPIO pin.
 *
 * Pin must have previously been configured to output mode.
 *
 * @param dev GPIO device whose pin to set.
 * @param pin Pin on to set or reset
 * @param val If true, set the pin.  If false, reset the pin.
 */
static inline void gpio_write_bit(gpio_dev *dev, uint8 pin, uint8 val) {
    if (val) {
        dev->regs->BSRR = BIT(pin);
    } else {
        dev->regs->BSRR = pin << (16+pin);
    }
}

/**
 * Determine whether or not a GPIO pin is set.
 *
 * Pin must have previously been configured to input mode.
 *
 * @param dev GPIO device whose pin to test.
 * @param pin Pin on dev to test.
 * @return True if the pin is set, false otherwise.
 */
static inline uint32 gpio_read_bit(gpio_dev *dev, uint8 pin) {
    return dev->regs->IDR & BIT(pin);
}

/**
 * Toggle a pin configured as output push-pull.
 * @param dev GPIO device.
 * @param pin Pin on dev to toggle.
 */
static inline void gpio_toggle_bit(gpio_dev *dev, uint8 pin) {
    dev->regs->ODR = dev->regs->ODR ^ BIT(pin);
}

#ifdef __cplusplus
}
#endif

#endif
