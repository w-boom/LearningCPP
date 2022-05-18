#include <stdio.h>

int main(void)
{
    /* int类型溢出会从-max开始 */
    /* unsigned int类型溢出会从0开始 */
    int i = 2147483647;
    unsigned int j = 4294967295;
    printf("%d %d %d\n", i, i+1, i+2);
    printf("%u %u %u\n", j, j+1, j+2);

    return 0;
}