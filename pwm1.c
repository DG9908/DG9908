#include <stdio.h>
#include <wiringPi.h>
#define wpi_22 22

int main(int n, char *s[])
{
    if (n < 2)
    {
        printf("usage : pwm1 [duty_rate(%%)] [period]\n\n");
        return 1;
    }
    
    int dr, drh, drl, period = 10; 
    sscanf(s[1], "%d", &dr);
    if (n > 2) 
    {
        sscanf(s[2], "%d", &period);
    }
    
    drh = (dr * period) / 100;
    drl = period - drh;

    wiringPiSetup(); 
    
    pinMode(wpi_22, OUTPUT);
    for (int i = 0; i < 500; i++)
    {
        digitalWrite(wpi_22, 1);
        delay(drh);
        digitalWrite(wpi_22, 0);
        delay(drl);
    }
    
    return 0;
}
