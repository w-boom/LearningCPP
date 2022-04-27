#include <iostream>

int main()
{
	unsigned u = 10, j = 20;
    int i = -42;
    std::cout << u - j << std::endl;
 	
	// for(unsigned u = 10; u >= 0; --u)
	//	std::cout << u << std::endl;
	// * 当u=-1时并不满足无符号数的要求，-1会自动转换成一个合法的无符号数
	// * 不要混用带符号类型和无符号类型，带符号类型会自动转换为无符号类型
	return 0;
}