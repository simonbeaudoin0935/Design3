#include "Motor/PID.h"

#include "ParameterManager/ParameterManager.h"
#include "Motor/Motor.h"
#include "define.h"
#include "stm32f4xx.h"

Encoder_t Encoder_1, Encoder_2, Encoder_3, Encoder_4;

PID_Position_t PID_Position_X, PID_Position_Y, PID_Position_R;

PID_Vitesse_t PID_Vitesse_1, PID_Vitesse_2, PID_Vitesse_3, PID_Vitesse_4;

type_deplacement g_typeDeplacement;


void PID_resetAll(void){
	//PID_1_reset();
	//PID_2_reset();
	//PID_3_reset();
	//PID_4_reset();
}

void PID_computeAll(void){
	//PID_1_compute();
	//PID_2_compute();
	//PID_3_compute();
	//PID_4_compute();
}


void Encoder_1_Compute(void){
	//Calcul de la nouvelle position

	Encoder_1.position += TICK_TO_CM(((int)(TIM1->CNT) - 32762));

	TIM1->CNT = 32762;
}
//void Encoder_2_Compute(void);
//void Encoder_3_Compute(void);

void Encoder_4_Compute(void){
	//Calcul de la nouvelle position

	Encoder_4.position += TICK_TO_CM(((int)(TIM4->CNT) - 32762));

	TIM4->CNT = 32762;
}



void PID_Position_X_Compute(void){
	//Asservissement en position
	Encoder_1_Compute();
	Encoder_4_Compute();

	PID_Position_X.position = 0.5 * (Encoder_1.position - Encoder_4.position);

	//PID_Position_X.position = Encoder_1.position;

	PID_Position_X.consigne_vitesse_old = PID_Position_X.consigne_vitesse;

	PID_Position_X.erreur_position_old  = PID_Position_X.erreur_position;


	PID_Position_X.erreur_position      = PID_Position_X.consigne_position - PID_Position_X.position;

	PID_Position_X.integral_position   += PID_Position_X.erreur_position * g_parameters.dt;

	float derivee_erreur_position = (PID_Position_X.erreur_position - PID_Position_X.erreur_position_old) / g_parameters.dt;

	PID_Position_X.consigne_vitesse = g_parameters.motor_1_PKp * PID_Position_X.erreur_position    +
						     	 	  g_parameters.motor_1_PKi * PID_Position_X.integral_position  +
									  g_parameters.motor_1_PKd * derivee_erreur_position;

	if(PID_Position_X.consigne_vitesse > g_parameters.motor_1_Vmax)
		PID_Position_X.consigne_vitesse = g_parameters.motor_1_Vmax;

	if(PID_Position_X.consigne_vitesse < - g_parameters.motor_1_Vmax)
		PID_Position_X.consigne_vitesse = - g_parameters.motor_1_Vmax;

	float acceleration = (PID_Position_X.consigne_vitesse - PID_Position_X.consigne_vitesse_old)  / g_parameters.dt;

	if(acceleration > g_parameters.motor_1_Amax)
		PID_Position_X.consigne_vitesse = PID_Position_X.consigne_vitesse_old + (g_parameters.motor_1_Amax * g_parameters.dt);

	if(acceleration < - g_parameters.motor_1_Amax)
		PID_Position_X.consigne_vitesse = PID_Position_X.consigne_vitesse_old - (g_parameters.motor_1_Amax * g_parameters.dt);



	//Asservissement en vitesse moteur 1

	Encoder_1.vitesse = (Encoder_1.position - Encoder_1.position_old) / g_parameters.dt;

	Encoder_1.position_old = Encoder_1.position;

	PID_Vitesse_1.erreur_vitesse_old = PID_Vitesse_1.erreur_vitesse;

	PID_Vitesse_1.erreur_vitesse = PID_Position_X.consigne_vitesse - Encoder_1.vitesse;

	float derivee_erreur_vitesse = (PID_Vitesse_1.erreur_vitesse - PID_Vitesse_1.erreur_vitesse_old) / g_parameters.dt;

	PID_Vitesse_1.integral_vitesse += PID_Vitesse_1.erreur_vitesse * g_parameters.dt;

	PID_Vitesse_1.pid_output = g_parameters.motor_1_VKp * PID_Vitesse_1.erreur_vitesse +
						   	   g_parameters.motor_1_VKi * PID_Vitesse_1.integral_vitesse +
							   g_parameters.motor_1_VKd * derivee_erreur_vitesse;

	//Asservissement en vitesse moteur 4

	Encoder_4.vitesse = (Encoder_4.position - Encoder_4.position_old) / g_parameters.dt;

	Encoder_4.position_old = Encoder_4.position;

	PID_Vitesse_4.erreur_vitesse_old = PID_Vitesse_4.erreur_vitesse;

	PID_Vitesse_4.erreur_vitesse = -PID_Position_X.consigne_vitesse - Encoder_4.vitesse;

	derivee_erreur_vitesse = (PID_Vitesse_4.erreur_vitesse - PID_Vitesse_4.erreur_vitesse_old) / g_parameters.dt;

	PID_Vitesse_4.integral_vitesse += PID_Vitesse_4.erreur_vitesse * g_parameters.dt;

	PID_Vitesse_4.pid_output = g_parameters.motor_1_VKp * PID_Vitesse_4.erreur_vitesse +
						   	   g_parameters.motor_1_VKi * PID_Vitesse_4.integral_vitesse +
							   g_parameters.motor_1_VKd * derivee_erreur_vitesse;






	motor1_set_speed_percent(PID_Vitesse_1.pid_output);
	motor4_set_speed_percent(PID_Vitesse_4.pid_output);

	if(((PID_Position_X.erreur_position > 0.0)? PID_Position_X.erreur_position : - PID_Position_X.erreur_position ) < 0.1){
			PID_Position_X_reset();
			extern char finit;
			finit = 1;

	}

}

void PID_Position_Y_Compute(void){

}

void PID_Position_Z_Compute(void){

}






//
//void PID_2_compute(void){
//
////Calcul de la nouvelle position
//
//	uint16_t motor_2_tick = TIM2->CNT;
//
//	TIM2->CNT = 32762;
//
//	PID_2.position += TICK_TO_CM(((int)motor_2_tick - 32762));
//
////Asservissement en position
//
//	PID_2.consigne_vitesse_old = PID_2.consigne_vitesse;
//
//	PID_2.erreur_position_old  = PID_2.erreur_position;
//
//	PID_2.erreur_position      = PID_2.consigne_position - PID_2.position;
//
//	PID_2.integral_position   += PID_2.erreur_position * g_parameters.dt;
//
//	float derivee_erreur_position = (PID_2.erreur_position - PID_2.erreur_position_old) / g_parameters.dt;
//
//	PID_2.consigne_vitesse = g_parameters.motor_2_PKp * PID_2.erreur_position    +
//						     g_parameters.motor_2_PKi * PID_2.integral_position  +
//							 g_parameters.motor_2_PKd * derivee_erreur_position;
//
//	if(PID_2.consigne_vitesse > g_parameters.motor_2_Vmax)
//		PID_2.consigne_vitesse = g_parameters.motor_2_Vmax;
//
//	if(PID_2.consigne_vitesse < - g_parameters.motor_2_Vmax)
//		PID_2.consigne_vitesse = - g_parameters.motor_2_Vmax;
//
//	float acceleration = (PID_2.consigne_vitesse - PID_2.consigne_vitesse_old)  / g_parameters.dt;
//
//	if(acceleration > g_parameters.motor_2_Amax)
//		PID_2.consigne_vitesse = PID_2.consigne_vitesse_old + (g_parameters.motor_2_Amax * g_parameters.dt);
//
//	if(acceleration < - g_parameters.motor_2_Amax)
//		PID_2.consigne_vitesse = PID_2.consigne_vitesse_old - (g_parameters.motor_2_Amax * g_parameters.dt);
//
////	//A MODIFIER
////	if(g_typeDeplacement == X){
////		PID_2.consigne_vitesse = - PID_1.consigne_vitesse;
////	}
//
////Asservissement en vitesse
//
//	PID_2.vitesse = (PID_2.position - PID_2.position_old) / g_parameters.dt;
//
//	PID_2.position_old = PID_2.position;
//
//	PID_2.erreur_vitesse_old = PID_2.erreur_vitesse;
//
//	PID_2.erreur_vitesse = PID_2.consigne_vitesse - PID_2.vitesse;
//
//	float derivee_erreur_vitesse = (PID_2.erreur_vitesse - PID_2.erreur_vitesse_old) / g_parameters.dt;
//
//	PID_2.integral_vitesse += PID_2.erreur_vitesse * g_parameters.dt;
//
//	PID_2.pid_output = g_parameters.motor_2_VKp * PID_2.erreur_vitesse +
//					   g_parameters.motor_2_VKi * PID_2.integral_vitesse +
//					   g_parameters.motor_2_VKd * derivee_erreur_vitesse;
//
//	if(((PID_2.erreur_position > 0.0)? PID_2.erreur_position : - PID_2.erreur_position ) < 0.1)
//		PID_2_reset();
//
//	motor2_set_speed_percent(PID_2.pid_output);
//}
//
//void PID_3_compute(void){
//
////Calcul de la nouvelle position
//
//	uint16_t motor_3_tick = TIM3->CNT;
//
//	TIM3->CNT = 32762;
//
//	PID_3.position += TICK_TO_CM(((int)motor_3_tick - 32762));
//
////Asservissement en position
//
//	PID_3.consigne_vitesse_old = PID_3.consigne_vitesse;
//
//	PID_3.erreur_position_old  = PID_3.erreur_position;
//
//	PID_3.erreur_position      = PID_3.consigne_position - PID_3.position;
//
//	PID_3.integral_position   += PID_3.erreur_position * g_parameters.dt;
//
//	float derivee_erreur_position = (PID_3.erreur_position - PID_3.erreur_position_old) / g_parameters.dt;
//
//	PID_3.consigne_vitesse = g_parameters.motor_3_PKp * PID_3.erreur_position    +
//						     g_parameters.motor_3_PKi * PID_3.integral_position  +
//							 g_parameters.motor_3_PKd * derivee_erreur_position;
//
//	if(PID_3.consigne_vitesse > g_parameters.motor_3_Vmax)
//		PID_3.consigne_vitesse = g_parameters.motor_3_Vmax;
//
//	if(PID_3.consigne_vitesse < - g_parameters.motor_3_Vmax)
//		PID_3.consigne_vitesse = - g_parameters.motor_3_Vmax;
//
//	float acceleration = (PID_3.consigne_vitesse - PID_3.consigne_vitesse_old)  / g_parameters.dt;
//
//	if(acceleration > g_parameters.motor_3_Amax)
//		PID_3.consigne_vitesse = PID_3.consigne_vitesse_old + (g_parameters.motor_3_Amax * g_parameters.dt);
//
//	if(acceleration < - g_parameters.motor_3_Amax)
//		PID_3.consigne_vitesse = PID_3.consigne_vitesse_old - (g_parameters.motor_3_Amax * g_parameters.dt);
//
////Asservissement en vitesse
//
//	PID_3.vitesse = (PID_3.position - PID_3.position_old) / g_parameters.dt;
//
//	PID_3.position_old = PID_3.position;
//
//	PID_3.erreur_vitesse_old = PID_3.erreur_vitesse;
//
//	PID_3.erreur_vitesse = PID_3.consigne_vitesse - PID_3.vitesse;
//
//	float derivee_erreur_vitesse = (PID_3.erreur_vitesse - PID_3.erreur_vitesse_old) / g_parameters.dt;
//
//	PID_3.integral_vitesse += PID_3.erreur_vitesse * g_parameters.dt;
//
//	PID_3.pid_output = g_parameters.motor_3_VKp * PID_3.erreur_vitesse +
//					   g_parameters.motor_3_VKi * PID_3.integral_vitesse +
//					   g_parameters.motor_3_VKd * derivee_erreur_vitesse;
//
//	if(((PID_3.erreur_position > 0.0)? PID_3.erreur_position : - PID_3.erreur_position ) < 0.1)
//		PID_3_reset();
//
//	motor3_set_speed_percent(PID_3.pid_output);
//}
//
//void PID_4_compute(void){
//
////Calcul de la nouvelle position
//
//	uint16_t motor_4_tick = TIM4->CNT;
//
//	TIM4->CNT = 32762;
//
//	PID_4.position += TICK_TO_CM(((int)motor_4_tick - 32762));
//
////Asservissement en position
//
//	PID_4.consigne_vitesse_old = PID_4.consigne_vitesse;
//
//	PID_4.erreur_position_old  = PID_4.erreur_position;
//
//	PID_4.erreur_position      = PID_4.consigne_position - PID_4.position;
//
//	PID_4.integral_position   += PID_4.erreur_position * g_parameters.dt;
//
//	float derivee_erreur_position = (PID_4.erreur_position - PID_4.erreur_position_old) / g_parameters.dt;
//
//	PID_4.consigne_vitesse = g_parameters.motor_4_PKp * PID_4.erreur_position    +
//						     g_parameters.motor_4_PKi * PID_4.integral_position  +
//							 g_parameters.motor_4_PKd * derivee_erreur_position;
//
//	if(PID_4.consigne_vitesse > g_parameters.motor_4_Vmax)
//		PID_4.consigne_vitesse = g_parameters.motor_4_Vmax;
//
//	if(PID_4.consigne_vitesse < - g_parameters.motor_4_Vmax)
//		PID_4.consigne_vitesse = - g_parameters.motor_4_Vmax;
//
//	float acceleration = (PID_4.consigne_vitesse - PID_4.consigne_vitesse_old)  / g_parameters.dt;
//
//	if(acceleration > g_parameters.motor_4_Amax)
//		PID_4.consigne_vitesse = PID_4.consigne_vitesse_old + (g_parameters.motor_4_Amax * g_parameters.dt);
//
//	if(acceleration < - g_parameters.motor_4_Amax)
//		PID_4.consigne_vitesse = PID_4.consigne_vitesse_old - (g_parameters.motor_4_Amax * g_parameters.dt);
//
////Asservissement en vitesse
//
//	PID_4.vitesse = (PID_4.position - PID_4.position_old) / g_parameters.dt;
//
//	PID_4.position_old = PID_4.position;
//
//	PID_4.erreur_vitesse_old = PID_4.erreur_vitesse;
//
//	PID_4.erreur_vitesse = PID_4.consigne_vitesse - PID_4.vitesse;
//
//	float derivee_erreur_vitesse = (PID_4.erreur_vitesse - PID_4.erreur_vitesse_old) / g_parameters.dt;
//
//	PID_4.integral_vitesse += PID_4.erreur_vitesse * g_parameters.dt;
//
//	PID_4.pid_output = g_parameters.motor_4_VKp * PID_4.erreur_vitesse +
//					   g_parameters.motor_4_VKi * PID_4.integral_vitesse +
//					   g_parameters.motor_4_VKd * derivee_erreur_vitesse;
//
//	if(((PID_4.erreur_position > 0.0)? PID_4.erreur_position : - PID_4.erreur_position ) < 0.1)
//		PID_4_reset();
//
//	motor4_set_speed_percent(PID_4.pid_output);
//}

void PID_Position_X_reset(void){

	motor1_set_speed_percent(0.0);
	motor4_set_speed_percent(0.0);

	Encoder_1.position = 0.0;
	Encoder_1.position_old = 0.0;
	Encoder_1.vitesse = 0.0;


	Encoder_4.position = 0.0;
	Encoder_4.position_old = 0.0;
	Encoder_4.vitesse = 0.0;


	PID_Position_X.consigne_position = 0.0;
	PID_Position_X.position = 0.0;
	PID_Position_X.position_old = 0.0;
	PID_Position_X.erreur_position = 0.0;
	PID_Position_X.erreur_position_old = 0.0;
	PID_Position_X.integral_position = 0.0;
	PID_Position_X.consigne_vitesse = 0.0;
	PID_Position_X.consigne_vitesse_old = 0.0;

	PID_Vitesse_1.erreur_vitesse = 0.0;
	PID_Vitesse_1.erreur_vitesse_old = 0.0;
	PID_Vitesse_1.integral_vitesse = 0.0;
	PID_Vitesse_1.pid_output = 0.0;

	PID_Vitesse_4.erreur_vitesse = 0.0;
	PID_Vitesse_4.erreur_vitesse_old = 0.0;
	PID_Vitesse_4.integral_vitesse = 0.0;
	PID_Vitesse_4.pid_output = 0.0;



	TIM1->CNT 					= 32762;
	TIM4->CNT 					= 32762;
}

