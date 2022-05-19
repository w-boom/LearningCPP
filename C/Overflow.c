#include <stdio.h>

int main(void)
{
    /* int类型溢出会从-max开始 */
    /* unsigned int类型溢出会从0开始 */
	/* 浮点类型溢出会显示inf */
	
    int i = 2147483647;
    unsigned int j = 4294967295;
	float toobig = 3.4E38 * 100.0f;
	
    printf("%d %d %d\n", i, i+1, i+2);
    printf("%u %u %u\n", j, j+1, j+2);
    printf("%e", toobig);
	
	/* * * 增加浮点数 * * */		
	/*float a, b;
	* b = 2.0e20 + 1.0;
	* a = b - 2.0e20;
	* printf("%f \n", b);
	* printf("%f \n", a); */
	
    return 0;
}