/* * * * * * main()函数接收字符并输出 * * * * * */

#include <iostream>
#include <stdexcept>

// int main(int argc, char *argv[]) // C语言风格
int main(int argc, char **argv) // C++风格
{
	if (argc < 1)
	{
		return -1;
	}
	else
	{
		for(int i = 0; i < argc; ++i)
		{
			std::cout << argv[i] << std::endl;
			// 注意：argv[0]是程序的名字
		}
		std::cout << argc << std::endl;
		return 1;
	}
}