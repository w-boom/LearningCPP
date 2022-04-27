#include <iostream> 
#include <typeinfo>

int main(int argc, char** argv)
{
    int ival = 1024;
    int *pi = &ival;
    int **ppi = &pi;
    int *&r = pi; 
    // 从右向左阅读r的定义，离变量名最近的符号对变量的
    // 类型有最直接的影响，因此r是一个引用


	std::cout << "The value of ival:" << ival << "\n"
              << "The value of pi:" << pi << "\n"
              << "indirect value:" << *pi << "\n"
              << "The value of ppi:" << ppi << "\n"
              << "doubly indirect value:" << **ppi << "\n"
              << "The value of r:" << r << "\n"
              << "The value of *r:" << *r << "\n"
               << std::endl;
    
    *r = 1; // 解引用r也就是pi指向的对象，将pi指向的对象赋值为1
    std::cout << "The value of ival:" << ival << "\n"
              << "The value of pi:" << pi << "\n"
              << "indirect value:" << *pi << "\n"
              << "The value of ppi:" << ppi << "\n"
              << "doubly indirect value:" << **ppi << "\n"
              << "The value of r:" << r << "\n"
              << "The value of *r:" << *r << "\n"
               << std::endl;
	
    /************ 指针、指向指针的指针和指向指针的引用********
    * 指针存放的是指针指向的对象的地址
    * 指向指针的指针存放的是指向的指针的地址
    * 指向指针的引用就是对指针的引用或者是指针的别名
    */
	return 0;
}