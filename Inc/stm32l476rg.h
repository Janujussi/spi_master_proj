/**
 * Header for STM32L476RG
 *
 * Author: Jan Morrison
 */

#ifndef STM32L476RH_H
#define STM32L476RH_H

#include <stdint.h>

/*----------- Cortex M4 Memory Addresses -----------*/

#define NVIC_REGISTERS_BASE_ADDRESS		0xE000E100U

typedef struct {
	volatile uint32_t ISERx[8];			// offset 0x00 - 0x1C
	volatile uint32_t RESERVED[23];		// 0x20 - 0x7C
	volatile uint32_t ICERx[8];
	volatile uint32_t ISPRx[8];
	volatile uint32_t RESERVED1[23];
	volatile uint32_t ICPRx[8];
	volatile uint32_t IABRx[8];
	volatile uint32_t IPR[60];
} NVIC_Reg_t;

#define NVIC_ISER0				0x
#define NVIC_ISER1
#define NVIC_ISER2
#define NVIC_ISER3

/*----------- STML476RG Memory Map -----------*/

/* RCC */

#define RCC_BASE_ADDRESS        0x40021000U

#define RCC						RCC_BASE_ADDRESS

typedef struct {
    volatile uint32_t RCC_CR;
    volatile uint32_t RCC_ICSCR;
    volatile uint32_t RCC_CFGR;
    volatile uint32_t RCC_PLLCFGR;
    volatile uint32_t RCC_PLLSAICFGR[2];
    volatile uint32_t RCC_CIER;
    volatile uint32_t RCC_CIFR;
    volatile uint32_t RCC_CICR;
    volatile uint32_t gap1;
    volatile uint32_t RCC_AHB1RSTR;
    volatile uint32_t RCC_AHB2RSTR;
    volatile uint32_t RCC_AHB3RSTR;
    volatile uint32_t gap2;
    volatile uint32_t RCC_APB1RSTR[2];
    volatile uint32_t RCC_APB2RSTR;
    volatile uint32_t gap3;
    volatile uint32_t RCC_AHB1ENR;
    volatile uint32_t RCC_AHB2ENR;
    volatile uint32_t RCC_AHB3ENR;
    volatile uint32_t gap4;
    volatile uint32_t RCC_APB1ENR[2];
    volatile uint32_t RCC_APB2ENR;
    volatile uint32_t gap5;
    volatile uint32_t RCC_AHB1SMENR;
    volatile uint32_t RCC_AHB2SMENR;
    volatile uint32_t RCC_AHB3SMENR;
    volatile uint32_t gap6;
    volatile uint32_t RCC_APB1SMENR[2];
    volatile uint32_t RCC_APB2SMENR;
    volatile uint32_t gap7;
    volatile uint32_t RCC_CCIPR;
    volatile uint32_t gap8;
    volatile uint32_t RCC_BDCR;
    volatile uint32_t RCC_CSR;
    volatile uint32_t RCC_CRRCR;
    volatile uint32_t RCC_CCIPR2;
} RCC_Reg_t;

/* Bus Domains */

#define BUS_BASE_ADDRESS        0x40000000U
#define APB1_BASE_ADDRESS       BUS_BASE_ADDRESS
#define APB2_BASE_ADDRESS       (BUS_BASE_ADDRESS + 0x10000U)
#define AHB1_BASE_ADDRESS       (BUS_BASE_ADDRESS + 0x20000U)
#define AHB2_BASE_ADDRESS       (BUS_BASE_ADDRESS + 0x8000000U)

#define APB1					APB1_BASE_ADDRESS
#define APB2					APB2_BASE_ADDRESS
#define AHB1					AHB1_BASE_ADDRESS
#define AHB2					AHB2_BASE_ADDRESS

/* GPIO */

#define GPIOA_BASE_ADDRESS      AHB2_BASE_ADDRESS
#define GPIOB_BASE_ADDRESS      (AHB2_BASE_ADDRESS + 0x400U)
#define GPIOC_BASE_ADDRESS      (AHB2_BASE_ADDRESS + 0x800U)
#define GPIOD_BASE_ADDRESS      (AHB2_BASE_ADDRESS + 0xC00U)
#define GPIOE_BASE_ADDRESS      (AHB2_BASE_ADDRESS + 0x1000U)
#define GPIOF_BASE_ADDRESS      (AHB2_BASE_ADDRESS + 0x1400U)
#define GPIOG_BASE_ADDRESS      (AHB2_BASE_ADDRESS + 0x1800U)
#define GPIOH_BASE_ADDRESS      (AHB2_BASE_ADDRESS + 0x1C00U)

#define GPIOA                   GPIOA_BASE_ADDRESS
#define GPIOB                   GPIOB_BASE_ADDRESS
#define GPIOC                   GPIOC_BASE_ADDRESS
#define GPIOD                   GPIOD_BASE_ADDRESS
#define GPIOE                   GPIOE_BASE_ADDRESS
#define GPIOF                   GPIOF_BASE_ADDRESS
#define GPIOG                   GPIOG_BASE_ADDRESS
#define GPIOH                   GPIOH_BASE_ADDRESS

typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFR[2];
    volatile uint32_t BRR;
    volatile uint32_t ASCR;
} GPIO_Reg_t;

/* SPI */

#define SPI1_BASE_ADDRESS       (APB2_BASE_ADDRESS + 0x3000U)
#define SPI2_BASE_ADDRESS       (APB1_BASE_ADDRESS + 0x3800U)
#define SPI3_BASE_ADDRESS       (APB1_BASE_ADDRESS + 0x3C00U)

#define SPI1					SPI1_BASE_ADDRESS
#define SPI2					SPI2_BASE_ADDRESS
#define SPI3					SPI3_BASE_ADDRESS

typedef struct {
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t SR;
    volatile uint32_t DR;
    volatile uint32_t CRCPR;
    volatile uint32_t RXCRCR;
    volatile uint32_t TXCRCR;
} SPI_Reg_t;

/* SYSCFG */

#define SYSCFG_BASE_ADDRESS		(APB2_BASE_ADDRESS)

#define SYSCFG					SYSCFG_BASE_ADDRESS

typedef struct {
	volatile uint32_t MEMRMP;
	volatile uint32_t CFGR1;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2 ;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	volatile uint32_t SCSR;
	volatile uint32_t CFGR2;
	volatile uint32_t SWPR;
	volatile uint32_t SKR;
//	volatile uint32_t SWPR2; // not for L4x devices
} SYSCFG_Reg_t;

/* EXTI */

#define EXTI_BASE_ADDRESS		(APB2_BASE_ADDRESS + 0X400U)

#define EXTI					EXTI_BASE_ADDRESS

typedef struct {
	volatile uint32_t IMR1;
	volatile uint32_t EMR1;
	volatile uint32_t RTSR1;
	volatile uint32_t FTSR1;
	volatile uint32_t SWIER1;
	volatile uint32_t PR1;
	volatile uint32_t gap1;
	volatile uint32_t gap2;
	volatile uint32_t IMR2;
	volatile uint32_t EMR2;
	volatile uint32_t RTSR2;
	volatile uint32_t FTSR2;
	volatile uint32_t SWIER2;
	volatile uint32_t PR2;
} EXTI_Reg_t;

#endif // STM32L476RH_H
