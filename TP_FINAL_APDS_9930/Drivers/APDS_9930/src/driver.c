/*
 * driver.c
 *
 *  Created on: 26 mar. 2022
 *      Author: Emiliano Eduardo Rodriguez
 */

#include <driver.h>

bool APDS9930_Init(void){


}

uint8_t APDS9930_Read_ID(void){

	uint8_t dato_read=0;

	if( !APDS9930_ReadByte(SENSOR_ID, &dato_read) ) {
		    return 0;
		}

	return dato_read;

}

bool lightSensorOn(void){


}

bool lightSensorOff(void){


}

bool proximitySensorOn(void){


}

bool proximitySensorOff(void){


}

bool setAmbientLightGain(uint8_t again){
	uint8_t dato_read=0;

	  if( !APDS9930_ReadByte(SENSOR_CONTROL, &dato_read) ) {
	         return false;
	     }

	  again = again | dato_read;

	  if( !APDS9930_WriteByte(SENSOR_CONTROL, &again) ) {
	           return false;
	      }


	   return true;

}


bool setProximityGain(uint8_t pgain){
  uint8_t dato_read=0;

  if( !APDS9930_ReadByte(SENSOR_CONTROL, &dato_read) ) {
         return false;
     }

  pgain = pgain | dato_read;

  if( !APDS9930_WriteByte(SENSOR_CONTROL, &pgain) ) {
           return false;
      }


   return true;
}

bool setProximityDiode(uint8_t pdiode){
	uint8_t dato_read=0;

	  if( !APDS9930_ReadByte(SENSOR_CONTROL, &dato_read) ) {
	         return false;
	     }

	  pdiode = pdiode | dato_read;

	  if( !APDS9930_WriteByte(SENSOR_CONTROL, &pdiode) ) {
	           return false;
	      }


	   return true;


}

bool setLEDIntensity(uint8_t pdrive){
	uint8_t dato_read=0;

	  if( !APDS9930_ReadByte(SENSOR_CONTROL, &dato_read) ) {
	         return false;
	     }

	  pdrive = pdrive | dato_read;

	  if( !APDS9930_WriteByte(SENSOR_CONTROL, &pdrive) ) {
	           return false;
	      }


	   return true;


}


bool APDS9930_ReadByte(uint8_t registro, uint8_t *dato){

	if(!I2C_APDS_Transmit(SENSOR_I2C_ADDR, (uint8_t *)(registro | REPEATED_BYTE), 1)){

		return false;
	}

	if(!I2C_APDS_Receive(SENSOR_I2C_ADDR, dato, 1)){
		return false;
	}
	
		return true;
}

bool APDS9930_WriteByte(uint8_t registro, uint8_t *dato){

	if(!I2C_APDS_Transmit(SENSOR_I2C_ADDR, (uint8_t *)(registro | AUTO_INCREMENT), 1)){
		return false;
	}

	if(!I2C_APDS_Transmit(SENSOR_I2C_ADDR, dato, 1)){
		return false;
	}

		return true;
}

