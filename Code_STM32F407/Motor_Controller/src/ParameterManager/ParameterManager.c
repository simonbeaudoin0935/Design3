#include "ParameterManager/ParameterManager.h"

#include "ParameterManager/25LC128.h"

parameters_t g_parameters;


void loadParametersFromEEPROM(){

	lireMemoireEEPROM(0, sizeof(parameters_t), (unsigned char*)&g_parameters);

}

void storeParametersInEEPROM(){

	ecrireMemoireEEPROM(0,sizeof(parameters_t), (unsigned char*)&g_parameters);

}
