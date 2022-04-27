/******************* 异常处理/后续继续补充 *******************/

#include <iostream>
#include <stdexcept>

int main(int argc, char** argv)
{
    int a = 1;
    int b = 0;
    std::cin >> b;
    
    if (b == 0)
        throw std::runtime_error("被除数不能等于0");

    std:: cout << a/b << std::endl;

    return 0;
}