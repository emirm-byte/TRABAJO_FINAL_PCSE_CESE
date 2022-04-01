/*
 * driver.h
 *
 *  Created on: 26 mar. 2022
 *      Author: emiliano
 */

#ifndef APDS_9930_INC_DRIVER_H_
#define APDS_9930_INC_DRIVER_H_

/*APDS-9930 I2C DEVICE ADDRESS */
#define SENSOR_I2C_ADDR 0x39

/*MODOS REGISTRO COMMAND*/
#define REPEATED_BYTE           0x80
#define AUTO_INCREMENT          0xA0
#define SPECIAL_FN              0xE0

/* DIRECCIONES DE LOS REGISTROS APDS-9930*/
#define SENSOR_ENABLE         0x00
#define SENSOR_ATIME          0x01
#define SENSOR_PTIME          0x02
#define SENSOR_WTIME          0x03
#define SENSOR_AILTL          0x04
#define SENSOR_AILTH          0x05
#define SENSOR_AIHTL          0x06
#define SENSOR_AIHTH          0x07
#define SENSOR_PILTL          0x08
#define SENSOR_PILTH          0x09
#define SENSOR_PIHTL          0x0A
#define SENSOR_PIHTH          0x0B
#define SENSOR_PERS           0x0C
#define SENSOR_CONFIG         0x0D
#define SENSOR_PPULSE         0x0E
#define SENSOR_CONTROL        0x0F
#define SENSOR_ID             0x12
#define SENSOR_STATUS         0x13
#define SENSOR_CH0DATAL       0x14
#define SENSOR_CH0DATAH       0x15
#define SENSOR_CH1DATAL       0x16
#define SENSOR_CH1DATAH       0x17
#define SENSOR_PDATAL         0x18
#define SENSOR_PDATAH         0x19
#define SENSOR_POFFSET        0x1E 

/* CAMPO DE BITS PARA EL REGISTRO ENABLE */
#define SENSOR_PON            0x01
#define SENSOR_AEN            0x02
#define SENSOR_PEN            0x04
#define SENSOR_WEN            0x08
#define SENSOR_AIEN           0x16
#define SENSOR_PIEN           0x32
#define SENSOR_SAI            0x64




#endif /* APDS_9930_INC_DRIVER_H_ */
