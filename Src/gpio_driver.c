/**
 * Implementation of gpio_driver.h
 * 
 * Author: Jan Morrison
*/

#include "gpio_driver.h"

void GPIO_Init(GPIO_Handle_t* GPIO_Handle) {
    GPIO_Reg_t* pGPIOx = GPIO_Handle->pGPIOx;
    GPIO_Config_t GPIO_Config = GPIO_Handle->GPIOConfig;
    uint8_t GPIOPin = GPIO_Config.PIN;
	RCC_Reg_t* pRCCReg = (RCC_Reg_t*)RCC;
	SYSCFG_Reg_t* pSYSCFGReg = (SYSCFG_Reg_t*)SYSCFG;
	EXTI_Reg_t* pEXTIReg = (EXTI_Reg_t*)EXTI;


    // Enable clock and assign gpio address
    switch(GPIO_Config.PORT) {
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
    pGPIOx->MODER |= (GPIO_Config.PIN_MODE << 2 * GPIOPin);

    if (GPIO_Config.PIN_MODE == OUTPUT_MODE) {
        // Output Type
        pGPIOx->OTYPER |= (GPIO_Config.OUTPUT_TYPE << GPIOPin);

        // Output Speed
        pGPIOx->OSPEEDR |= (GPIO_Config.OUTPUT_SPEED << 2 * GPIOPin);
    } else if (GPIO_Config.INTERRUPT_EN) {
		// Enable SYSCFG
		if (!(pRCCReg->RCC_APB2ENR & 0x1)) {
			pRCCReg->RCC_APB2ENR |= (1 << 0);
		}

		// Configure SYSCFG
		switch(GPIO_Config.PIN / 4) {
			case(0):
				pSYSCFGReg->EXTICR1 |= (GPIO_Config.PORT << GPIO_Config.PIN % 4);
				break;

			case(1):
				pSYSCFGReg->EXTICR2 |= (GPIO_Config.PORT << GPIO_Config.PIN % 4);
				break;

			case(2):
				pSYSCFGReg->EXTICR3 |= (GPIO_Config.PORT << GPIO_Config.PIN % 4);
				break;

			default:
				pSYSCFGReg->EXTICR4 |= (GPIO_Config.PORT << GPIO_Config.PIN % 4);
				break;
		}

		/* Setup EXTI */

		// Enable Interrupt
		pEXTIReg->IMR1 |= (1 << GPIO_Config.PIN);

		// Configure Edges
		if (GPIO_Config.INTERRUPT_EN & 0x1) {
			pEXTIReg->RTSR1 |= (1 << GPIO_Config.PIN);
		}

		if (GPIO_Config.INTERRUPT_EN & 0x2) {
			pEXTIReg->FTSR1 |= (1 << GPIO_Config.PIN);
		}
    }

    // PUPDR
    pGPIOx->PUPDR |= ~(0x3 << 2 * GPIOPin);
    pGPIOx->PUPDR |= (GPIO_Config.PUPD << 2 * GPIOPin);

    // Alternate Function
    pGPIOx->AFR[GPIOPin / 8] |= ~(0xF << 4 * GPIOPin);
    pGPIOx->AFR[GPIOPin / 8] |= (GPIO_Config.ALTERNATE_FUNCTION << 4 * GPIOPin);

}

/**
 *	Not implemented
 */
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

void GPIO_IRQConfig(GPIO_Handle_t* GPIO_Handle) {
}

void GPIO_IRQHandler(GPIO_Handle_t* GPIO_Handle) {

}
