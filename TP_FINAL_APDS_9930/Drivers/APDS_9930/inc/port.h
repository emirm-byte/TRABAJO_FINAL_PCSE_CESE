/*
 * port.h
 *
 *  Created on: 26 mar. 2022
 *      Author: emiliano
 */

#ifndef APDS_9930_INC_PORT_H_
#define APDS_9930_INC_PORT_H_

#include "stm32f4xx_hal.h"
#include <stdint.h>

#define APDS_INTERRUPT_Pin GPIO_PIN_11
#define APDS_INTERRUPT_GPIO_Port GPIOB

void I2C_APDS_Init(void);
void APDS_Int_Init(void);
uint8_t I2C_APDS_Transmit(uint16_t direccion_disp, uint8_t *data, uint16_t size, uint32_t timeout);
uint8_t I2C_APDS_Receive(uint16_t direccion_disp, uint8_t *data, uint16_t size, uint32_t timeout);

#endif /* APDS_9930_INC_PORT_H_ */
