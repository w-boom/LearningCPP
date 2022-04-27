#include <stdio.h>
#include <stdlib.h>

// C语言接口与实现中的strcpy字符串复制
char *strcpy1(char *dst, const char *src)
{
    char *s = dst;

    // 这种方式是为了表明赋值操作并非笔误
    while ((*dst++ = *src++) != '\0')
    // while (*dst++ = *src++)
        ;

    return s;
}

int main()
{
	char str[] = "1234";
    char *p1 = str;
    char *p2 = (char *)malloc(5 * sizeof(char));

    // 动态分配内存
    // 要保证分配的内存不小于需要的内存
    // 避免函数返回指针
    // 如果内部分配内存的话可能导致外部调用不知道需要分配多少内存
    // 内部动态分配内存，外部不知道需不需要释放内存，怎么释放，可能会造成内存泄漏
	// 如果需要静态变量等，可以采用上下文的编程方法
    
    p2 = strcpy1(p2, p1);
	
	printf("The result is %c \n", p2[1]);

    free(p2);
    // 动态分配内存是在堆上进行的，函数内部分配内存是在栈上进行的
    // 动态分配内存需要手动释放
    // 内部变量则不需要 
    // 所以这里必须手动释放p2,但p1不需要

	return 0;
}              