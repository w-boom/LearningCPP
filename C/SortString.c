/* * * * 读入字符串，并排序 * * * */
#include <stdio.h>
#include <string.h>

#define SIZE 81
#define LIM 20
// 空字符串停止输入
#define HALT "" 

// 字符串排序函数
void stsrt(char *strings [], int num);
// 输入函数
char *s_gets(char *st, int n);

int main(void)
{
    char input[LIM][SIZE];
    // 内含指针变量的数组
    char *ptstr[LIM];
    // 输入计数
    int ct = 0;
    // 输出计数
    int k;

    printf("Input up to %d lines, and I will sort them.\n", LIM);
    printf("To stop, press the Enter key at a line's start.\n");
    while((ct < LIM) && (s_gets(input[ct], SIZE) != NULL) && (input[ct][0] != '\0'))
    {
        ptstr[ct] = input[ct];
        ct++;
    }

    stsrt(ptstr, ct);
    puts("\nHere's the sorted list:\n");

    for(k = 0; k < ct; k++)
    {
        puts(ptstr[k]);
    }

	system("pause");
    return 0;
}

/* * * * 字符串-指针-排序函数 * * * */
void stsrt(char *strings [], int num)
{
    char *temp;
    int top, seek;

    for(top = 0; top < num - 1; top++)
    {
        for(seek = top + 1; seek < num; seek++)
        {
            if(strcmp(strings[top], strings[seek]) > 0)
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
        }
    }
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin);

    if(ret_val)
    {
        while(st[i] != '\n' && st[i] != '\0')
            i++;

        if(st[i] == '\n')
            st[i] = '\0';
        else
            while(getchar() != '\n')
                continue;
    }

    return ret_val;
}