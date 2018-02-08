#ifndef DEFINE_H
#define DEFINE_H

#define TICK_PER_ROTATION	6400.0
#define WHEEL_DIAMETER_CM 	7.0
#define PI 				  	3.14159

#define TICK_TO_CM(tick)	(((float)tick) / TICK_PER_ROTATION  * WHEEL_DIAMETER_CM * PI)


#define DELTA_TEMPS 0.05 //Second



#define Amax 3.0 //cm/s^2
#define Vmax 5.0 //cm/s

/*
 * En pourcent. Représente le rapport cyclique minimum avant que le moteur se mette
 * à tourner. À été évalué par tranche de 0.5%. Par exemple, à 49.5% le moteur 1 ne
 * tournait pas, mais à 50.0% il s'est mit à tourner
 */
#define MOTOR_1_PWM_VAL	     	    4500
#define MOTOR_2_MIN_DUTY_CYCLE		0.540
#define MOTOR_3_MIN_DUTY_CYCLE		0.530
#define MOTOR_4_MIN_DUTY_CYCLE		0.510

/*
 * C'est la valeur jusqu'à laquelle les timers des quatre moteurs comptent avant de
 * overflow pour avoir un PWM d'une fréquence de 10 kHz
 */
#define MOTOR_PWM_OVERFLOW_VALUE	8399



#endif //DEFINE_H
