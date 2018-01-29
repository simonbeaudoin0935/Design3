#include "../../inc/Motor/Motor.h"

#include "stm32f4xx.h"

void motor_1_init(void);

void motors_init()
{
  motor_1_init();
}




void motor_1_init()
{
//QUADRATURE : TIM1
//  CH1 -> PE9
//  CH2 -> PE11
  
//PWM : TIM10
//  CH1 : PB8

//CTRL1 : PD0
//CTRL2 : PD1
  
  GPIO_InitTypeDef GPIO_InitStruct;
  
  TIM_TimeBaseInitTypeDef TIM_BaseStruct;
  
  TIM_OCInitTypeDef TIM_OCStruct;

  
// ******************* CONFIGURATION DE LA PIN PWM
 
/*  Configuration �lectrique de la pin  */
  
  //activer la clock du port B
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

  //Initialiser la pin 8 avec fonction alternative
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOB, &GPIO_InitStruct);
  
  //Configurer la fonction alternative avec timer 10  
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_TIM10);
  
/*  Configuration de la base du temps du timer  */
  
  //Activer la clock du timer 10
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM10, ENABLE);
  
  
  /*    
    TIM4 is connected to APB1 bus, which has on F407 device 42MHz clock                 
    But, timer has internal PLL, which double this frequency for timer, up to 84MHz     
    Remember: Not each timer is connected to APB1, there are also timers connected     
    on APB2, which works at 84MHz by default, and internal PLL increase                 
    this to up to 168MHz                                                             
    
    Set timer prescaller 
    Timer count frequency is set with 
    
    timer_tick_frequency = Timer_default_frequency / (prescaller_set + 1)        
    
    In our case, we want a max frequency for timer, so we set prescaller to 0         
    And our timer will have tick frequency        
    
    timer_tick_frequency = 84000000 / (0 + 1) = 84000000 
*/    
    TIM_BaseStruct.TIM_Prescaler = 0;
    /* Count up */
    TIM_BaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
/*
    Set timer period when it have reset
    First you have to know max value for timer
    In our case it is 16bit = 65535
    To get your frequency for PWM, equation is simple
    
    PWM_frequency = timer_tick_frequency / (TIM_Period + 1)
    
    If you know your PWM frequency you want to have timer period set correct
    
    TIM_Period = timer_tick_frequency / PWM_frequency - 1
    
    In our case, for 10Khz PWM_frequency, set Period to
    
    TIM_Period = 84000000 / 10000 - 1 = 8399
    
    If you get TIM_Period larger than max timer value (in our case 65535),
    you have to choose larger prescaler and slow down timer tick frequency
*/
    TIM_BaseStruct.TIM_Period = 8399; /* 10kHz PWM */
    TIM_BaseStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_BaseStruct.TIM_RepetitionCounter = 0;
    /* Initialize TIM4 */
    TIM_TimeBaseInit(TIM10, &TIM_BaseStruct);
    /* Start count on TIM4 */
    TIM_Cmd(TIM10, ENABLE);
  
/*  Configuration du mode PWM  */ 
    
    
       
    
    /* Common settings */
    
    /* PWM mode 2 = Clear on compare match */
    /* PWM mode 1 = Set on compare match */
    TIM_OCStruct.TIM_OCMode = TIM_OCMode_PWM2;
    TIM_OCStruct.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCStruct.TIM_OCPolarity = TIM_OCPolarity_Low;
    
/*
    To get proper duty cycle, you have simple equation
    
    pulse_length = ((TIM_Period + 1) * DutyCycle) / 100 - 1
    
    where DutyCycle is in percent, between 0 and 100%
    
    25% duty cycle:     pulse_length = ((8399 + 1) * 25) / 100 - 1 = 2099
    50% duty cycle:     pulse_length = ((8399 + 1) * 50) / 100 - 1 = 4199
    75% duty cycle:     pulse_length = ((8399 + 1) * 75) / 100 - 1 = 6299
    100% duty cycle:    pulse_length = ((8399 + 1) * 100) / 100 - 1 = 8399
    
    Remember: if pulse_length is larger than TIM_Period, you will have output HIGH all the time
*/
    TIM_OCStruct.TIM_Pulse = 0; /* 0% duty cycle */
    TIM_OC1Init(TIM10, &TIM_OCStruct);
    TIM_OC1PreloadConfig(TIM10, TIM_OCPreload_Enable);
  
  
  
// ******************* CONFIGURATION DES PINS DE CONTROLE 1 ET 2
  
  //activer la clock du port D
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
 
  //Aucune configuration alternative pour les pins de controle du moteur, juste deux gpio
  
  
  //Initialiser la pins de controle du moteur
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOD, &GPIO_InitStruct);

// ******************* CONFIGURATION DES PINS DE L'ENCODEUR QUADRATURE
  
  //activer la clock du port E
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
  
  //Configurer la fonction alternative avec timer 1 
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource9,  GPIO_AF_TIM1);
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource11, GPIO_AF_TIM1);
  
  //Initialiser la pins de controle du moteur
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_11;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOE, &GPIO_InitStruct);
  
  
  TIM_EncoderInterfaceConfig(TIM1,
                             TIM_EncoderMode_TI12, 
                             TIM_ICPolarity_Rising, 
                             TIM_ICPolarity_Rising);
  TIM_SetAutoreload(TIM1, 0xffff);
  
  TIM_Cmd(TIM1, ENABLE);
  
  
  //encodersReset();
  
}




void motor1_set_speed(signed char p_speed){

	if(p_speed > 0){

		//forward
	    GPIOD->BSRRL = 0x0002; //set   PD1
	    GPIOD->BSRRH = 0x0001; //reset PD0
	    TIM10->CCR1 = ((8399 + 1) * p_speed) / 100 - 1;
	}
	else if(p_speed < 0){
		//backward
	    GPIOD->BSRRL = 0x0001; //set   PD0
	    GPIOD->BSRRH = 0x0002; //reset PD1
	    p_speed *= -1;
	    TIM10->CCR1 = ((8399 + 1) * p_speed) / 100 - 1;

	}
	else{
		//brake to ground
	    GPIOD->BSRRL = 0x0000; //set nothing
	    GPIOD->BSRRH = 0x0003; //reset PD0 and PD1
	    TIM10->CCR1 = 0;
	}



	//brake to v motor
	//    GPIOD->BSRRL = 0x0003; //set PD0 and PD1
	//    GPIOD->BSRRH = 0x0000; //reset nothing

}
void motor2_set_speed(signed char p_speed){

	if(p_speed > 0){

		//forward
	    GPIOD->BSRRL = 0x0008; //set   PD3
	    GPIOD->BSRRH = 0x0004; //reset PD2
	}
	else if(p_speed < 0){
		//backward
	    GPIOD->BSRRL = 0x0004; //set   PD2
	    GPIOD->BSRRH = 0x0008; //reset PD3
	}
	else{
		//brake to ground
	    GPIOD->BSRRL = 0x0000; //set nothing
	    GPIOD->BSRRH = 0x000C; //reset PD2 and PD3
	}

	//brake to v motor
	//    GPIOD->BSRRL = 0x000C; //set PD2 and PD3
	//    GPIOD->BSRRH = 0x0000; //reset nothing

}
void motor3_set_speed(signed char p_speed){

	if(p_speed > 0){

		//forward
	    GPIOD->BSRRL = 0x0020; //set   PD5
	    GPIOD->BSRRH = 0x0010; //reset PD4
	}
	else if(p_speed < 0){
		//backward
	    GPIOD->BSRRL = 0x0010; //set   PD4
	    GPIOD->BSRRH = 0x0020; //reset PD5
	}
	else{
		//brake to ground
	    GPIOD->BSRRL = 0x0000; //set nothing
	    GPIOD->BSRRH = 0x0030; //reset PD4 and PD5
	}

	//brake to v motor
	//    GPIOD->BSRRL = 0x0030; //set PD0 and PD1
	//    GPIOD->BSRRH = 0x0000; //reset nothing

}
void motor4_set_speed(signed char p_speed){

	if(p_speed > 0){

		//forward
	    GPIOD->BSRRL = 0x0080; //set   PD7
	    GPIOD->BSRRH = 0x0040; //reset PD6
	}
	else if(p_speed < 0){
		//backward
	    GPIOD->BSRRL = 0x0040; //set   PD6
	    GPIOD->BSRRH = 0x0080; //reset PD7
	}
	else{
		//brake to ground
	    GPIOD->BSRRL = 0x0000; //set nothing
	    GPIOD->BSRRH = 0x00C0; //reset PD6 and PD7
	}

	//brake to v motor
	//    GPIOD->BSRRL = 0x00C0; //set PD2 and PD3
	//    GPIOD->BSRRH = 0x0000; //reset nothing

}
