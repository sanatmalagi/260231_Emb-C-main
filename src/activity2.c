#include<avr/io.h>
#include "activity2.h"


void InitADC()
{
    ADMUX=(1<<REFS0);
    ADCSRA=(1<<ADEN)|(7<<ADPS0);
}

/**
 * @brief Read ADC function to read the potentiometer values(temperature sensor)
 *
 * @param c setting channel 0.
 */
uint16_t ReadADC(uint8_t c)
{
    ADMUX&=0xf8;
    c=c&0b00000111;
    ADMUX|=c;
    ADCSRA|=(1<<ADSC);
    while(!(ADCSRA & (1<<ADIF)));
    ADCSRA|=(1<<ADIF);
    return(ADC);
}