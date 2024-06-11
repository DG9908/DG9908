#include <wiringPi.h>
#include <stdio.h>
int ps[40]; //pin number ; 40, pin status :default 0

int mode;
int TD[] ={1000,900,800,700,600,500,400,300,200,100};
void Toggle(int pin)
{
	ps[pin] = !ps[pin];
	digitalWrite(pin,ps[pin]);
	
}

void gpioisr()
{
		
		if(++mode>=10)
		{	
			mode=1;
			printf("intttttttttter ocurred\n");
		}
	
}

void allstop()
{
	int SW1= digitalRead(3);
	if(SW1==00)
	{
		digitalWrite(8,0);
		digitalWrite(9,0);
		digitalWrite(7,0);
		printf("End\n");
	}
}

int main ()
{
	wiringPiSetup();	//Pin number use case(wPi)
	pinMode(8,OUTPUT);//8,9,7:OUT 2:IN
	pinMode(9,OUTPUT);
	pinMode(7,OUTPUT);
	pinMode(2,INPUT);
	
	wiringPiISR(2,INT_EDGE_FALLING,gpioisr);
	wiringPiISR(3,INT_EDGE_FALLING,allstop);
	while(1)
	{
	int sw = digitalRead(2);

	Toggle(8);
	delay(TD[mode]);
	Toggle(9);
	delay(TD[mode]);
Toggle(7);
delay(TD[mode]);

	if(sw==0)//PUSHED
	{

		//mode++;
	}
	
	}
	return 0;
}
