#include <iostream> 

int main(int argc, char** argv)
{
   #include <iostream> 

int main(int argc, char** argv)
{
    int i = 1;
    int j = 2;
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

    // const指针
    /***********顶层const****************
    * 顶层const表示指针本身是个常量
    * 底层const表示指针所指的对象是个常量
    */
    // 顶层const指针
    int *const p1 = &i; 
    // 从右往左阅读，p1为常量对象，*代表为常量指针
    // 最后确定的是指针指向的是int对象
    // p1是指向i的指针，不变的是指针本身的值p1
    // p1 = &j; 错误，该指针本身是const常量对象

    // 底层const指针
    const int *p3 = &i;
    p3 = &j;
    const int *const p2 = &i; // p2是指向常量对象的常量指针
    std::cout << "The value of *p2:" << *p2 << std::endl;

	return 0;
}
}