#include "../../inc/Motor/PID.h"
#include "../../inc/Motor/Motor.h"
#include "../../inc/define.h"


#include "stm32f4xx.h"


typedef struct{

	float position;
	float position_old;

	float vitesse;
	float vitesse_old;


	float consigne_position;

	float consigne_vitesse;
	float consigne_vitesse_old;

	float erreur_position;
	float erreur_position_old;

	float erreur_vitesse;
	float erreur_vitesse_old;

	float integral_position;
	float integral_vitesse;

	float acceleration;

	float pid;
}PID_t;

PID_t PID_1;
PID_t PID_2;
PID_t PID_3;
PID_t PID_4;



void PID_reset(void){

	PID_1.consigne_position     = 0.5;

	PID_1.consigne_vitesse      = 0.0;
	PID_1.consigne_vitesse_old  = 0.0;

	PID_1.erreur_position       = 0.0;
	PID_1.erreur_position_old   = 0.0;

	PID_1.erreur_vitesse        = 0.0;
	PID_1.erreur_vitesse_old    = 0.0;

	PID_1.integral_position     = 0.0;
	PID_1.integral_vitesse      = 0.0;

	PID_1.pid                   = 0.0;

	PID_1.position              = 0.0;
	PID_1.position_old          = 0.0;

	PID_1.vitesse               = 0.0;
	PID_1.vitesse_old           = 0.0;


}


void PID_compute(void){

	uint16_t motor_1_tick = TIM1->CNT;
	TIM1->CNT = 32762;
	uint16_t motor_2_tick = TIM2->CNT;
	TIM2->CNT = 32762;
	uint16_t motor_3_tick = TIM3->CNT;
	TIM3->CNT = 32762;
	uint16_t motor_4_tick = TIM4->CNT;
	TIM4->CNT = 32762;

	PID_1.position += ((float)((int)motor_1_tick - 32762)) * TICK_TO_METER;
	PID_1.position += ((float)((int)motor_2_tick - 32762)) * TICK_TO_METER;
	PID_1.position += ((float)((int)motor_3_tick - 32762)) * TICK_TO_METER;
	PID_1.position += ((float)((int)motor_4_tick - 32762)) * TICK_TO_METER;

	PID_1.consigne_vitesse_old = PID_1.consigne_vitesse;
	PID_1.erreur_position_old  = PID_1.erreur_position;
	PID_1.erreur_position      = PID_1.consigne_position - PID_1.position;
	PID_1.integral_position   += PID_1.erreur_position;
	float derivee_erreur_position = (PID_1.erreur_position - PID_1.erreur_position_old) / CONTROL_LOOP_INTERVAL;
	PID_1.consigne_vitesse     = PKp * PID_1.erreur_position +
								 PKi * PID_1.integral_position   +
								 PKd * derivee_erreur_position;

	if(PID_1.consigne_vitesse > Vmax){
		PID_1.consigne_vitesse = Vmax;
	}else if(PID_1.consigne_vitesse < - Vmax){
		PID_1.consigne_vitesse = - Vmax;
	}

	PID_1.acceleration = (PID_1.consigne_vitesse - PID_1.consigne_vitesse_old)  / CONTROL_LOOP_INTERVAL;

	if(PID_1.acceleration > Amax){
		PID_1.consigne_vitesse = PID_1.consigne_vitesse_old + Amax;
	}else if(PID_1.acceleration < - Amax){
		PID_1.consigne_vitesse = PID_1.consigne_vitesse_old - Amax;
	}

	PID_1.vitesse = (PID_1.position - PID_1.position_old) / CONTROL_LOOP_INTERVAL;
	PID_1.position_old = PID_1.position;

	PID_1.erreur_vitesse_old = PID_1.erreur_vitesse;
	PID_1.erreur_vitesse = PID_1.consigne_vitesse - PID_1.vitesse;

	float derivee_vitesse = (PID_1.erreur_vitesse - PID_1.erreur_vitesse_old) / CONTROL_LOOP_INTERVAL;
	PID_1.integral_vitesse += PID_1.erreur_vitesse * CONTROL_LOOP_INTERVAL;
	PID_1.pid = VKp * PID_1.erreur_vitesse +
			    VKi * PID_1.integral_vitesse +
				VKd * derivee_vitesse;


	motor1_set_speed((int)(PID_1.pid));
}



