/* * * * 一本书得图书目录 * * * */
#include <stdio.h>
#include <string.h>

/* 输入函数 */
char *s_gets(char *st, int n);

#define MAXTITL 41  // 书名得最大长度+1
#define MAXAUTL 31  // 作者姓名得最大长度+1

/* 结构模板： 标记是book */
struct book{
	char title[MAXTITL];  // 书名
	char author[MAXAUTL]; // 作者名
	float value;          // 价格
};

int main(void)
{
	// 把library声明为一个book类型的变量
	struct book library;
	
	printf("Please enter the book title.\n");
	s_gets(library.title, MAXTITL);
	printf("Now enter the author.\n");
	s_gets(library.author, MAXAUTL);
	printf("Now enter the value.\n");
	scanf("%f", &library.value);
	printf("%s by %s: $%.2f\n", library.title, library.author, library.value);
	printf("%s:\"%s\"($%.2f)\n", library.author, library.title, library.value);
	printf("Done.\n");
	
	system("pause");
	return 0;
}

char *s_gets(char *st, int n)
{
	char *ret_val;
	char *find;
	
	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		find = strchr(st, '\n'); // 查找换行符
		if(find)
			*find = '\0';        // 放置空字符
		else
			while(getchar() != '\n')
				continue;        // 处理输入行中剩余的字符	
	}
	
	return ret_val;
}