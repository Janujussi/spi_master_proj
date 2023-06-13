/**
 * Implementation of gpio_driver.h
 * 
 * Author: Jan Morrison
*/

#include "gpio_driver.h"

void GPIO_Init(GPIO_Handle_t* GPIO_Handle) {
    GPIO_Reg_t* pGPIOx = GPIO_Handle->pGPIOx;
    GPIO_Config_t GPIOConfig = GPIO_Handle->GPIOConfig;
    uint8_t GPIOPin = GPIO_Handle->GPIOConfig.PIN;

//---------------work on enable clock
    // Enable Clock
    switch((int)pGPIOx) {
        case((int)GPIOA):
            break;
        case((int)GPIOB):
            break;
        case((int)GPIOC):
            break;
        case((int)GPIOD):
            break;
        case((int)GPIOE):
            break;
        case((int)GPIOF):
            break;
        case((int)GPIOG):
            break;
        case((int)GPIOH):
            break;
    }

    // Port Mode
    pGPIOx->MODER |= (GPIOConfig.PORT_MODE << 2 * GPIOPin);

    if (GPIOConfig.PORT_MODE == OUTPUT_MODE) {
        // Output Type
        pGPIOx->OTYPER |= (GPIOConfig.OUTPUT_TYPE << GPIOPin);

        // Output Speed
        pGPIOx->OSPEEDR |= (GPIOConfig.OUTPUT_SPEED << 2 * GPIOPin);
    }

    // PUPDR
    pGPIOx->PUPDR |= (GPIOConfig.PUPD << 2 * GPIOPin);

    // Alternate Function
    pGPIOx->AFR[GPIOPin / 8] |= (GPIOConfig.ALTERNATE_FUNCTION << 4 * GPIOPin);
}