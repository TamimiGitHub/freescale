#include "TFC\TFC.h"
#include "derivative.h"


#define FTM0_MOD_VALUE	(int)((float)(PERIPHERAL_BUS_CLOCK)/TFC_MOTOR_SWITCHING_FREQUENCY)

#define FTM0_CLOCK                                   	      (CORE_CLOCK/2)
#define FTM0_CLK_PRESCALE                                 	   0  // Prescale Selector value - see comments in Status Control (SC) section for more details
#define FTM0_OVERFLOW_FREQUENCY 5000							  //
#define	M(i) 	(i + 50.0)/100.0

/**********************************************************************************************/

static const float PWMtable[101]=
{
	/* Assume User input is correct
	if(MotorA>100.0)
		MotorA = 100.0;
	else if(MotorA<-100.0)
		MotorA = -100.0;
	
	if(MotorB>100.0)
			MotorB = 100.0;
		else if(MotorB<-100.0)
			MotorB = -100.0;
	*/
			M(-50),
			M(-49),
			M(-48),
			M(-47),
			M(-46),
			M(-45),
			M(-44),
			M(-43),
			M(-42),
			M(-41),
			M(-40),
			M(-39),
			M(-38),
			M(-37),
			M(-36),
			M(-35),
			M(-34),
			M(-33),
			M(-32),
			M(-31),
			M(-30),
			M(-29),
			M(-28),
			M(-27),
			M(-26),
			M(-25),
			M(-24),
			M(-23),
			M(-22),
			M(-21),
			M(-20),
			M(-19),
			M(-18),
			M(-17),
			M(-16),
			M(-15),
			M(-14),
			M(-13),
			M(-12),
			M(-11),
			M(-10),
			M(-9),
			M(-8),
			M(-7),
			M(-6),
			M(-5),
			M(-4),
			M(-3),
			M(-2),
			M(-1),
			M(0),
			M(1),
			M(2),
			M(3),
			M(4),
			M(5),
			M(6),
			M(7),
			M(8),
			M(9),
			M(10),
			M(11),
			M(12),
			M(13),
			M(14),
			M(15),
			M(16),
			M(17),
			M(18),
			M(19),
			M(20),
			M(21),
			M(22),
			M(23),
			M(24),
			M(25),
			M(26),
			M(27),
			M(28),
			M(29),
			M(30),
			M(31),
			M(32),
			M(33),
			M(34),
			M(35),
			M(36),
			M(37),
			M(38),
			M(39),
			M(40),
			M(41),
			M(42),
			M(43),
			M(44),
			M(45),
			M(46),
			M(47),
			M(48),
			M(49),
			M(50)
};

void TFC_SetPWMLookup(int setA, int setB)
{
	// To make sure speeds are within range: -50-50
	if(setA>50.0)
		setA = 50.0;
	else if(setA<-50.0)
		setA = -50.0;
	
	if(setB>50.0)
		setB = 50.0;
		else if(setB<-50.0)
			setB = -50.0;
	
	
	setA += 50;
	setB += 50;
	
	TPM0_C2V = ((float)TPM0_MOD * PWMtable[setA]);
	TPM0_C3V = TPM0_C2V;
	TPM0_C0V =  ((float)TPM0_MOD * PWMtable[setB]);
	TPM0_C1V = TPM0_C0V;

}


void TFC_InitMotorPWM()
{
	//Clock Setup for the TPM requires a couple steps.

	
    //1st,  set the clock mux
    //See Page 124 of f the KL25 Sub-Family Reference Manual, Rev. 3, September 2012
    SIM_SOPT2 |= SIM_SOPT2_PLLFLLSEL_MASK;// We Want MCGPLLCLK/2 (See Page 196 of the KL25 Sub-Family Reference Manual, Rev. 3, September 2012)
    SIM_SOPT2 &= ~(SIM_SOPT2_TPMSRC_MASK);
    SIM_SOPT2 |= SIM_SOPT2_TPMSRC(1); //We want the MCGPLLCLK/2 (See Page 196 of the KL25 Sub-Family Reference Manual, Rev. 3, September 2012)


	//Enable the Clock to the FTM0 Module
	//See Page 207 of f the KL25 Sub-Family Reference Manual, Rev. 3, September 2012
	SIM_SCGC6 |= SIM_SCGC6_TPM0_MASK;
    
    //The TPM Module has Clock.  Now set up the peripheral
    
    //Blow away the control registers to ensure that the counter is not running
    TPM0_SC = 0;
    TPM0_CONF = 0;
    
    //While the counter is disabled we can setup the prescaler
    
    TPM0_SC = TPM_SC_PS(FTM0_CLK_PRESCALE);
    
    //Setup the mod register to get the correct PWM Period
    
    TPM0_MOD = FTM0_CLOCK/(1<<FTM0_CLK_PRESCALE)/FTM0_OVERFLOW_FREQUENCY;
    
    //Setup Channels 0,1,2,3
    TPM0_C0SC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK;
    TPM0_C1SC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK; // invert the second PWM signal for a complimentary output;
    TPM0_C2SC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK;
    TPM0_C3SC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK; // invert the second PWM signal for a complimentary output;
    
    
    //Enable the Counter
    
    //Set the Default duty cycle to 50% duty cycle
    TFC_SetPWMLookup(0.0,0.0);
    
    //Enable the TPM COunter
    TPM0_SC |= TPM_SC_CMOD(1);
    
    
    //Enable the FTM functions on the the port
    PORTC_PCR1 = PORT_PCR_MUX(4);
    PORTC_PCR2 = PORT_PCR_MUX(4);     
    PORTC_PCR3 = PORT_PCR_MUX(4);  
    PORTC_PCR4 = PORT_PCR_MUX(4);  

}


/* This is done by TFC_SetPWMLookup ()
void TFC_SetMotorPWM(float MotorA , float MotorB)
{
	
	if(MotorA>50.0)
		MotorA = 50.0;
	else if(MotorA<-50.0)
		MotorA = -50.0;
	
	if(MotorB>50.0)
			MotorB = 50.0;
		else if(MotorB<-50.0)
			MotorB = -50.0;
		
	TPM0_C2V = ((float)TPM0_MOD * ((MotorA + 50.0)/100.0));
	TPM0_C3V = TPM0_C2V;
	TPM0_C0V = ((float)TPM0_MOD * ((MotorB + 50.0)/100.0));
	TPM0_C1V = TPM0_C0V;

}
*/

