#include <stdio.h>
#include <wiringPi.h>
#define wpi_PWM1 23
int main ()
{
	wiringPiSetup();
	pinMode(wpi_PWM1,PWM_OUTPUT);
	pwmWrite(wpi_PWM1, 500);
	
	
	return 0;
}
