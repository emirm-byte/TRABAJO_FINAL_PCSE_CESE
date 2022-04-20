/*
 * port.h
 *
 *  Created on: 26 mar. 2022
 *      Author: Emiliano Eduardo Rodriguez
 */

#ifndef APDS_9930_INC_PORT_H_
#define APDS_9930_INC_PORT_H_

#include "stm32f4xx_hal.h"
#include <stdint.h>
#include <stdbool.h>

typedef bool bool_t;

#define APDS_INTERRUPT_Pin GPIO_PIN_11
#define APDS_INTERRUPT_GPIO_Port GPIOB

void I2C_APDS_Init(void);
void APDS_Int_Init(void);
uint8_t I2C_APDS_Transmit(uint16_t direccion_disp, uint8_t *data, uint16_t size);
uint8_t I2C_APDS_Receive(uint16_t direccion_disp, uint8_t *data, uint16_t size);

#endif /* APDS_9930_INC_PORT_H_ */
