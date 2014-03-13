#include "derivative.h" /* include peripheral declarations */
#include "TFC\TFC.h"

int main(void)
{
	uint32_t t,i=0;
	//LineScanImage0;
	int ii=0;
	int deltaL, deltaR;
	int firstLevel, secondLevel;
	int steeringAngle;
	
	TFC_Init();
	
	for(;;)
	{	   
		//TFC_Task must be called in your main loop.  This keeps certain processing happy (I.E. Serial port queue check)
			TFC_Task();

			//This Demo program will look at the middle 2 switch to select one of 4 demo modes.
			//Let's look at the middle 2 switches
			switch((TFC_GetDIP_Switch()>>1)&0x03)
			{
			default:
				ii=0;

				
				for(;ii<=50; ii++){
					deltaL = LineScanImage0[63-ii] - LineScanImage0[62-ii];
					deltaR = LineScanImage0[63+ii] - LineScanImage0[65+ii];
					//may need to tweak '5' just abasic slope thresh hold
					if(deltaL<-5||deltaR<-5){
						//car continues straight(may want to adjust this later to be more accurate)
						steeringAngle = 0;
						break;
					}
					//where first derivative drop found on leftside
					
					if(deltaL>10&&(LineScanImage0[62-ii] - LineScanImage0[61-ii])){
						//may need to change 3 should be lower than first thresh holdslope
						while(deltaL>3&&ii<=50){
							ii++;
							deltaL = LineScanImage0[63-ii] - LineScanImage0[62-ii];
						}
						firstLevel = 63 - ii;
						while(deltaL<3&&i<=50){
							ii++;
							deltaL = LineScanImage0[63-ii] - LineScanImage0[62-ii];
						}
						secondLevel = 63 - ii;
						steeringAngle = (firstLevel + secondLevel)/2; 
						break;//don't check right side
					
					}
					if(deltaR>10&&(LineScanImage0[64+ii] - LineScanImage0[65+ii])){
					//may need to change 3 should be lower than first thresh holdslope
						while(deltaR>3&&ii<=50){
							ii++;
							deltaR = LineScanImage0[64+ii] - LineScanImage0[65+ii];
						}
						firstLevel = 64 + ii;
						while(deltaL<3&&ii<=50){
							ii++;
							deltaR = LineScanImage0[64+ii] - LineScanImage0[65+ii];
						}
							secondLevel = 64 + ii;
							steeringAngle = (firstLevel + secondLevel)/2; 
							break; //don't check anymore bits				
										
						}
				}
				steeringAngle = 0;//if passes a horizontal line
				
				
				
				
				break;
			
			case 3 :
			
				//Demo Mode 3 will be in Freescale Garage Mode.  It will beam data from the Camera to the 
				//Labview Application
				
		
				if(TFC_Ticker[0]>100 && LineScanImageReady==1)
					{
					 TFC_Ticker[0] = 0;
					 LineScanImageReady=0;
					 TERMINAL_PRINTF("\r\n");
					 TERMINAL_PRINTF("L:");
					 
					 	if(t==0)
					 		t=3;
					 	else
					 		t--;
					 	
						 TFC_SetBatteryLED_Level(t);
						
						 for(i=0;i<128;i++)
						 {
								 TERMINAL_PRINTF("%X,",LineScanImage0[i]);
						 }
						
						 for(i=0;i<128;i++)
						 {
								 TERMINAL_PRINTF("%X",LineScanImage1[i]);
								 if(i==127)
									 TERMINAL_PRINTF("\r\n",LineScanImage1[i]);
								 else
									 TERMINAL_PRINTF(",",LineScanImage1[i]);
						}										
							
					}
					


				break;
			}
	}
	
	return 0;
}
