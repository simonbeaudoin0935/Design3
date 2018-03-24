#ifndef MOTOR_H
#define MOTOR_H

typedef enum
{
  FORWARD,
  BACKWARD,
  BRAKE_TO_GROUND,
  BRAKE_TO_V_MOTOR
} MOTOR_DIRECTION;


void motors_init(void);

void change_motor_direction(unsigned int motor_id, MOTOR_DIRECTION motor_dir);

void motor1_set_speed(signed char p_speed);
void motor2_set_speed(signed char p_speed);
void motor3_set_speed(signed char p_speed);
void motor4_set_speed(signed char p_speed);

#endif //MOTOR_H
