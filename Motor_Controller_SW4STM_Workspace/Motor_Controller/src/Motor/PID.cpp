#include "../../inc/Motor/PID.h"
#include "../../inc/Motor/Motor.h"
#include "../../inc/define.h"


#include "stm32f4xx.h"

float PKp = 0.3;
float PKi = 0.02;
float PKd = 0.00;

float VKp = 0.02;
float VKi = 0.01;
float VKd = 0.00;




Encodeur_t encodeur_1;

PID_t PID_1;



void PID_compute(void){

	uint16_t motor_1_tick = TIM1->CNT;
	TIM1->CNT = 32762;

	int motor_1_delta_tick = (int) motor_1_tick - 32762;

	encodeur_1.position += TICK_TO_CM(motor_1_delta_tick);



//Asservissement en position

	PID_1.consigne_vitesse_old = PID_1.consigne_vitesse;

	PID_1.erreur_position_old  = PID_1.erreur_position;

	PID_1.erreur_position      = PID_1.consigne_position - encodeur_1.position;

	PID_1.integral_position   += PID_1.erreur_position * DELTA_TEMPS;

	float derivee_erreur_position = (PID_1.erreur_position - PID_1.erreur_position_old) / DELTA_TEMPS;

	PID_1.consigne_vitesse     = PKp * PID_1.erreur_position     +
								 PKi * PID_1.integral_position   +
								 PKd * derivee_erreur_position;

	if(PID_1.consigne_vitesse >   Vmax) PID_1.consigne_vitesse =   Vmax;
	if(PID_1.consigne_vitesse < - Vmax) PID_1.consigne_vitesse = - Vmax;

	float acceleration = (PID_1.consigne_vitesse - PID_1.consigne_vitesse_old)  / DELTA_TEMPS;

	if(acceleration > Amax)   PID_1.consigne_vitesse = PID_1.consigne_vitesse_old + (Amax * DELTA_TEMPS);
	if(acceleration < - Amax) PID_1.consigne_vitesse = PID_1.consigne_vitesse_old - (Amax * DELTA_TEMPS);





//Asservissement en vitesse

	PID_1.vitesse = (encodeur_1.position - PID_1.position_old) / DELTA_TEMPS;

	PID_1.position_old = encodeur_1.position;

	PID_1.erreur_vitesse_old = PID_1.erreur_vitesse;

	PID_1.erreur_vitesse = PID_1.consigne_vitesse - PID_1.vitesse;

	float derivee_erreur_vitesse = (PID_1.erreur_vitesse - PID_1.erreur_vitesse_old) / DELTA_TEMPS;

	PID_1.integral_vitesse += PID_1.erreur_vitesse * DELTA_TEMPS;

	PID_1.pid = VKp * PID_1.erreur_vitesse +
			    VKi * PID_1.integral_vitesse +
				VKd * derivee_erreur_vitesse;

	if(PID_1.pid > 1.0)  PID_1.pid = 1.0;
	if(PID_1.pid < -1.0) PID_1.pid = -1.0;

//	if(PID_1.erreur_position < 0.1 && PID_1.erreur_position > -0.1){
//		PID_1.pid = 0.0;
//		encodeur_1.position = PID_1.consigne_position;
//		PID_1.integral_position = 0.0;
//	}

	motor1_set_speed_percent(PID_1.pid);
}



void PID_reset(void){

	encodeur_1.position         = 0.0;


	PID_1.vitesse               = 0.0;
	PID_1.consigne_position     = 20.0;

	PID_1.consigne_vitesse      = 0.0;
	PID_1.consigne_vitesse_old  = 0.0;

	PID_1.erreur_position       = 0.0;
	PID_1.erreur_position_old   = 0.0;

	PID_1.erreur_vitesse        = 0.0;
	PID_1.erreur_vitesse_old    = 0.0;

	PID_1.integral_position     = 0.0;
	PID_1.integral_vitesse      = 0.0;

	PID_1.pid                   = 0.0;

	PID_1.position_old          = 0.0;


	PID_1.vitesse_old           = 0.0;

	TIM1->CNT = 32762;
}


