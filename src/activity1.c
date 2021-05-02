// include files
#include<avr/io.h>
#include "activity1.h"
/**
 * @brief Change the state of the LED Pin according to the value of S1 and S2.
 *
 * @param v Voltage level to which the LED Pin should be set
 */
void ledchange(uint8_t v)
{
	LED_PORT = (v << LED_PIN);
}
