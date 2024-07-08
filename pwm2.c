#include <stdio.h>
#include <wiringPi.h>
#define wpi_22 7
#include <softPwm.h>


	int main(int n, char *s[])
{
    if (n < 2)
    {
        printf("usage : pwm2 [duty_rate(%%)] [period]\n\n");
        printf("		period = 10 ms if empty \n\n");
	printf(" 		default value : period =10ms,DR =50%%\n\n");
       // return 1;
    }
    
    int dr, drh,  period = 10; 
    if (n > 1) sscanf(s[1], "%d", &dr);
    if (n > 2) sscanf(s[2], "%d", &period);
    drh = (dr * period) / 100; //MARK TIME 
    //drl = period - drh; 	//SPACE TIME

	wiringPiSetup();
	pinMode(wpi_22,OUTPUT);
	pwmSetMode(PWM_MODE_MS);// MS = MARK & space
	
	softPwmCreate(wpi_22,drh,period);
	//softPwmWrite(wpi_22,70);
	
	delay(5000);
	softPwmStop(wpi_22);
	return 0;
}
