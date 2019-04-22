/*
 * F97_SPI.h
 *
 *  Created on: 20 Apr 2019
 *      Author: root
 */

#ifndef F97_SPI_H_
#define F97_SPI_H_

typedef enum
{
	MASTER_SPI,
	SLAVE_SPI
} spi_type_t;


typedef enum
{
	SLAVE_1,
	SLAVE_2
} spi_slaves_t;

void F97_void_SPI_Init(spi_type_t type);
void F97_void_SPI_transiver(unsigned char Send , unsigned char *Receive);
void F97_void_SPI_SlaveSelect(spi_slaves_t S);

void F97_void_SPI_receive(unsigned char *Receive);
void F97_void_SPI_Send_String(unsigned char *arr );


#endif /* F97_SPI_H_ */
