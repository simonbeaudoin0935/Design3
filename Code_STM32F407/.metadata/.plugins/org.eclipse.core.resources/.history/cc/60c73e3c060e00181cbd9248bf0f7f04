#ifndef PID_H
#define PID_H

#include "../define.h"
#include "../ParameterManager/ParameterManager.h"

typedef struct{

	float position;
	float position_old;
	float consigne_position;
	float erreur_position;
	float erreur_position_old;
	float integral_position;

	float vitesse;
	float vitesse_old;
	float consigne_vitesse;
	float consigne_vitesse_old;
	float erreur_vitesse;
	float erreur_vitesse_old;
	float integral_vitesse;

	float pid_output;
}PID_t;

void PID_reset_all(void);

void PID_1_reset(void);
void PID_2_reset(void);
void PID_3_reset(void);
void PID_4_reset(void);

void PID_1_compute(void);
void PID_2_compute(void);
void PID_3_compute(void);
void PID_4_compute(void);


#endif //PID_H
