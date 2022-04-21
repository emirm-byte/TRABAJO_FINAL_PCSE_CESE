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
	
    if( !setAmbientLightGain(DEFAULT_AGAIN) ) {
        return false;
    }
    
    if( !powerOnSensor() ){
        return false;
    }
    if( !setOperation(SENSOR_AEN, 1) ) {
        return false;
    }
    
    return true;

}

bool lightSensorOff(void){
	if( !setOperation(SENSOR_PEN, 0) ) {
        	return false;
    	}
	else{
		return true;
	}
}

bool proximitySensorOn(void){
	
   if( !setProximityGain(DEFAULT_PGAIN) ) {
        return false;
    }
    if( !setLEDIntensity(DEFAULT_PDRIVE) ) {
        return false;
    }
    
    if( !powerOnSensor() ){
        return false;
    }
    
   if( !setOperation(SENSOR_PEN, 1) ) {
        return false;
    }

return true;
	
}

bool proximitySensorOff(void){

	if( !setOperation(SENSOR_PEN, 0) ) {
        	return false;
    	}
	else{
		return true;
	}
	
		
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

bool powerOffSensor(void){
	uint8_t dato_write= 0x00;  //Escribo 0x00 en el registro enable para desactivar el sensor//
	
	if( !APDS9930_WriteByte(SENSOR_ENABLE, &dato_write) ) {
	           return false;
	      }
	else{
		   return true;
	}
	
}

bool powerOnSensor(void){
	uint8_t enable_read=0;

	  if( !APDS9930_ReadByte(SENSOR_ENABLE, &enable_read) ) {
	         return false;
	     }

	   enable_read = enable_read | SENSOR_PON ;  //PON = Power ON//

	  if( !APDS9930_WriteByte(SENSOR_ENABLE, &enable_read) ) {
	           return false;
	      }

	   return true;
}

bool setOperation(uint8_t modo, uint8_t enable){
	uint8_t enable_read=0;

	if( !APDS9930_ReadByte(SENSOR_ENABLE, &enable_read) ) {
	        return false;
	    }
	
	if(enable){
		modo = modo | enable_read;
		if( !APDS9930_WriteByte(SENSOR_ENABLE, &modo) ) {
	           return false;
	      	} 	
	}
	else{
		modo = ~modo;
		modo = modo & enable_read;
		if( !APDS9930_WriteByte(SENSOR_ENABLE, &modo) ) {
	           return false;
	      	} 	
	
	}
	
	return true;
	
}


bool APDS9930_ReadByte(uint8_t registro, uint8_t *dato){

	if(!I2C_APDS_Transmit(SENSOR_I2C_ADDR, (uint8_t *)(registro | REPEATED_BYTE), 1)){

		uartSendString("TX NOOK");

		return false;
	}

	if(!I2C_APDS_Receive(SENSOR_I2C_ADDR, dato, 1)){
		uartSendString("RX NOOK");

		return false;
	}
	
		return true;
		uartSendString("TX OK");
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



