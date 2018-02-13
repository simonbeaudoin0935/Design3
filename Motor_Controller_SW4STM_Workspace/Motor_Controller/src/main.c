#include "include.h"



void execute_received_command(void);







int main(void)
{
	systemInit();

	g_parameters.wheel_diameter = 6.58;
	storeParametersInEEPROM();

	while(1){

		if(UART_available(g_selectedUART)){
			if(parseMessage(UART_read(g_selectedUART)) == 1){
				execute_received_command();
				BLUE_LED_TOGGLE;
			}

		}

		if(g_systickCount == 1){

			g_systickCount = 0;

			if(g_typeDeplacement == X){
				PID_1_compute();
				PID_4_compute();
			}
			else if(g_typeDeplacement == Y){
				PID_2_compute();
				PID_3_compute();
			}
			else if(g_typeDeplacement == R){
				PID_1_compute();
				PID_2_compute();
				PID_3_compute();
				PID_4_compute();
			}

			UART_write(g_selectedUART, '#');
			UART_write(g_selectedUART, 0x03);
			UART_write(g_selectedUART, 0x18);

			UART_writeFloatUnion(g_selectedUART, PID_1.vitesse);
			UART_writeFloatUnion(g_selectedUART, -PID_4.vitesse);
			UART_writeFloatUnion(g_selectedUART, PID_1.consigne_position);
			UART_writeFloatUnion(g_selectedUART, PID_1.consigne_vitesse);
			UART_writeFloatUnion(g_selectedUART, PID_1.position);
			UART_writeFloatUnion(g_selectedUART, -PID_4.position);

			UART_write(g_selectedUART, '.');
		}
	}
}

void execute_received_command(void){

	int index = 0;
	switch(g_messageId){

	case 0x01: //read

		UART_write(g_selectedUART, '#');
		UART_write(g_selectedUART, 0x04);
		UART_write(g_selectedUART, 0x88); //to update

		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_1_PKp);
		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_1_PKi);
		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_1_PKd);
		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_1_VKp);
		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_1_VKi);
		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_1_VKd);
		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_1_Amax);
		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_1_Vmax);

		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_2_PKp);
		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_2_PKi);
		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_2_PKd);
		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_2_VKp);
		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_2_VKi);
		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_2_VKd);
		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_2_Amax);
		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_2_Vmax);

		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_3_PKp);
		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_3_PKi);
		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_3_PKd);
		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_3_VKp);
		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_3_VKi);
		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_3_VKd);
		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_3_Amax);
		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_3_Vmax);

		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_4_PKp);
		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_4_PKi);
		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_4_PKd);
		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_4_VKp);
		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_4_VKi);
		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_4_VKd);
		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_4_Amax);
		UART_writeFloatUnion(g_selectedUART, g_parameters.motor_4_Vmax);

		UART_writeFloatUnion(g_selectedUART, g_parameters.dt);
		UART_writeFloatUnion(g_selectedUART, g_parameters.wheel_diameter);

		UART_write(g_selectedUART, '.');

		break;

	case 0x02: //store

		if(g_messageLength != 0x88) break;

		g_parameters.motor_1_PKp = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_1_PKi = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_1_PKd = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_1_VKp = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_1_VKi = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_1_VKd = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_1_Amax = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_1_Vmax = readFloatUnion(&g_messageContent[index]); index += 4;

		g_parameters.motor_2_PKp = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_2_PKi = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_2_PKd = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_2_VKp = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_2_VKi = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_2_VKd = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_2_Amax = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_2_Vmax = readFloatUnion(&g_messageContent[index]); index += 4;

		g_parameters.motor_3_PKp = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_3_PKi = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_3_PKd = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_3_VKp = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_3_VKi = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_3_VKd = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_3_Amax = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_3_Vmax = readFloatUnion(&g_messageContent[index]); index += 4;

		g_parameters.motor_4_PKp = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_4_PKi = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_4_PKd = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_4_VKp = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_4_VKi = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_4_VKd = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_4_Amax = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_4_Vmax = readFloatUnion(&g_messageContent[index]); index += 4;

		g_parameters.dt = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.wheel_diameter = readFloatUnion(&g_messageContent[index]);

		storeParametersInEEPROM();

		break;

	case 0x03: //reset

		PID_resetAll();

		if(g_messageContent[0] == 0x01){ 		//Déplacement en X

			g_typeDeplacement = X;
			PID_4.consigne_position = - readFloatUnion(&g_messageContent[1]);
			PID_1.consigne_position = readFloatUnion(&g_messageContent[1]);
		}

		else if(g_messageContent[0] == 0x02){	//Déplacement en Y

			g_typeDeplacement = Y;
			PID_2.consigne_position = - readFloatUnion(&g_messageContent[1]);
			PID_3.consigne_position = readFloatUnion(&g_messageContent[1]);

		}

		else if(g_messageContent[0] == 0x03){	//Rotation

			PID_1.consigne_position =  readFloatUnion(&g_messageContent[1]);
			PID_2.consigne_position =  readFloatUnion(&g_messageContent[1]);
			PID_3.consigne_position =  readFloatUnion(&g_messageContent[1]);
			PID_4.consigne_position =  readFloatUnion(&g_messageContent[1]);

			g_typeDeplacement = R;

		}
		else{
			break;
		}


		break;

	case 0x04: //
		break;

	case 0x05:
		break;

	default:
		break;
	}
}






void SysTick_Handler(void)
{
	g_systickCount += 1;
}
