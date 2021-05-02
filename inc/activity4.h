#ifndef ACTIVITY4_H_INCLUDED
#define ACTIVITY4_H_INCLUDED

#define F_CPU 16000000UL 	//Clock is set to 16 MHz 

#include<avr/io.h>
#include <util/delay.h>
#include <stdint.h>

/**
 * @brief Initialize the USART communication
 * @param unsigned integer to set the baud rate to 9600
 * @note ennabling transmitting and receiving
 */
void Init_USART(uint16_t);

/**
 * @brief Function to read from UDR register
 * @return Return what is  stored in UDR register
 * @note Wait until the data is available and then store it in UDR register
 */
char USART_Read();

/**
 * @brief Function to write to the USART buffer
 * @param uint16_t type integer is temperature.
 */
void USART_Write(uint16_t);

#endif // ACTIVITY4_H_INCLUDED
