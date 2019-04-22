


#include <avr/io.h>
#include <avr/iom32.h>
#include <avr/interrupt.h>
#include "../SL/Standard_types.h"
#include "F97_Uart.h"


volatile unsigned char *ptr_uart;

void F97_void_Uart_Init(unsigned long baud)
{
	unsigned long baudrate = (F_CPU / (baud*16)) - 1;
	unsigned char reg = 0;
	F97_SET_BIT(reg , RXEN);
	F97_SET_BIT(reg , TXEN);
	F97_SET_BIT(reg , RXCIE);

	UCSRB = reg;
	reg = 0;
	F97_SET_BIT(reg , URSEL);
	F97_SET_BIT(reg , UCSZ0);
	F97_SET_BIT(reg , UCSZ1);

	UCSRC = reg;

	UBRRL = (unsigned char) (baudrate);
	UBRRH = (unsigned char) (baudrate >> 8);

	sei();


}

void F97_void_Uart_callbackfunc(unsigned char *ptr)
{
	ptr_uart = ptr;
}

void F97_void_Uart_Send_byte(unsigned char data)
{
	while (F97_CHECK_BIT(UCSRA , UDRE) == 0);
	UDR = data;
}

void F97_void_Uart_Send_String(unsigned char *data)
{
	int index = 0 ;
	while(data[index] != 0)
	{
		F97_void_Uart_Send_byte(data[index]);
		index ++;
	}
}

void F97_void_Uart_Send_frame(unsigned char *data , int len)
{
	for(int index = 0 ; index < len ; index ++)
	{
		F97_void_Uart_Send_byte(data[index]);
	}

}

void F97_void_Uart_Receive_byte(unsigned char *data)
{
	while (F97_CHECK_BIT(UCSRA , RXC) == 0);
	*data = UDR;
}

ISR(USART_RXC_vect)
{
	if(ptr_uart)
		*ptr_uart = UDR;
}
