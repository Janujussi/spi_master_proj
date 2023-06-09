#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include <stdint.h>
#include "stm32l476rg.h"

typedef struct {
    GPIO_Reg_t* pGPIOx;  // GPIO port (address)
} GPIO_Handle_t;

/**
 * Initialize GPIO
 * 
 * @param[in] GPIO_Handle: handle for GPIO object
 * @param[in] GPIO_Port: GPIO port to initialize. GPIOA, GPIOB, ..., GPIOH
 * 
 * @return None
*/
void GPIO_Init(GPIO_Handle_t GPIO_Handle, uint32_t GPIO_Port);

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
