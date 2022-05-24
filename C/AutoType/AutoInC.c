#include <stdio.h>

int main(void)
{
   double value1 = 5.4, value2 = 4.5;
   // auto 在C语言中可以不初始化
   auto val;
   val = value2;
   printf("%d\n", val);
   // 先相加后转换
   val = value1 + value2;
   printf("val占位：%d\n", sizeof(val));
   printf("%d\n", val);

   return 0;
}