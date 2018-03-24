#ifndef DEFINE_H
#define DEFINE_H

#define TICK_PER_ROTATION	6400.0
#define PI 				  	3.14159

#define TICK_TO_CM(tick)	(((float)tick) / TICK_PER_ROTATION  * g_parameters.wheel_diameter * PI)

#define BLUE_LED_ON    		GPIOD->ODR |=  0x8000
#define BLUE_LED_OFF		GPIOD->ODR &= ~0x8000
#define BLUE_LED_TOGGLE     GPIOD->ODR ^=  0x8000

#define RED_LED_ON			GPIOD->ODR |=  0x4000
#define RED_LED_OFF			GPIOD->ODR &= ~0x4000
#define RED_LED_TOGGLE		GPIOD->ODR ^=  0x4000

#define SELECTED_UART UART_2



#endif //DEFINE_H