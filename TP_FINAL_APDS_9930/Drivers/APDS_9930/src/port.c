/*
 * port.c
 *
 *  Created on: 26 mar. 2022
 *      Author: emiliano
 */

#include <port.h>
#include <main.h>

I2C_HandleTypeDef I2C_Handler;

void I2C_APDS_Init(void)
{


  I2C_Handler.Instance = I2C1;
  I2C_Handler.Init.ClockSpeed = 100000;
  I2C_Handler.Init.DutyCycle = I2C_DUTYCYCLE_2;
  I2C_Handler.Init.OwnAddress1 = 0;
  I2C_Handler.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  I2C_Handler.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  I2C_Handler.Init.OwnAddress2 = 0;
  I2C_Handler.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  I2C_Handler.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&I2C_Handler) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&I2C_Handler, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&I2C_Handler, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}


void APDS_Int_Init(void){

	GPIO_InitTypeDef GPIO_InitStruct = {0};

	__HAL_RCC_GPIOB_CLK_ENABLE();

	/*Configure GPIO pin : APDS_INTERRUPT_Pin */
	GPIO_InitStruct.Pin = APDS_INTERRUPT_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(APDS_INTERRUPT_GPIO_Port, &GPIO_InitStruct);

}


uint8_t I2C_APDS_Transmit(uint16_t direccion_disp, uint8_t *data, uint16_t size, uint32_t timeout){
	HAL_StatusTypeDef ret;

	ret = HAL_I2C_Master_Transmit(&I2C_Handler, direccion_disp, data, size, timeout);
	    if ( ret != HAL_OK ) {
	      return 0;
	    }
	    else{
	      return 1;
	    }

}

uint8_t I2C_APDS_Receive(uint16_t direccion_disp, uint8_t *data, uint16_t size, uint32_t timeout){
	HAL_StatusTypeDef ret;

	ret = HAL_I2C_Master_Receive(&I2C_Handler, direccion_disp, data, size, timeout);
		 if ( ret != HAL_OK ) {
		    return 0;
		  }
		  else{
		    return 1;
		  }

}

