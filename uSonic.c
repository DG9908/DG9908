

#include <stdio.h>
#include <wiringPi.h>
#define TRIG 8
#define ECHO 9
double Dist ()
{
	//TRIG Signal 
	digitalWrite(TRIG,1);
	delayMicroseconds(10);
	digitalWrite(TRIG,0);
	delayMicroseconds(200);
	
	// while (digitalRead(ECHO) !=0);	//wait for burst START
	// wait for ECHO SIGNAL
	while (digitalRead(ECHO) !=1);	//wait for ECHO HIGH
	
	while(1)
	{
		int    v = digitalRead(ECHO);
		if (v == 0) break;
	}
	int t1 = micros();				//Get current START time(in micro Sec)
	while (digitalRead(ECHO) !=0);	//Wait for ECHO LOW
	int t2 = micros();

	return (t2 - t1) * 0.017;


}


