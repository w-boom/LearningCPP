#include <stdio.h>

union num
{
	int a;
	float b;
	char c;
};

int main(void)
{
	union num x;
	x.c = 'x';
	x.b = 3.14;
	x.a = 25;
	printf("%g, %c, %d", x.b, x.c, x.a);
	
	return 0;
}