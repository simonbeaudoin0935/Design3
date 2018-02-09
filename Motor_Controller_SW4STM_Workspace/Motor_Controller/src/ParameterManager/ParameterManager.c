/*
 * ParameterManager.cpp
 *
 *  Created on: Feb 8, 2018
 *      Author: simon
 */

#include "../../inc/ParameterManager/ParameterManager.h"


parameters_t g_parameters;


void loadParametersFromEEPROM(){

	lireMemoireEEPROM(0, sizeof(parameters_t), (unsigned char*)&g_parameters);

}

void storeParametersInEEPROM(){

	ecrireMemoireEEPROM(0,sizeof(parameters_t), (unsigned char*)&g_parameters);

}