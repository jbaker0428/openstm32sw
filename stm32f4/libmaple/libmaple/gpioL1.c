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
 * @file gpio.c
 * @brief GPIO initialization routine
 */

#include "gpio.h"
#include "rcc.h"

/*
 * GPIO devices
 */

gpio_dev gpioa = {
    .regs      = GPIOA_BASE,
    .clk_id    = RCC_GPIOA,
};
/** GPIO port A device. */
gpio_dev* const GPIOA = &gpioa;

gpio_dev gpiob = {
    .regs      = GPIOB_BASE,
    .clk_id    = RCC_GPIOB,
};
/** GPIO port B device. */
gpio_dev* const GPIOB = &gpiob;

gpio_dev gpioc = {
    .regs      = GPIOC_BASE,
    .clk_id    = RCC_GPIOC,
};
/** GPIO port C device. */
gpio_dev* const GPIOC = &gpioc;

gpio_dev gpiod = {
    .regs      = GPIOD_BASE,
    .clk_id    = RCC_GPIOD,
};
/** GPIO port D device. */
gpio_dev* const GPIOD = &gpiod;

gpio_dev gpioe = {
    .regs      = GPIOE_BASE,
    .clk_id    = RCC_GPIOE,
};
/** GPIO port E device. */
gpio_dev* const GPIOE = &gpioe;

gpio_dev gpioh = {
    .regs      = GPIOH_BASE,
    .clk_id    = RCC_GPIOH,
};
/** GPIO port H device. */
gpio_dev* const GPIOH = &gpioh;

/*
 * GPIO convenience routines
 */

/**
 * Initialize a GPIO device.
 *
 * Enables the clock for and resets the given device.
 *
 * @param dev GPIO device to initialize.
 */
void gpio_init(gpio_dev *dev) {
    rcc_clk_enable(dev->clk_id);
    rcc_reset_dev(dev->clk_id);
}

/**
 * Initialize and reset all available GPIO devices.
 */
void gpio_init_all(void) {
    gpio_init(GPIOA);
    gpio_init(GPIOB);
    gpio_init(GPIOC);
    gpio_init(GPIOD);
    gpio_init(GPIOE);
    gpio_init(GPIOH);
}

/**
 * Set the mode of a GPIO pin.
 *
 * @param dev GPIO device.
 * @param pin Pin on the device whose mode to set, 0--15.
 * @param mode General purpose or alternate function mode to set the pin to.
 * @see gpio_pin_mode
 */
void gpio_set_mode(gpio_dev *dev, uint8 pin, gpio_pin_mode mode) {
    gpio_reg_map *regs = dev->regs;
    __io uint32 *moder = &regs->MODER;
    __io uint32 *otyper = &regs->OTYPER;
    __io uint32 *ospeedr = &regs->OSPEEDR;
    __io uint32 *pupdr = &regs->PUPDR;
    __io uint32 *afrl = &regs->AFRL;
    __io uint32 *afrh = &regs->AFRH;

    uint32 shift;
    uint32 tmp;

    shift = pin;
    tmp = *otyper;
    tmp &= ~(0x1 << shift);
    tmp |= mode.GPIO_OTYPE;
    *otyper = tmp;

    shift = 2*pin;	// Used for MODER, OSPEEDR, and PUPDR
    tmp = *moder;
    tmp &= ~(0x3 << shift);
    tmp |= mode.GPIO_MODE << shift;
    *moder = tmp;

    tmp = *ospeedr;
    tmp &= ~(0x3 << shift);
    tmp |= mode.GPIO_OSPEED << shift;
    *ospeedr = tmp;

    tmp = *pupdr;
    tmp &= ~(0x3 << shift);
    tmp |= mode.GPIO_PUPD << shift;
    *pupdr = tmp;

    if (mode.GPIO_PUPD == GPIO_PUPD_PD) {
            regs->ODR &= ~BIT(pin);
        } else if (mode.GPIO_PUPD == GPIO_PUPD_PU) {
            regs->ODR |= BIT(pin);
        }

    if (pin > 7) // Use AFRH
    {
    	shift = (pin-8)*4;
    	tmp = *afrh;
    	tmp &= ~(0xF << shift);
    	tmp |= mode.GPIO_AF << shift;
    	*afrh = tmp;
    }
    else // Use AFRL
    {
    	shift = pin*4;
    	tmp = *afrl;
    	tmp &= ~(0xF << shift);
    	tmp |= mode.GPIO_AF << shift;
    	*afrl = tmp;
    }
}
