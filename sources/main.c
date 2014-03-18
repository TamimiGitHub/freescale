#include "derivative.h" /* include peripheral declarations */
#include "TFC\TFC.h"

int main(void)
{
	uint32_t i=0;
	//LineScanImage0;
	int ii=0;
	int deltaL, deltaR;
	int firstLevel, secondLevel;
	int steeringAngle;
	int samplenum = 8;
	int threshold=50*samplenum;
	int smallthreshold=50*samplenum;
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
				
				uint16_t  WorkingImage[128]={0};
				int sample = 0;
				for(;sample<3;){
					if(LineScanImageReady){
						int j=0;
						for(;j<128;j++) WorkingImage[j]=LineScanImage0[j];
						sample++;
					}
					
				}
									
				
			int L1, L2, R1, R2;				
				for(;ii<=50; ii++){
					L1 = WorkingImage[63-ii];
					L2 = WorkingImage[62-ii];
					R1 = WorkingImage[63+ii];
					R2 = WorkingImage[64+ii];
					deltaL = WorkingImage[63-ii] - WorkingImage[62-ii];
					deltaR = WorkingImage[63+ii] - WorkingImage[64+ii];
					
					if(deltaL<-threshold||deltaR<-threshold){
						//car continues straight(may want to adjust this later to be more accurate)
						steeringAngle = 0;
						TFC_SetServoLookup(0);// straight line to servos
						break;
					}
					//where first derivative drop found on leftside
					
					if(deltaL>threshold&&(WorkingImage[62-ii] - WorkingImage[61-ii])>threshold){
						//may need to change 3 should be lower than first thresh holdslope
						while(deltaL>smallthreshold&&ii<=50){
							ii++;
							deltaL = WorkingImage[63-ii] - WorkingImage[62-ii];
						}
						firstLevel = 63 - ii;
						while(deltaL<smallthreshold&&i<=50){
							ii++;
							deltaL = WorkingImage[63-ii] - WorkingImage[62-ii];
						}
						secondLevel = 63 - ii;
						steeringAngle = (firstLevel + secondLevel)/2; 
						TFC_SetServoLookup(steeringAngle-50);
						break;//don't check right side
					
					}
					if(deltaR>threshold&&(WorkingImage[64+ii] - WorkingImage[65+ii])>threshold){
					//may need to change 3 should be lower than first thresh holdslope
						while(deltaR>smallthreshold&&ii<=50){
							ii++;
							deltaR = WorkingImage[64+ii] - WorkingImage[65+ii];
						}
						firstLevel = 64 + ii;
						while(deltaL<smallthreshold&&ii<=50){
							ii++;
							deltaR = WorkingImage[64+ii] - WorkingImage[65+ii];
						}
							secondLevel = 64 + ii;
							steeringAngle = (firstLevel + secondLevel)/2; 
							TFC_SetServoLookup(steeringAngle-50);
							break; //don't check anymore bits				
										
						}
				}
				steeringAngle = 0;//if passes a horizontal line
				TFC_SetServoLookup(steeringAngle); // straight line to servos
				
				
				
				
				break;
			}
	}
	
	return 0;
}
