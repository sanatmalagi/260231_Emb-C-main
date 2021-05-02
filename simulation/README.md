# Blinky Project In Act
## LED ON
| s1 and s2 ON|
:-------------------------:
|![LED ON](LED%20ON%20(s1%20ON,s2%20ON).png)|

## LED OFF
| s1 and s2 OFF            |  s1 OFF ,s2 ON |  s1 ON ,s2 OFF|
:-------------------------:|:-------------------------:|:-------------------------:
![LED case 1](LED%20OFF%20(s1%20OFF%20,s2%20OFF).png) | ![LED case 2](LED%20OFF%20(s1%20OFF,s2%20ON).png) | ![LED case 3](LED%20OFF%20(s1%20ON%20,s2%20OFF).png)

## Code 
```
	for(;;)
	{
        change_led_state(HIGH);
		delay_ms(LED_ON_TIME);
        change_led_state(LOW);
		delay_ms(LED_OFF_TIME);	
	}
```