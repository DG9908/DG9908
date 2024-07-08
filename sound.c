#include <stdio.h>
#include <wiringPi.h>
#define wPi_PWM1 23
int PSC = 19;			//분주 설정
int RANGE = 100;		


enum {DO = 0, Do, RE , Re , MI , FA , Fa , SL , Sl , LA , La ,  CI}; //   안에서 문자로 되어있는 기호들을 정수로 명령해줌

int pitch[] = { 262 , 277, 294 , 311 , 330 ,349 , 370 ,392 ,415 , 440 ,466 ,494};
int range[12];
int song [] = {SL,SL,LA,LA,SL,SL,MI,SL,SL,MI,MI,RE,
			   SL,SL,LA,LA,SL,SL,MI,SL,MI,RE,MI,DO,-1};
int rythm[] = {4,4,4,4,4,4,2,4,4,4,4,4,
			   4,4,4,4,4,4,2,4,4,4,8,4};
void calcRange() // calc Range Values using Pitch data
{
	for (int i = 0; i < 12; i++) 
	{
        range[i] =19200000 / (PSC * pitch[i]);
	}
	
}
void playSound(int um, int rthm) 	// um : pitch , len : rythm
{
	
	pwmSetClock(PSC); 	// 1MHz 까지 컨트롤이 가능한 상수를 정의 -> Prescaler : 1MHz
	pwmSetRange(range[um]);   // Range 
	pwmWrite(wPi_PWM1,range[um]/2); // 음정이 바뀌면서 범위가 바껴서 range[um] / 2 로 설정  
	delay(2000 / rthm);

}	



int main()
{
	wiringPiSetup();
	pinMode(wPi_PWM1,PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);
	calcRange();
	for(int i = 0 ; song[i] != -1; i++)
	{
		playSound(song[i],rythm[i]);
	}
	pwmWrite(wPi_PWM1, 0);
	return 0;
}
