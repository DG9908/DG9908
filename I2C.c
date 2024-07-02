#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

int main()
{
	printf("\033[2J"); //clear screen
    int fd = wiringPiI2CSetup(0x48);  

    
      while(1)
    {
        wiringPiI2CWrite(fd, 00);  
        wiringPiI2CRead(fd);
        int x = (wiringPiI2CRead(fd) * 80) / 255;  // 0 ~255
        delay(100);

        wiringPiI2CWrite(fd, 01);  
        wiringPiI2CRead(fd);
        int y = (wiringPiI2CRead(fd) * 24) /255;
               
        delay(100);

       // wiringPiI2CWrite(fd, 3);  
      //  wiringPiI2CRead(fd);
      //  v3 = wiringPiI2CRead(fd);
     //  f3 = (float)((v3/255.0)*5.0);     
		printf("\033[%d;%dH{%d %d}\n", y , x , x, y);
        
        delay(500);
    }
}
