#include <stdio.h>
#define STOP '#'

int main(void)
{
	// getchar, putchar只处理字符
	char ch;
	unsigned int spaces = 0, newlines = 0, other= 0;
	printf("Enter input (%c to stop):\n", STOP);
	while((ch = getchar()) != STOP)
	{
		switch (ch)
		{
			case ' ':
				spaces++;
				break;
			case '\n':
				newlines++;
				break;
			default:
				other++;
		}
	}
	printf("\n");
	printf("Character Count:\n");
	printf("----------------\n");
	printf("Spaces: %u\n"
		   "Newlines: %u\n"
		   "Other: %u\n", spaces, newlines, other);

    system("pause");
	return 0;
}