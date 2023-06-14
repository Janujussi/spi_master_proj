/**
 * Implementation of gpio_driver.h
 * 
 * Author: Jan Morrison
*/

#include "gpio_driver.h"

void GPIO_Init(GPIO_Handle_t* GPIO_Handle, GPIO_Port_t GPIO_Port) {
    GPIO_Reg_t* pGPIOx = GPIO_Handle->pGPIOx;
    GPIO_Config_t GPIOConfig = GPIO_Handle->GPIOConfig;
    uint8_t GPIOPin = GPIOConfig.PIN;
	RCC_Reg_t* pRCCReg = (RCC_Reg_t*)RCC_BASE_ADDRESS;


    // Enable clock and assign gpio address
    switch(GPIO_Port) {
        case(GPIO_PORT_A):
            pGPIOx = (GPIO_Reg_t*)GPIOA;
            pRCCReg->RCC_AHB2ENR |= (1 << GPIO_PORT_A);
            break;
        case(GPIO_PORT_B):
            pGPIOx = (GPIO_Reg_t*)GPIOB;
            pRCCReg->RCC_AHB2ENR |= (1 << GPIO_PORT_B);
            break;
        case(GPIO_PORT_C):
            pGPIOx = (GPIO_Reg_t*)GPIOC;
            pRCCReg->RCC_AHB2ENR |= (1 << GPIO_PORT_C);
            break;
        case(GPIO_PORT_D):
            pGPIOx = (GPIO_Reg_t*)GPIOD;
            pRCCReg->RCC_AHB2ENR |= (1 << GPIO_PORT_D);
            break;
        case(GPIO_PORT_E):
            pGPIOx = (GPIO_Reg_t*)GPIOE;
            pRCCReg->RCC_AHB2ENR |= (1 << GPIO_PORT_E);
            break;
        case(GPIO_PORT_F):
            pGPIOx = (GPIO_Reg_t*)GPIOF;
            pRCCReg->RCC_AHB2ENR |= (1 << GPIO_PORT_F);
            break;
        case(GPIO_PORT_G):
            pGPIOx = (GPIO_Reg_t*)GPIOG;
            pRCCReg->RCC_AHB2ENR |= (1 << GPIO_PORT_G);
            break;
        case(GPIO_PORT_H):
            pGPIOx = (GPIO_Reg_t*)GPIOH;
            pRCCReg->RCC_AHB2ENR |= (1 << GPIO_PORT_H);
            break;
    }

    // Port Mode
    pGPIOx->MODER &= ~(0x3 << 2 * GPIOPin);
    pGPIOx->MODER |= (GPIOConfig.PIN_MODE << 2 * GPIOPin);

    if (GPIOConfig.PIN_MODE == OUTPUT_MODE) {
        // Output Type
        pGPIOx->OTYPER |= (GPIOConfig.OUTPUT_TYPE << GPIOPin);

        // Output Speed
        pGPIOx->OSPEEDR |= (GPIOConfig.OUTPUT_SPEED << 2 * GPIOPin);
    }

    // PUPDR
    pGPIOx->PUPDR |= ~(0x3 << 2 * GPIOPin);
    pGPIOx->PUPDR |= (GPIOConfig.PUPD << 2 * GPIOPin);

    // Alternate Function
    pGPIOx->AFR[GPIOPin / 8] |= ~(0xF << 4 * GPIOPin);
    pGPIOx->AFR[GPIOPin / 8] |= (GPIOConfig.ALTERNATE_FUNCTION << 4 * GPIOPin);
}

void GPIO_DeInit(GPIO_Handle_t* GPIO_Handle) {
    // reset pin
}

uint8_t GPIO_ReadPin(GPIO_Handle_t* GPIO_Handle) {
    uint16_t IDR = GPIO_Handle->pGPIOx->IDR;
    uint8_t pin = GPIO_Handle->GPIOConfig.PIN;

    return ((IDR >> pin) & 0x1);
}

uint16_t GPIO_ReadPort(GPIO_Handle_t* GPIO_Handle) {
    return GPIO_Handle->pGPIOx->IDR;
}

void GPIO_WritePin(GPIO_Handle_t* GPIO_Handle, uint8_t Pin_Enable) {
    uint8_t GPIOPin = GPIO_Handle->GPIOConfig.PIN;

    GPIO_Handle->pGPIOx->ODR &= ~(0x1 << GPIOPin);
    GPIO_Handle->pGPIOx->ODR |= (Pin_Enable << GPIOPin);
}

void GPIO_WritePort(GPIO_Handle_t* GPIO_Handle, uint16_t Port_Value) {
    GPIO_Handle->pGPIOx->ODR &= ~(0xFFFF);
    GPIO_Handle->pGPIOx->ODR |= Port_Value;
}

// Implement irq later
