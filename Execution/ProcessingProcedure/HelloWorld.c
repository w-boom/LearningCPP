#include <stdio.h>

#define PI 3.14
	
#undef PI

int main()
{
	printf("Hello World\n"); 
	double pi = PI;
	printf("%f", pi);

	
	return 0;
}