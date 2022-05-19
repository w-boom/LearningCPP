#include <stdio.h>

int main(void)
{
	int age;
	float assets;
	char pet[30];
	
	printf("Enter your age, assets, and favorite pet.\n");
	// 读取基本变量类型的值，在变量名前加&
	scanf("%d%f", &age, &assets);
	// 读入字符数组，不要使用&
	// 字符数组，pet为数组起始地址
	scanf("%s", pet);
	printf("%d$%.2f%s\n", age, assets, pet);
	
	return 0;
	
}