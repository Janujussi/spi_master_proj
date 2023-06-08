#ifndef STM32L476RH_H
#define STM32L476RH_H

/*----------- Memory map -----------*/

/* RCC */

#define RCC_BASE_ADDRESS        0x40021000U

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

#endif // STM32L476RH_H
