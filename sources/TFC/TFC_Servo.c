#include "TFC\TFC.h"


#define FTM1_CLOCK                                                                  (CORE_CLOCK)
#define FTM1_CLK_PRESCALE                                  						     6// Prescale Selector value - see comments in Status Control (SC) section for more details
#define FTM1_OVERFLOW_FREQUENCY 50  // Desired Frequency of PWM Signal - Here 60Hz => ~17ms period
// use these to dial in servo steering to your particular servo
#define SERVO_MIN_DUTY_CYCLE                                          (float)(.00160*FTM1_OVERFLOW_FREQUENCY)  // The number here should be be *pulse width* in seconds to move servo to its left limit
#define SERVO_MAX_DUTY_CYCLE                                         (float)(.00235*FTM1_OVERFLOW_FREQUENCY)  // The number here should be be *pulse width* in seconds to move servo to its Right limit
#define	S(i)	(((i + 50.0)/100.0)*(SERVO_MAX_DUTY_CYCLE - SERVO_MIN_DUTY_CYCLE) + SERVO_MIN_DUTY_CYCLE)
/**********************************************************************************************/

//Position is -1.0 to 1.0.   Use SERVO_X_MIN_DUTY_CYCLE and SERVO_MAX_DUTY_CYCLE  to calibrate the extremes
void TFC_SetServo(float Position)
{
                              TFC_SetServoDutyCycle((((Position + 1.0)/2)*(SERVO_MAX_DUTY_CYCLE - SERVO_MIN_DUTY_CYCLE))+SERVO_MIN_DUTY_CYCLE);
               
}

void TFC_SetServoDutyCycle(float DutyCycle)
{
          TPM1_C0V = TPM1_MOD * DutyCycle;

}

/******************************************* Function to control Interrupt ************************************/
volatile unsigned char ServoTickVar;

void FTM1_IRQHandler()
{
               //Clear the overflow mask if set.   According to the reference manual, we clear by writing a logic one!
               if(TPM1_SC & TPM_SC_TOF_MASK)
                              TPM1_SC |= TPM_SC_TOF_MASK;
               
               if (ServoTickVar < 0xff)//if servo tick less than 255 count up... 
                              ServoTickVar++;
  
}

/**
 * This is the lookup table for TFC_SetServoLookup.
 */
static const float lookupDC[101]=
{
		S(-50),
		S(-49),
		S(-48),
		S(-47),
		S(-46),
		S(-45),
		S(-44),
		S(-43),
		S(-42),
		S(-41),
		S(-40),
		S(-39),
		S(-38),
		S(-37),
		S(-36),
		S(-35),
		S(-34),
		S(-33),
		S(-32),
		S(-31),
		S(-30),
		S(-29),
		S(-28),
		S(-27),
		S(-26),
		S(-25),
		S(-24),
		S(-23),
		S(-22),
		S(-21),
		S(-20),
		S(-19),
		S(-18),
		S(-17),
		S(-16),
		S(-15),
		S(-14),
		S(-13),
		S(-12),
		S(-11),
		S(-10),
		S(-9),
		S(-8),
		S(-7),
		S(-6),
		S(-5),
		S(-4),
		S(-3),
		S(-2),
		S(-1),
		S(0),
		S(1),
		S(2),
		S(3),
		S(4),
		S(5),
		S(6),
		S(7),
		S(8),
		S(9),
		S(10),
		S(11),
		S(12),
		S(13),
		S(14),
		S(15),
		S(16),
		S(17),
		S(18),
		S(19),
		S(20),
		S(21),
		S(22),
		S(23),
		S(24),
		S(25),
		S(26),
		S(27),
		S(28),
		S(29),
		S(30),
		S(31),
		S(32),
		S(33),
		S(34),
		S(35),
		S(36),
		S(37),
		S(38),
		S(39),
		S(40),
		S(41),
		S(42),
		S(43),
		S(44),
		S(45),
		S(46),
		S(47),
		S(48),
		S(49),
		S(50)
};

/**
 * TFC_SetServoLookup: Sets servo to a certain angle using a lookup tble stored in flash
 * 
 * current: global state tracking variable
 * setTo: position to set servo to; int btwn -50 and 50 (inclusive); -50: left, 50: right
 */
volatile int current;
void TFC_SetServoLookup(int setTo)
{
	current = setTo; // update state tracker
	TPM1_C0V = TPM1_MOD * lookupDC[setTo + 50]; // offset and make register modifications
}

/**
 * TFC_MoveServoLookup: Move servo by an amount from it's present position
 * 
 * current: global state tracking variable
 * increment: amount to move servo; current + increment cannot have a magnitude greater than 50
 */
void TFC_MoveServoLookup(int increment)
{
	current += increment; // update state tracker
	TPM1_C0V = TPM1_MOD * lookupDC[current + increment + 50]; // offset and make register modifications
}

/**
 * TFC_MoveServo: Move servo by a certain amount.
 * 
 * current: current position stored in main and passed to function using an ampersand (e.g. TFC_MoveServo(&a,20.0);)
 * increment: amount to move servo by; the sum of increment and current has to be within the range -100 to 100 (inclusive) (as servo can operate in range of a current value from -100 to 100) 
 */
void TFC_MoveServo(float *current, float increment)
{
	if(increment+*current<=100 && increment+*current>=-100)
	{
		//move as instructed; increment
		TFC_SetServoDutyCycle(((((*current+increment) + 100)/200.0)*(SERVO_MAX_DUTY_CYCLE - SERVO_MIN_DUTY_CYCLE))+SERVO_MIN_DUTY_CYCLE);
		*current+=increment;
	}
}

/**
 * TFC_SetServoC: Sets servo to certain angle
 * 
 * current: current position stored in main and passed to function using an ampersand (e.g. TFC_MoveServo(&a,20.0);)
 * setTo: position you want to set to; between -100 and 100 (inclusive); -100: left, 100: right
 */
void TFC_SetServoC(float *current, float setTo)
{
	if(setTo<=100 && setTo>=-100)
	{
		//move as instructed; increment
		TFC_SetServoDutyCycle((((setTo + 100)/200.0)*(SERVO_MAX_DUTY_CYCLE - SERVO_MIN_DUTY_CYCLE))+SERVO_MIN_DUTY_CYCLE);
		*current=setTo;
	}
}

void TFC_InitServos()
{
               
               //Clock Setup for the TPM requires a couple steps.
               
    
				
               //1st,  set the clock mux
               //See Page 124 of f the KL25 Sub-Family Reference Manual, Rev. 3, September 2012
               SIM_SOPT2 |= SIM_SOPT2_PLLFLLSEL_MASK;// We Want MCGPLLCLK/2 (See Page 196 of the KL25 Sub-Family Reference Manual, Rev. 3, September 2012)
               SIM_SOPT2 &= ~(SIM_SOPT2_TPMSRC_MASK);
               SIM_SOPT2 |= SIM_SOPT2_TPMSRC(1); //We want the MCGPLLCLK/2 (See Page 196 of the KL25 Sub-Family Reference Manual, Rev. 3, September 2012)
  

				//Enable the Clock to the FTM0 Module
				//See Page 207 of f the KL25 Sub-Family Reference Manual, Rev. 3, September 2012
				SIM_SCGC6 |= SIM_SCGC6_TPM1_MASK; 
               
               //The TPM Module has Clock.  Now set up the peripheral
               
               //Blow away the control registers to ensure that the counter is not running
               TPM1_SC = 0;
               TPM1_CONF = 0;
               
               //While the counter is disabled we can setup the prescaler
               
               TPM1_SC = TPM_SC_PS(FTM1_CLK_PRESCALE);
               TPM1_SC |= TPM_SC_TOIE_MASK; //Enable Interrupts for the Timer Overflow
               
               //Setup the mod register to get the correct PWM Period
               
               TPM1_MOD = FTM1_CLOCK/(1<<(FTM1_CLK_PRESCALE+1))/FTM1_OVERFLOW_FREQUENCY;
               
               //Setup Channels 0 and 1
               
               TPM1_C0SC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK;
               
               //Enable the Counter
               
               //Set the Default duty cycle to servo neutral
               TFC_SetServo(0.0);
               
               //Enable the TPM COunter
               TPM1_SC |= TPM_SC_CMOD(1);
               
               //Enable TPM1 IRQ on the NVIC
               enable_irq (INT_TPM1-16);
              
               //Enable the FTM functions on the the port
               
               PORTB_PCR0 = PORT_PCR_MUX(3);
                              
}
