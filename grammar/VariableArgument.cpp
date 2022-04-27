/* * * * * * * * * 可变形参 * * * * * * * * * */
#include <cstdarg>
#include <iostream>
#include <initializer_list>
#include <string>

// initializer_list 标准库模型
void error_msg(std::initializer_list<std::string> il)
{
    for(auto beg = il.begin(); beg != il.end(); ++beg)
        // std::cout << il[1] << " "; // 元素永远是常量，无法更改，没有[]
        std::cout << *beg << " ";
    
    std::cout << std::endl;
}

// 省略符形参
void error_msg (int n, ...) 
{
    auto *p = &n + 1; // 硬编码，只能传递int类型

    for(int i = 0; i < n; ++i)
    {
        std::cout << p[n] << " ";
    }
    std::cout << std::endl;

    return;
}

void error_msg1 (int n, ...)
{
    va_list args; // 指向参数的指针
    va_start(args, n); // 初始化，指向第一个

    for(int i = 0; i < n; ++i)
    {
        std::cout << va_arg(args, const char*) << " ";
    }
    std::cout << std::endl;

    va_end(args);

    return;
}

void foo ( ... ); 

int main(int argc, char **argv)
{
    std::string expected = "actual";

    if (expected != "actual")
        error_msg({"functionX", expected, "actual"});
    else
        error_msg({"functionX", "okay"});

    error_msg(3, "hello", "world", "!");
    error_msg1(3, "hello", "world", "!");

    return 0;
}