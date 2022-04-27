
#include <iostream>
#include <string>
 
void func(int* num)
{
    std::cout << "this is the ptr function..." << std::endl;
}
 
void func(int num)
{
    std::cout << "this is the normal function..." << std::endl;
}
 
int main(int argc, char** argv)
{
    //func(NULL); // 高版本二义性，低版本会识别为0
	func(nullptr);
	func(0);
	/*****************null与nullptr*******************
	* c中，#define NULL ((void*)0)，C++中不能将void *类型的指针隐式转换成其他指针类
	* c++中，#define NULL 0
	* 完整的定义：
	* #undef NULL
	* #if defined(__cplusplus)
	* #define NULL 0
	* #else
	* #define NULL ((void *)0)
	* #endif
	*/
	system("pause");
	return 0;
}