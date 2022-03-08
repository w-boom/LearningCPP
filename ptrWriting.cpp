#include <iostream> 
#include <typeinfo>

int main(int argc, char** argv)
{
    int *p1 = NULL, var1 = 0;
	int* p2 = NULL, var2 = 0;
	std::cout << "p1的类型为：" << typeid(p1).name() << std::endl;
	std::cout << "p2的类型为：" << typeid(p2).name() << std::endl;
	std::cout << "var1的类型为：" << typeid(var1).name() << std::endl;
	std::cout << "var2的类型为：" << typeid(var2).name() << std::endl;
	
	system("pause");
	return 0;
	// int *p1 = NULL, var1 = 0; 和 int* p2 = NULL, var2 = 0;两者并没有差别
}