#include <stdio.h>

int main(void)
{	// 查看当前系统指定类型的大小是多少
	printf("Type int has a size of %zd bytes.\n", sizeof(int));
	printf("Type char has a size of %zd bytes.\n", sizeof(char));
	printf("Type long has a size of %zd bytes.\n", sizeof(long));
	printf("Type long long has a size of %zd bytes.\n", sizeof(long long));
	printf("Type double has a size of %zd bytes.\n", sizeof(double));
	printf("Type long double has a size of %zd bytes.\n", sizeof(long double));
	
	system("pause");
	
	return 0;
	
}