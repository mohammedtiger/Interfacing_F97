
#include "F97_SPI.h"
#include <avr/io.h>
#include <util/delay.h>

void F97_void_SPI_Init(spi_type_t type)
{
	switch(type)
	{
	case MASTER_SPI:
		DDRB |= (1 << PB5) | (1 << PB7);
		SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR1) | (1 << SPR0);
		break;
	case SLAVE_SPI:
		DDRB |=  (1 << PB6);
		SPCR = (1 << SPE) ;
		break;
	default:
		break;
	}
}

void F97_void_SPI_SlaveSelect(spi_slaves_t S)
{
	switch(S)
	{
	case SLAVE_1 :
		DDRB |= (1 << PB4 );
		PORTB &= ~( 1 << PB4);
		PORTB |= ( 1 << PB3);
		break;
	case SLAVE_2 :
		DDRB |= (1 << PB3 );
		PORTB &= ~( 1 << PB3);
		PORTB |= ( 1 << PB4);

		break;
	}
}

void F97_void_SPI_transiver(unsigned char Send , unsigned char *Receive)
{
	SPDR = Send;
	while((SPSR & (1 << SPIF)) == 0);
//	*Receive = SPDR;
}

void F97_void_SPI_receive(unsigned char *Receive)
{
	while((SPSR & (1 << SPIF)) == 0);
	*Receive = SPDR;
}



void F97_void_SPI_Send_String(unsigned char *arr )
{
	int index = 0 ;
	unsigned char receive_data = 0;
	while(arr[index] != 0)
	{
		F97_void_SPI_transiver(arr[index] , &receive_data);
	    index ++;
	    _delay_ms(5);
	}
}







