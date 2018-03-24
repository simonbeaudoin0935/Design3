#include "include.h"



void execute_received_command(void);


enum TO_ROBOT_COMMAND_ID
{
    PING                   = 0x01,
    DISPLACEMENT_X         = 0x03,
    DISPLACEMENT_Y         = 0x05,
    DISPLACEMENT_R         = 0x07,
    CANCEL_DISPLACEMENT    = 0x09,
    CHANGE_LED_STATE       = 0x0B,
    REQUEST_COUNTRY_CODE   = 0x0D,
    TILT_CAMERA_LEFT_RIGHT = 0x0F,
    TILT_CAMERA_UP_DOWN    = 0x11,
    GRIP_PREHENSER         = 0x13,
    RELEASE_PREHENSER      = 0x15,
    ACTIVATE_PID_DEBUG     = 0x17,
    STORE_PID_VALUES       = 0x19,
    REQUEST_PID_VALUES     = 0x1B
};

enum FROM_ROBOT_COMMAND_ID
{
    PING_ACK               = 0x02,
    DISPLACEMENT_X_ACK     = 0x04,
    DISPLACEMENT_Y_ACK     = 0x06,
    DISPLACEMENT_R_ACK     = 0x08,

    COUNTRY_CODE           = 0x0E,

    REQUESTED_PID_VALUES   = 0x10,

    PID_OUTPUT             = 0x12
};


char g_immobilize;
char g_pid_debug;

int main(void)
{
	systemInit();

	//g_parameters.wheel_diameter = 6.58;
	//g_parameters.dt = 0.05;
	//storeParametersInEEPROM();

	PID_resetAll();

	g_immobilize = 1;
	g_pid_debug = 0;

	while(1){

		if(UART2_available()){
			if(parseMessage(UART2_read()) == 1){
				execute_received_command();
				BLUE_LED_TOGGLE;
			}

		}

		if(g_systickCount == 1){

			g_systickCount = 0;

			if(g_typeDeplacement == X && g_immobilize == 0){
				PID_Position_X_Compute();
			}
			else if(g_typeDeplacement == Y && g_immobilize == 0){
				PID_Position_Y_Compute();
			}
			else if(g_typeDeplacement == R && g_immobilize == 0){
				PID_Position_R_Compute();
			}

			if(g_pid_debug == 1)
			{
				UART2_write('#');
				UART2_write(PID_OUTPUT);
				UART2_write(0x18);
				if(g_typeDeplacement == X)
				{
					UART2_writeFloatUnion(Encoder_1.vitesse);
					UART2_writeFloatUnion(-Encoder_4.vitesse);
					UART2_writeFloatUnion(Encoder_1.position);
					UART2_writeFloatUnion(-Encoder_4.position);
					UART2_writeFloatUnion(PID_Position_X.consigne_position);
					UART2_writeFloatUnion(PID_Position_X.consigne_vitesse);
				}
				else if(g_typeDeplacement == Y)
				{
					UART2_writeFloatUnion(Encoder_2.vitesse);
					UART2_writeFloatUnion(-Encoder_3.vitesse);
					UART2_writeFloatUnion(Encoder_2.position);
					UART2_writeFloatUnion(-Encoder_3.position);
					UART2_writeFloatUnion(PID_Position_Y.consigne_position);
					UART2_writeFloatUnion(PID_Position_Y.consigne_vitesse);
				}
				else if(g_typeDeplacement == R)
				{
					UART2_writeFloatUnion(Encoder_1.vitesse);
					UART2_writeFloatUnion(Encoder_4.vitesse);
					UART2_writeFloatUnion(Encoder_1.position);
					UART2_writeFloatUnion(Encoder_4.position);
					UART2_writeFloatUnion(PID_Position_R.consigne_position);
					UART2_writeFloatUnion(PID_Position_R.consigne_vitesse);
				}


				UART2_write('.');
			}

		}
	}
}

void execute_received_command(void){

	int index = 0;

	switch(g_messageId){

	case DISPLACEMENT_X:
		PID_resetAll();
		g_typeDeplacement = X;
		PID_Position_X.consigne_position = readFloatUnion(&g_messageContent[0]);
		g_immobilize = 0;
		break;

	case DISPLACEMENT_Y:
		PID_resetAll();
		g_typeDeplacement = Y;
		PID_Position_Y.consigne_position = readFloatUnion(&g_messageContent[0]);
		g_immobilize = 0;
		break;

	case DISPLACEMENT_R:
		PID_resetAll();
		g_typeDeplacement = R;
		PID_Position_X.consigne_position = readFloatUnion(&g_messageContent[0]);
		g_immobilize = 0;
		break;

	case CANCEL_DISPLACEMENT:
		PID_resetAll();
		g_immobilize = 1;
		break;

	case CHANGE_LED_STATE:
		break;

	case REQUEST_COUNTRY_CODE:
		UART2_write('#');
		UART2_write(COUNTRY_CODE);
		UART2_write(0x01);
		UART2_write(UART3_read());
		UART2_write('.');
		break;

	case TILT_CAMERA_LEFT_RIGHT:
		break;

	case TILT_CAMERA_UP_DOWN:
		break;

	case GRIP_PREHENSER:
		break;

	case RELEASE_PREHENSER:
		break;

	case ACTIVATE_PID_DEBUG:
		g_pid_debug = 1;//g_messageContent[0];
		break;

	case REQUEST_PID_VALUES: //read

		UART2_write('#');
		UART2_write(REQUESTED_PID_VALUES);
		UART2_write(0x74); //to update

		UART2_writeFloatUnion(g_parameters.position_X_PKp);
		UART2_writeFloatUnion(g_parameters.position_X_PKi);
		UART2_writeFloatUnion(g_parameters.position_X_PKd);
		UART2_writeFloatUnion(g_parameters.position_X_Vmax);
		UART2_writeFloatUnion(g_parameters.position_X_Amax);
		UART2_writeFloatUnion(g_parameters.position_Y_PKp);
		UART2_writeFloatUnion(g_parameters.position_Y_PKi);
		UART2_writeFloatUnion(g_parameters.position_Y_PKd);
		UART2_writeFloatUnion(g_parameters.position_Y_Vmax);
		UART2_writeFloatUnion(g_parameters.position_Y_Amax);
		UART2_writeFloatUnion(g_parameters.position_R_PKp);
		UART2_writeFloatUnion(g_parameters.position_R_PKi);
		UART2_writeFloatUnion(g_parameters.position_R_PKd);
		UART2_writeFloatUnion(g_parameters.position_R_Vmax);
		UART2_writeFloatUnion(g_parameters.position_R_Amax);
		UART2_writeFloatUnion(g_parameters.motor_1_VKp);
		UART2_writeFloatUnion(g_parameters.motor_1_VKi);
		UART2_writeFloatUnion(g_parameters.motor_1_VKd);
		UART2_writeFloatUnion(g_parameters.motor_2_VKp);
		UART2_writeFloatUnion(g_parameters.motor_2_VKi);
		UART2_writeFloatUnion(g_parameters.motor_2_VKd);
		UART2_writeFloatUnion(g_parameters.motor_3_VKp);
		UART2_writeFloatUnion(g_parameters.motor_3_VKi);
		UART2_writeFloatUnion(g_parameters.motor_3_VKd);
		UART2_writeFloatUnion(g_parameters.motor_4_VKp);
		UART2_writeFloatUnion(g_parameters.motor_4_VKi);
		UART2_writeFloatUnion(g_parameters.motor_4_VKd);
		UART2_writeFloatUnion(g_parameters.dt);
		UART2_writeFloatUnion(g_parameters.wheel_diameter);

		UART2_write('.');

		break;

	case STORE_PID_VALUES: //store

		if(g_messageLength != 0x74) break;

		g_parameters.position_X_PKp = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.position_X_PKi = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.position_X_PKd = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.position_X_Vmax = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.position_X_Amax = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.position_Y_PKp = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.position_Y_PKi = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.position_Y_PKd = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.position_Y_Vmax = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.position_Y_Amax = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.position_R_PKp = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.position_R_PKi = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.position_R_PKd = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.position_R_Vmax = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.position_R_Amax = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_1_VKp = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_1_VKi = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_1_VKd = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_2_VKp = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_2_VKi = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_2_VKd = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_3_VKp = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_3_VKi = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_3_VKd = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_4_VKp = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_4_VKi = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.motor_4_VKd = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.dt = readFloatUnion(&g_messageContent[index]); index += 4;
		g_parameters.wheel_diameter = readFloatUnion(&g_messageContent[index]);

		storeParametersInEEPROM();

		break;

	default:
		break;
	}
}






void SysTick_Handler(void)
{
	g_systickCount += 1;
}
