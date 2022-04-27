#include <iostream>

int main()
{
    std::cout << -sizeof(1) << std::endl;
    std::cout << sizeof(1) << std::endl;
    std::cout << sizeof(int) << std::endl;
    std::cout << -sizeof(int) << std::endl;
    std::cout << int(-sizeof(int)) << std::endl;

    return 0;
}