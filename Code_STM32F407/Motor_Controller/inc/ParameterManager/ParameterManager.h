#ifndef PARAMETERMANAGER_H_
#define PARAMETERMANAGER_H_

#include "ParameterManager/25LC128.h"

void loadParametersFromEEPROM();
void storeParametersInEEPROM();

typedef	struct{
    float position_X_PKp;
    float position_X_PKi;
    float position_X_PKd;
    float position_X_Vmax;
    float position_X_Amax;

    float position_Y_PKp;
    float position_Y_PKi;
    float position_Y_PKd;
    float position_Y_Vmax;
    float position_Y_Amax;

    float position_R_PKp;
    float position_R_PKi;
    float position_R_PKd;
    float position_R_Vmax;
    float position_R_Amax;

    float motor_1_VKp;
    float motor_1_VKi;
    float motor_1_VKd;

    float motor_2_VKp;
    float motor_2_VKi;
    float motor_2_VKd;

    float motor_3_VKp;
    float motor_3_VKi;
    float motor_3_VKd;

    float motor_4_VKp;
    float motor_4_VKi;
    float motor_4_VKd;

    float dt;

    float wheel_diameter;
}parameters_t;

extern parameters_t g_parameters;

#endif /* PARAMETERMANAGER_H_ */
