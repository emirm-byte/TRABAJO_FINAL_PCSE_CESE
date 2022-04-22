/*
 * port.c
 *
 *  Created on: 26 mar. 2022
 *      Author: Emiliano Eduardo Rodriguez
 */

#include <port.h>
#include <main.h>

I2C_HandleTypeDef hi2c2;

void I2C_APDS_Init(void)
{


	  hi2c2.Instance = I2C2;
	  hi2c2.Init.ClockSpeed = 100000;
	  hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
	  hi2c2.Init.OwnAddress1 = 0;
	  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	  hi2c2.Init.OwnAddress2 = 0;
	  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
	  {
	    Error_Handler();
	  }

	  /** Configure Analogue filter
	  */
	  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c2, I2C_ANALOGFILTER_DISABLE) != HAL_OK)
	  {
	    Error_Handler();
	  }

	  /** Configure Digital filter
	  */
	  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c2, 0) != HAL_OK)
	  {
	    Error_Handler();
	  }


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

//HAL_MAX_DELAY ->Es el timeout máximo que se puede asignar por la HAL//


uint8_t I2C_APDS_Write(uint16_t direccion_registro, uint8_t *data, uint16_t size){
	HAL_StatusTypeDef ret;

	ret = HAL_I2C_Mem_Write(&hi2c2, SENSOR_I2C_ADDR, direccion_registro, I2C_MEMADD_SIZE_8BIT, data, size, HAL_MAX_DELAY);
	    if ( ret != HAL_OK ) {
	      return 0;
	    }
	    else{
	      return 1;
	    }
	 HAL_Delay(100);
}


uint8_t I2C_APDS_Read(uint16_t direccion_registro, uint8_t *data, uint16_t size){
	HAL_StatusTypeDef ret;

	ret = HAL_I2C_Mem_Read(&hi2c2, SENSOR_I2C_ADDR, direccion_registro, I2C_MEMADD_SIZE_8BIT, data, size, HAL_MAX_DELAY);
		 if ( ret != HAL_OK ) {
		    return 0;
		  }
		  else{
		    return 1;
		  }
     HAL_Delay(100);
}

