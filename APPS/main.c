#include "../MCAL/F97_Uart.h"
#include <util/delay.h>

unsigned char Uart_UDR = 0 ;
unsigned char x = 0 ;
int main ()
{
	F97_void_Uart_Init(9600);
	F97_void_Uart_callbackfunc(&x);
	unsigned char incomingdata = 0;
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
