#include "activity1.h"
#include "activity2.h"
#include<avr/io.h>
#include "activity3.h"
#include <util/delay.h>
#include "activity4.h"
/**
 * @brief Initialize all the peripherals
 *
 */

void initialize(void)
{
    /*Configure LED ,Switch pins and initialize pwm and usart*/
    DDRD=DDRD|(1<<4);
    DDRC=DDRC&~(1<<4);
    DDRC=DDRC &~(1<<5);
    InitADC();
    init_pwm();
    Init_USART(103);

}


int main(void)
{
    uint16_t temp;
    /* Initialize peripherals*/
    initialize();
    while(1)
    {
        if(SWITCH_ON && HEATER_ON) /*If switch_1 and switch_2 are both ON*/
        {
            temp = 0;
            ledchange(LED_ON);/*LED is ON*/
            temp=ReadADC(0);/*Read ADC function is called and the value obtained is stored in temp*/
            pwm(temp);
            _delay_ms(200);
            USART_Write(temp);
            }
        else
        {
            ledchange(LED_OFF);/*LED is OFF*/
        }
    }
    return 0;
}