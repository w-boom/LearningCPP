#include <iostream> 

int main(int argc, char** argv)
{
    int i = 1;
    const int bufSize = 512, bufSize2 = i; // const对象必须初始化
    const int &r1 = bufSize; // reference to const
    // r1 = 42;错误，常量引用不能更改
    // int &r2 = bufSize; 错误，一个非常量引用不能指向一个常量对象
    // 引用类型必须与其所引用对象的类型一致，但初始化常量引用时允许任意表达式作为初始值
    const int &r2 = i; 

    double dval = 3.14;
    const int &r3 = dval;
    std::cout << "The value of r3:" << r3 << std::endl;
    /* 相当于
    * const int temp = dval;
    * const int &r3 = temp;
    */

	return 0;
}