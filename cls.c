#include <stdio.h>
int main()
{
	int x =10 , y =20;
	printf("\033[2J"); //esc / clear screen (escape sequence)
	while(1)
	{
		
	
		printf("\033[%d;%dH@@",y,x);
}
	return 0;
}
