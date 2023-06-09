/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "stm32l476rg.h"
#include "gpio_driver.h"

int main(void)
{
	GPIO_Handle_t GPIOC_Pin3_Handle;
    GPIO_Config_t* GPIOC_Pin3_Config = &GPIOC_Pin3_Handle.GPIOConfig;

    GPIOC_Pin3_Config->PORT = GPIO_PORT_C;
    GPIOC_Pin3_Config->PIN = 3;
    GPIOC_Pin3_Config->PIN_MODE = INPUT_MODE;
    GPIOC_Pin3_Config->INTERRUPT_EN = BOTH_TRIGGERS;
    GPIOC_Pin3_Config->PUPD = PULL_UP;

    GPIO_Init(&GPIOC_Pin3_Handle);

    uint8_t val = GPIO_ReadPin(&GPIOC_Pin3_Handle);

    /* Loop forever */
	for(;;);
}
