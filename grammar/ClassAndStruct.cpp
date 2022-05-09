#include <iostream>
#include <string>

class book
{
public:
    // 构造函数初始化列表
    // 为新创建的对象的数据成员赋初值 
    book():num(1){};
    // 默认构造函数
    // book() = default;
    int num;
};

struct bookStu
{
    int num;
};

// struct关键字定义类，则第一个访问说明符之前得成员是public；
// class关键字定义类，则为private
// 除此之外，struct关键的点是c/c++混合编程
// 比如函数接口设置到多平台，可设置为C接口，实现为C++,就必须用struct
int main()
{
    book book1;
    bookStu book2;
    // book1.num = 3;
    std::cout << book1.num << std::endl;
    std::cout << book2.num << std::endl;

    return 0;
}