#include "../MCAL/F97_Uart.h"
#include <util/delay.h>

unsigned char Uart_UDR = 0 ;
unsigned char x = 0 ;

int main ()
{
	F97_void_Uart_Init(9600);
	F97_void_Uart_callbackfunc(&Uart_UDR);
	F97_void_Uart_Send_byte('a');

	for(;;)
	{
		if(Uart_UDR != 0)
		{
			F97_void_Uart_Send_byte(Uart_UDR);
			Uart_UDR = 0;
		}
	}
	return 0;
}


//#include <avr/io.h>
//#include <util/delay.h>
//#include "../MCAL/F97_SPI.h"
//#include "../MCAL/F97_Uart.h"
//
////#define MASTER
//#define SLAVE
//
//int main (void)
//{
//
//	unsigned char Incomingdata = 0;
//	F97_void_Uart_Init(9600);
//
//#ifdef MASTER
//	F97_void_SPI_Init(MASTER_SPI);
//	F97_void_Uart_Send_byte('M');
//
//#endif
//#ifdef SLAVE
//	F97_void_SPI_Init(SLAVE_SPI);
//	F97_void_Uart_Send_byte('S');
//#endif
//
//	for(;;)
//	{
//
//#ifdef MASTER
//		F97_void_SPI_SlaveSelect(SLAVE_1);
//		F97_void_SPI_Send_String((unsigned char *)"Hello World !!");
//		F97_void_Uart_Send_byte(Incomingdata);
//		_delay_ms(1000);
//#endif
//
//#ifdef SLAVE
//		F97_void_SPI_receive(&Incomingdata);
//		F97_void_Uart_Send_byte(Incomingdata);
//#endif
//
//
//	}
//	return 0;
//}
