/*
 * F97_Uart.h
 *
 *  Created on: 13 Apr 2019
 *      Author: root
 */

#ifndef F97_UART_H_
#define F97_UART_H_

void F97_void_Uart_Init(unsigned long baud);
void F97_void_Uart_Send_byte(unsigned char data);
void F97_void_Uart_Send_String(unsigned char *data);
void F97_void_Uart_Send_frame(unsigned char *data , int len);
void F97_void_Uart_Receive_byte(unsigned char *data);
void F97_void_Uart_callbackfunc(unsigned char *ptr);

#endif /* F97_UART_H_ */
