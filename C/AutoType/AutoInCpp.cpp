#include <iostream>

int main(void)
{
   double value1 = 5.4, value2 = 4.5;
   // auto 在C++语言中必须初始化
   auto val = value1 + value2;

   std::cout << val << std::endl;
   std::cout << "val占位：" << sizeof(val) << std::endl;

   return 0;
}