/*
 * driver.c
 *
 *  Created on: 26 mar. 2022
 *      Author: Emiliano Eduardo Rodriguez
 */

#include <driver.h>

bool APDS9930_Init(void){

	if(!powerOffSensor()){
		return false;
	}

	if(!setATIME(DEFAULT_ATIME)){
			return false;
		}

	if(!setWTIME(DEFAULT_WTIME)){
				return false;
	     }

	if(!setPTIME(DEFAULT_PTIME)){
				return false;
			}

	if(!setPPULSE(DEFAULT_PPULSE)){
					return false;
				}

	if(!setPOFFSET(DEFAULT_POFFSET)){
					return false;
				}
	if(!setPTIME(DEFAULT_PTIME)){
					return false;
				}
	if(!setCONFIG(DEFAULT_CONFIG)){
					return false;
				}

	if( !setLEDIntensity(DEFAULT_PDRIVE) ) {
	        return false;
	  	  	  	}
	if( !setProximityGain(DEFAULT_PGAIN) ) {
	        return false;
	    		}
	if( !setAmbientLightGain(DEFAULT_AGAIN) ) {
	        return false;
	    		}
	if( !setProximityDiode(DEFAULT_PDIODE) ) {
	        return false;
	            }

	return true;
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

uint8_t getAmbientLightGain(void){
	uint8_t dato_read=0;

	  if( !APDS9930_ReadByte(SENSOR_CONTROL, &dato_read) ) {
	         return false;
	    }

	  dato_read = dato_read & 0x03;
	  return dato_read;

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

	   uint8_t enable_pon = SENSOR_PON | SENSOR_AEN | SENSOR_PEN ;  //PON = Power ON//

	  if( !APDS9930_WriteByte(SENSOR_ENABLE, &enable_pon) ) {
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

bool setATIME(uint8_t atime){
	if( !APDS9930_WriteByte(SENSOR_ATIME, &atime) ) {
		 return false;
	}
	else{
		return true;
	}

}

bool setWTIME(uint8_t wtime){
	if( !APDS9930_WriteByte(SENSOR_WTIME, &wtime) ) {
			 return false;
		}
		else{
			return true;
		}
}

bool setPTIME(uint8_t ptime){
	if( !APDS9930_WriteByte(SENSOR_PTIME, &ptime) ) {
			 return false;
		}
		else{
			return true;
		}

}

bool setPPULSE(uint8_t ppulse){
	if( !APDS9930_WriteByte(SENSOR_PPULSE, &ppulse) ) {
				 return false;
			}
			else{
				return true;
			}
}

bool setPOFFSET(uint8_t poffset){
	if( !APDS9930_WriteByte(SENSOR_POFFSET, &poffset) ) {
				 return false;
			}
			else{
				return true;
			}

}

bool setCONFIG(uint8_t config){

	if( !APDS9930_WriteByte(SENSOR_CONFIG, &config) ) {
				 return false;
			}
			else{
				return true;
			}
}


bool readCh0Light(uint16_t *val_ch0) {


    if(!APDS9930_ReadWord(SENSOR_CH0DATAL, val_ch0)){
    	return false;
    }
    else{
    	return true;

    }
}


bool readCh1Light(uint16_t *val_ch1) {


    if(!APDS9930_ReadWord(SENSOR_CH1DATAL, val_ch1)){
    	return false;
    }
    else{
    	return true;

    }
}

bool readAmbientLight(float *val){
	uint16_t ch0;
	uint16_t ch1;
	uint8_t x[4]={1,8,16,120};
	float ALSIT, iac1, iac2, iac, lpc;

	if( !readCh0Light(&ch0) ) {
	        return false;
	   }

	if( !readCh1Light(&ch1) ) {
	        return false;
	    }

	ALSIT = 2.73 * (256 - DEFAULT_ATIME);
	iac1 = ch0 - ALS_B * ch1;
	iac2 = ALS_C * ch0 - ALS_D * ch1;
	if(iac1>iac2){
		iac=iac1;
	}
	else{
		iac=iac2;
	}
	if (iac < 0){
		iac = 0;
	}

	lpc  = GA * DF / (ALSIT * x[getAmbientLightGain()]);
	*val = iac * lpc;

	return true;
}

bool readProximity(uint16_t *val){

	if(!APDS9930_ReadWord(SENSOR_CH1DATAL, val)){
	    return false;
	  }
	  else
	  {
	   return true;
	  }
}



bool APDS9930_ReadByte(uint8_t registro, uint8_t *dato){

	if(!I2C_APDS_Read(registro | REPEATED_BYTE, dato, 1)){
			return false;

		}
		else{
			return true;

		}
}

bool APDS9930_ReadWord(uint8_t registro, uint16_t *dato){

	uint8_t buff[2]={0};

	if(!I2C_APDS_Read(registro | REPEATED_BYTE, buff, 2)){
				return false;
			}

	*dato = buff[0]+256*buff[1];
	 return true;
}



bool APDS9930_WriteByte(uint8_t registro, uint8_t *dato){

	if(!I2C_APDS_Write(registro | REPEATED_BYTE, dato, 1)){
		return false;

	}
	else{
		return true;

	}

}



