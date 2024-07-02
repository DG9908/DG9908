#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>


int fd;
int v1, v2, v3;
float f1, f2, f3;

void readSensors()
{
    
    wiringPiI2CWrite(fd, 3);
    delay(10);  
    v1 = wiringPiI2CRead(fd);
    f1 = (float)((v1 / 255.0) * 5.0);

    
    wiringPiI2CWrite(fd, 0);
    delay(10);  
    v2 = wiringPiI2CRead(fd);
    f2 = (float)((v2 / 255.0) * 5.0);

    
    wiringPiI2CWrite(fd, 1);
    delay(10);  
    v3 = wiringPiI2CRead(fd);
    float temp_voltage = (float)((v3 / 255.0) * 5.0) * 1000; 
    f3 = temp_voltage / 10; 
}

int main()
{
    fd = wiringPiI2CSetup(0x48);
    
    while(1)
    {
        readSensors();

       
        printf("VR: %d (%.1fV), Light: %d (%.1fV), Temperature: %d (%.1fC)\n", v1, f1, v2, f2, v3, f3);

        delay(500);  
    }

    return 0;
}
