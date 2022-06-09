#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    /* C99中加入_Bool */

    _Bool f = 5; 
    printf("%d", f);
	
	/* c99 <stdbool.h> */
	bool a = true, b = false;
    printf("%d\n", a&&b);
    printf("%d\n", a||b);
    printf("%d\n", !b);
	
	system("pause");

    return 0;
}
// https://en.cppreference.com/w/c/types/boolean
 
