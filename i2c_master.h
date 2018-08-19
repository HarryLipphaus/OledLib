//
//  i2c_master.h
//  i2c
//
//  Created by Michael Köhler on 09.10.17.
//
//

#ifndef I2C_MASTER_H
#define I2C_MASTER_Hs

#ifndef __ARM_ARCH
/* TODO: setup i2c/twi */

#ifdef I2C_HIGHSPEED
#define F_I2C			400000UL// clock i2c
#else
#define F_I2C			100000UL// clock i2c
#endif

#define PSC_I2C			1		// prescaler i2c
#define SET_TWBR		(F_CPU/F_I2C-16UL)/(PSC_I2C*2UL)

#include <stdio.h>
#include <avr/io.h>

extern uint8_t I2C_ErrorCode;		// variable for communication error at twi
									// ckeck it in your code
									// 0 means no error
									// define bits in I2C-ErrorCode:
#define I2C_START		0			// bit 0: timeout start-condition
#define I2C_SENDADRESS	1			// bit 0: timeout device-adress
#define I2C_BYTE		2			// bit 0: timeout byte-transmission
#define I2C_READACK		3			// bit 0: timeout read acknowledge
#define I2C_READNACK	4			// bit 0: timeout read nacknowledge

void i2c_init(void);				// init hw-i2c
void i2c_start(uint8_t i2c_addr);	// send i2c_start_condition
void i2c_stop(void);				// send i2c_stop_condition
void i2c_byte(uint8_t byte);		// send data_byte

uint8_t i2c_readAck(void);          // read byte with ACK
uint8_t i2c_readNAck(void);         // read byte with NACK

#endif // __ARM_ARCH
#endif /* I2C_MASTER_H */
