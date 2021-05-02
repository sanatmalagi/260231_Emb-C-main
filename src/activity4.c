#include "activity4.h"

int i = 0;

void Init_USART(uint16_t baud_rate){
    /*Seting the required Baud rate*/
    UBRR0L = baud_rate;
    UBRR0H = (baud_rate>>8)&0x00ff;
    UCSR0C = (1<<UMSEL00) | (1<<UCSZ01) | (1<<UCSZ00);

    /*receiver and transmitter enabled*/
    UCSR0B = (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0) | (1<<TXCIE0);
}

char USART_Read(){
    /*Wait for dataavailability*/
    while(!(UCSR0A & (1<<RXC0))){
        /*still*/
    }
    return UDR0;
}

void USART_Write(uint16_t temp){
    if(temp>=0 && temp<=200){
        unsigned char temperature[] = "Temperature is 20 degree Celsius"; /*duty cycle=20%*/
        i = 0;
        while(temperature[i] != 0) 
        {
            while (!( UCSR0A & (1<<UDRE0))); /*Wait for empty transmit buffer*/
            UDR0 = temperature[i];            /*store data in buffer and send it.*/
            i++;                             /*increment pc*/
        }
    }
    else if(temp>=210 && temp<=500){
        unsigned char temperature[] = "Temperature is 25 degree Celsius"; /*duty=40%*/
        i = 0;
        while(temperature[i] != 0) 
        {
            while (!( UCSR0A & (1<<UDRE0))); /*Wait for empty transmit buffer*/
            UDR0 = temperature[i];           /*store data in buffer and send it.*/
            i++;                             /*increment pc*/
        }
    }
    else if(temp>=510 && temp<=700){
        unsigned char temperature[] = "Temperature is 29 degree Celsius"; /*duty=70%*/
        i = 0;
        while(temperature[i] != 0) 
        {
            while (!( UCSR0A & (1<<UDRE0))); /*Wait for empty transmit buffer*/
            UDR0 = temperature[i];            /*store data in buffer and send it.*/
            i++;                             /*increment pc*/
        }
    }
    else if(temp>=710 && temp<=1024){
        unsigned char temperature[] = "Temperature is 33 degree Celsius"; /*duty=95%*/
        i = 0;
        while(temperature[i] != 0) 
        {
            while (!( UCSR0A & (1<<UDRE0))); /*Wait for empty transmit buffer*/
            UDR0 = temperature[i];            /*store data in buffer and send it.*/
            i++;                             /*increment pc*/
        }
    }
    else{
        unsigned char temperature[] = "Temperature is not within the limit";  /*duty= 100%*/
        i = 0;
        while(temperature[i] != 0) 
        {
            while (!( UCSR0A & (1<<UDRE0))); /*Wait for empty transmit buffer*/
            UDR0 = temperature[i];            /*store data in buffer and send it.*/
            i++;                             /*increment pc*/
        }
    }
    while (!( UCSR0A & (1<<UDRE0)));   /*Wait for empty transmit buffer*/
		 UDR0 = '\n';   /*store data in buffer and send it.*/
    while (!( UCSR0A & (1<<UDRE0)));  /*Wait for empty transmit buffer*/
		 UDR0 = '\r';					    /*store data in buffer and send it.*/
    _delay_ms(2000);
}