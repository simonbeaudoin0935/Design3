#include "../../inc/Motor/Motor.h"

#include "stm32f4xx.h"

static void motor_1_init(void);
static void motor_2_init(void);
static void motor_3_init(void);
static void motor_4_init(void);

void motors_init()
{
  motor_1_init();
  motor_2_init();
  motor_3_init();
  motor_4_init();
}




void motor_1_init(void)
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




	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);		//Enables PORTB clock
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM10, ENABLE);		//Enables TIM10 clock

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;						//Setup pin 8
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;					//Alternate function (for TIM10)
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;					//Push-Pull
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;				//No pull-up/down
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;				//Max speed

	GPIO_Init(GPIOB, &GPIO_InitStruct);							//Configure PB8

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_TIM10);	//Configure PB8 as TIM10 alternate function

/*
	TIM10 is connected to APB2 bus, which is 168 MHz / 2 = 84 MHz
	APB2 timers have internal pll that double the frequency : 84 MHz *2 - 168 MHz
	TIM10 default frequency is then 168 MHz.
	We want a timer tick frequency that is the same across TIM10, TIM11, TIM13 and TIM14 : 84 MHz
	timer_tick_frequency = Timer_default_frequency / (prescaller_set + 1)
	timer_tick_frequency = 168 000 000 / (1 + 1) = 84 MHZ
	TIM 10 is 16 bit = 65 535
	We want a PWM frequency of 10 kHz
	TIM_Period = (timer_tick_frequency / PWM_frequency) - 1
	TIM_Period = (84000000 / 10000) - 1 = 83999
*/

	TIM_BaseStruct.TIM_Prescaler = 1;						//Gives a tick frequency of 84 MHz
	TIM_BaseStruct.TIM_CounterMode = TIM_CounterMode_Up;	//Counts up
	TIM_BaseStruct.TIM_Period = 8399;						//Gives PWM frequency of 10 kHz
	TIM_BaseStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_BaseStruct.TIM_RepetitionCounter = 0;

	TIM_TimeBaseInit(TIM10, &TIM_BaseStruct);				//Setup TIM10

	TIM_Cmd(TIM10, ENABLE);									//Starts TIM10


	TIM_OCStruct.TIM_OCMode = TIM_OCMode_PWM2;				//PWM mode 2 = Clear on compare match */
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
	TIM_OCStruct.TIM_Pulse = 1; /* 0% duty cycle */
	TIM_OC1Init(TIM10, &TIM_OCStruct);
	TIM_OC1PreloadConfig(TIM10, TIM_OCPreload_Enable);

// ******************* CONFIGURATION DES PINS DE CONTROLE 1 ET 2


	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);	//Enables PORTD clock




	//Initialiser la pins de controle du moteur
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOD, &GPIO_InitStruct);

// ******************* CONFIGURATION DES PINS DE L'ENCODEUR QUADRATURE


	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);	//Enable PORTE clock

	  //Configurer la fonction alternative avec timer 1
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource9,  GPIO_AF_TIM1);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource11, GPIO_AF_TIM1);

	  //Initialiser la pins de controle du moteur
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_9 | GPIO_Pin_11;
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOE, &GPIO_InitStruct);


	TIM_EncoderInterfaceConfig(TIM1,
	                           TIM_EncoderMode_TI12,
	                           TIM_ICPolarity_Rising,
	                           TIM_ICPolarity_Rising);
	TIM_SetAutoreload(TIM1, 0xffff);

	TIM_Cmd(TIM1, ENABLE);

}

void motor_2_init(void){

	//QUADRATURE : TIM2
	//  CH1 -> PA0
	//  CH2 -> PA1

	//PWM : TIM11
	//  CH1 : PB9

	//CTRL1 : PD2
	//CTRL2 : PD3

	  GPIO_InitTypeDef GPIO_InitStruct;

	  TIM_TimeBaseInitTypeDef TIM_BaseStruct;

	  TIM_OCInitTypeDef TIM_OCStruct;


	// ******************* CONFIGURATION DE LA PIN PWM

	/*  Configuration �lectrique de la pin  */

	  //activer la clock du port B
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	  //Initialiser la pin 9 avec fonction alternative
	  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
	  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	  GPIO_Init(GPIOB, &GPIO_InitStruct);

	  //Configurer la fonction alternative avec timer 11
	  GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_TIM11);

	/*  Configuration de la base du temps du timer  */

	  //Activer la clock du timer 10
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM11, ENABLE);


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
	    TIM_TimeBaseInit(TIM11, &TIM_BaseStruct);
	    /* Start count on TIM4 */
	    TIM_Cmd(TIM11, ENABLE);

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
	    TIM_OCStruct.TIM_Pulse = 1; /* 0% duty cycle */
	    TIM_OC1Init(TIM11, &TIM_OCStruct);
	    TIM_OC1PreloadConfig(TIM11, TIM_OCPreload_Enable);



	// ******************* CONFIGURATION DES PINS DE CONTROLE 1 ET 2

	  //activer la clock du port D
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	  //Aucune configuration alternative pour les pins de controle du moteur, juste deux gpio


	  //Initialiser la pins de controle du moteur
	  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
	  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	  GPIO_Init(GPIOD, &GPIO_InitStruct);

	// ******************* CONFIGURATION DES PINS DE L'ENCODEUR QUADRATURE

	  //activer la clock du port A
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	  //Configurer la fonction alternative avec timer 2
	  GPIO_PinAFConfig(GPIOA, GPIO_PinSource0, GPIO_AF_TIM2);
	  GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_TIM2);

	  //Initialiser la pins de controle du moteur
	  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	  GPIO_Init(GPIOA, &GPIO_InitStruct);


	  TIM_EncoderInterfaceConfig(TIM2,
	                             TIM_EncoderMode_TI12,
	                             TIM_ICPolarity_Rising,
	                             TIM_ICPolarity_Rising);
	  TIM_SetAutoreload(TIM2, 0xffff);

	  TIM_Cmd(TIM2, ENABLE);


	  //encodersReset();
}

void motor_3_init(void){
	//QUADRATURE : TIM3
	//  CH1 -> PC6
	//  CH2 -> PB5

	//PWM : TIM13
	//  CH1 : PA6

	//CTRL1 : PD4
	//CTRL2 : PD5

	  GPIO_InitTypeDef GPIO_InitStruct;

	  TIM_TimeBaseInitTypeDef TIM_BaseStruct;

	  TIM_OCInitTypeDef TIM_OCStruct;


	// ******************* CONFIGURATION DE LA PIN PWM

	/*  Configuration �lectrique de la pin  */

	  //activer la clock du port A
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	  //Initialiser la pin 6 avec fonction alternative
	  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
	  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	  GPIO_Init(GPIOA, &GPIO_InitStruct);

	  //Configurer la fonction alternative avec timer 11
	  GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_TIM13);

	/*  Configuration de la base du temps du timer  */

	  //Activer la clock du timer 13
	  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM13, ENABLE);


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
	    TIM_TimeBaseInit(TIM13, &TIM_BaseStruct);
	    /* Start count on TIM4 */
	    TIM_Cmd(TIM13, ENABLE);

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
	    TIM_OCStruct.TIM_Pulse = 1; /* 0% duty cycle */
	    TIM_OC1Init(TIM13, &TIM_OCStruct);
	    TIM_OC1PreloadConfig(TIM13, TIM_OCPreload_Enable);



	// ******************* CONFIGURATION DES PINS DE CONTROLE 1 ET 2

	  //activer la clock du port D
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	  //Aucune configuration alternative pour les pins de controle du moteur, juste deux gpio


	  //Initialiser la pins de controle du moteur
	  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
	  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	  GPIO_Init(GPIOD, &GPIO_InitStruct);

	// ******************* CONFIGURATION DES PINS DE L'ENCODEUR QUADRATURE

	  //activer la clock du port B et C
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

	  //Configurer la fonction alternative avec timer 3
	  GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_TIM3);
	  GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_TIM3);

	  //Initialiser la pins de controle du moteur
	  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
	  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	  GPIO_Init(GPIOC, &GPIO_InitStruct);

	  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
	  GPIO_Init(GPIOB, &GPIO_InitStruct);

	  TIM_EncoderInterfaceConfig(TIM3,
	                             TIM_EncoderMode_TI12,
	                             TIM_ICPolarity_Rising,
	                             TIM_ICPolarity_Rising);
	  TIM_SetAutoreload(TIM3, 0xffff);

	  TIM_Cmd(TIM3, ENABLE);


	  //encodersReset();
}

void motor_4_init(void){
	//QUADRATURE : TIM4
	//  CH1 -> PD12
	//  CH2 -> PD13

	//PWM : TIM14
	//  CH1 : PA7

	//CTRL1 : PD6
	//CTRL2 : PD7

	  GPIO_InitTypeDef GPIO_InitStruct;

	  TIM_TimeBaseInitTypeDef TIM_BaseStruct;

	  TIM_OCInitTypeDef TIM_OCStruct;


	// ******************* CONFIGURATION DE LA PIN PWM

	/*  Configuration �lectrique de la pin  */

	  //activer la clock du port A
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	  //Initialiser la pin 6 avec fonction alternative
	  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;
	  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	  GPIO_Init(GPIOA, &GPIO_InitStruct);

	  //Configurer la fonction alternative avec timer 11
	  GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_TIM14);

	/*  Configuration de la base du temps du timer  */

	  //Activer la clock du timer 13
	  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14, ENABLE);


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
	    TIM_TimeBaseInit(TIM14, &TIM_BaseStruct);
	    /* Start count on TIM4 */
	    TIM_Cmd(TIM14, ENABLE);

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
	    TIM_OCStruct.TIM_Pulse = 1; /* 0% duty cycle */
	    TIM_OC1Init(TIM14, &TIM_OCStruct);
	    TIM_OC1PreloadConfig(TIM14, TIM_OCPreload_Enable);



	// ******************* CONFIGURATION DES PINS DE CONTROLE 1 ET 2

	  //activer la clock du port D
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	  //Aucune configuration alternative pour les pins de controle du moteur, juste deux gpio


	  //Initialiser la pins de controle du moteur
	  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	  GPIO_Init(GPIOD, &GPIO_InitStruct);

	// ******************* CONFIGURATION DES PINS DE L'ENCODEUR QUADRATURE

	  //activer la clock du port D
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);


	  //Configurer la fonction alternative avec timer 3
	  GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4);
	  GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_TIM4);

	  //Initialiser la pins de controle du moteur
	  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13;
	  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	  GPIO_Init(GPIOD, &GPIO_InitStruct);



	  TIM_EncoderInterfaceConfig(TIM4,
	                             TIM_EncoderMode_TI12,
	                             TIM_ICPolarity_Rising,
	                             TIM_ICPolarity_Rising);
	  TIM_SetAutoreload(TIM4, 0xffff);

	  TIM_Cmd(TIM4, ENABLE);


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
	    TIM10->CCR1 = 1;
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
	    TIM11->CCR1 = ((8399 + 1) * p_speed) / 100 - 1;
	}
	else if(p_speed < 0){
		//backward
	    GPIOD->BSRRL = 0x0004; //set   PD2
	    GPIOD->BSRRH = 0x0008; //reset PD3
	    p_speed *= -1;
	    TIM11->CCR1 = ((8399 + 1) * p_speed) / 100 - 1;
	}
	else{
		//brake to ground
	    GPIOD->BSRRL = 0x0000; //set nothing
	    GPIOD->BSRRH = 0x000C; //reset PD2 and PD3
	    TIM11->CCR1 = 1;
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
	    TIM13->CCR1 = ((8399 + 1) * p_speed) / 100 - 1;
	}
	else if(p_speed < 0){
		//backward
	    GPIOD->BSRRL = 0x0010; //set   PD4
	    GPIOD->BSRRH = 0x0020; //reset PD5
	    p_speed *= -1;
	    TIM13->CCR1 = ((8399 + 1) * p_speed) / 100 - 1;
	}
	else{
		//brake to ground
	    GPIOD->BSRRL = 0x0000; //set nothing
	    GPIOD->BSRRH = 0x0030; //reset PD4 and PD5
	    TIM13->CCR1 = 1;
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
	    TIM14->CCR1 = ((8399 + 1) * p_speed) / 100 - 1;
	}
	else if(p_speed < 0){
		//backward
	    GPIOD->BSRRL = 0x0040; //set   PD6
	    GPIOD->BSRRH = 0x0080; //reset PD7
	    p_speed *= -1;
	    TIM14->CCR1 = ((8399 + 1) * p_speed) / 100 - 1;
	}
	else{
		//brake to ground
	    GPIOD->BSRRL = 0x0000; //set nothing
	    GPIOD->BSRRH = 0x00C0; //reset PD6 and PD7
	    TIM14->CCR1 = 1;
	}

	//brake to v motor
	//    GPIOD->BSRRL = 0x00C0; //set PD2 and PD3
	//    GPIOD->BSRRH = 0x0000; //reset nothing

}


void go_forward(signed char p_speed){
	motor_1_set_speed(p_speed);
	motor_3_set_speed(p_speed);
}
void go_sideward(signed char p_speed){
	motor_2_set_speed(p_speed);
	motor_4_set_speed(p_speed);

}
void go_rotate(signed char p_speed);
