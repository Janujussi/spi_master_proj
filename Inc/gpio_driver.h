/**
 * Header of gpio driver
 * 
 * Author: Jan Morrison
*/

#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include <stdint.h>
#include "stm32l476rg.h"

#define SET                     1
#define RESET                   0

#define INPUT_MODE              0
#define OUTPUT_MODE             1
#define AF_MODE                 2
#define ANALOG_MODE             3

#define OUTPUT_PUSH_PULL        0
#define OUTPUT_OPEN_DRAIN       1

#define LOW_SPEED               0
#define MEDIUM_SPEED            1
#define HIGH_SPEED              2
#define VERY_HIGH_SPEED         3

#define NO_PUPD                 0
#define PULL_UP                 1
#define PULL_DOWN               2

#define AF0                     0b0000
#define AF1                     0b0001
#define AF2                     0b0010
#define AF3                     0b0011
#define AF4                     0b0100
#define AF5                     0b0101
#define AF6                     0b0110
#define AF7                     0b0111
#define AF8                     0b1000
#define AF9                     0b1001
#define AF10                    0b1010
#define AF11                    0b1011
#define AF12                    0b1100
#define AF13                    0b1101
#define AF14                    0b1110
#define AF15                    0b1111

typedef struct {
    uint8_t PIN;
    uint8_t PORT_MODE;
    uint8_t OUTPUT_TYPE;
    uint8_t OUTPUT_SPEED;
    uint8_t PUPD;
    uint8_t INPUT_DATA;
    uint8_t OUTPUT_DATA;
    uint8_t ALTERNATE_FUNCTION;
} GPIO_Config_t;

typedef struct {
    GPIO_Reg_t* pGPIOx;  // GPIO port (address)
    GPIO_Config_t GPIOConfig; // GPIO config
} GPIO_Handle_t;

/**
 * Initialize GPIO
 * 
 * @param[in] GPIO_Handle: handle for GPIO object
 * @param[in] GPIO_Port: GPIO port to initialize. GPIOA, GPIOB, ..., GPIOH
 * 
 * @return None
*/
void GPIO_Init(GPIO_Handle_t* GPIO_Handle);

/**
 * Uninitialize GPIO
 * 
 * @param[in] GPIO_Handle: handle for GPIO object
 * 
 * @return None
*/
void GPIO_DeInit(GPIO_Handle_t GPIO_Handle);

/**
 * Read GPIO pin
 * 
 * @param[in] GPIO_Handle: handle for GPIO object
 * @param[in] GPIO_Pin: Pin to read from
 * 
 * @return Pin value
*/
uint8_t GPIO_ReadPin(GPIO_Handle_t GPIO_Handle, uint8_t GPIO_Pin);

/**
 * Read GPIO port
 * 
 * @param[in] GPIO_Handle: handle for GPIO object
 * 
 * @return Port value
*/
uint16_t GPIO_ReadPort(GPIO_Handle_t GPIO_Handle);

/**
 * Write to GPIO pin
 * 
 * @param[in] GPIO_Handle: handle for GPIO object
 * @param[in] GPIO_Pin: pin to write to
 * @param[in] Pin_Enable: SET or RESET pin
 * 
 * @return None
*/
void GPIO_WritePin(GPIO_Handle_t GPIO_Handle, uint8_t GPIO_Pin, uint8_t Pin_Enable);

/**
 * Write to GPIO port
 * 
 * @param[in] GPIO_Handle: handle for GPIO object
 * @param[in] Port_Value: value to write to port
 * 
 * @return None
*/
void GPIO_WritePort(GPIO_Handle_t GPIO_Handle, uint16_t Port_Value);

/**
 * Configure interrupt request
 * 
 * @param[in] GPIO_Handle: handle for GPIO object
 * 
 * @return None
*/
void GPIO_IRQConfig(GPIO_Handle_t GPIO_Handle);

/**
 * Handle interrupt request
 * 
 * @param[in] GPIO_Handle: handle for GPIO object
 * 
 * @return None
*/
void GPIO_IRQHandling(GPIO_Handle_t GPIO_Handle);

#endif // GPIO_DRIVER_H
