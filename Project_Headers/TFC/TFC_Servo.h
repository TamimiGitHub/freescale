#ifndef TFC_PWM_SERVO_H_
#define TFC_PWM_SERVO_H_

void TFC_InitServos();
void TFC_SetServo(float Position);
void TFC_SetServoDutyCycle(float DutyCycle);
void TFC_MoveServo(float *current,float increment);
void TFC_SetServoC(float *current, float setTo);
void TFC_SetServoLookup(int setTo);
void TFC_MoveServoLookup(int increment);

#endif /* TFC_PWM_SERVO_H_ */
