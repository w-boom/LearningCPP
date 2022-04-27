/******************* 使用迭代器完成二分搜索 *******************/
#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
   std::vector<int> vec1(100,0);
   for (int i = 0; i < vec1.size(); i++)
   {
       vec1[i] = i;
   }

   int sought = 86; //二分搜索要找的数
   auto beg = vec1.begin(),  end = vec1.end();
   auto mid = vec1.begin() + (end - beg) / 2;
   // 其中注意end-beg 的类型是difference_type的带符号整型数
  
    // 当还有元素尚未检查并且还未找到sought时执行循环
    while (mid != end && *mid != sought) // mid = end已经搜索完所有元素
    {
        if (sought < *mid)
            end = mid;
        else
            beg = mid + 1;

        mid = beg + (end - beg) / 2;

    }

    std::cout << (int)(mid - vec1.begin()) << std::endl;

	return 0;
}