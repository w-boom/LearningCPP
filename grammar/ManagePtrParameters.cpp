/******************* 管理指针形参 *******************/

#include <iostream>

void print(const char *cp)
{
    if (cp)
        while (*cp)
            std::cout << *cp++;

    std::cout << std::endl;
}

void print(const int *cp)
{
    if (cp)
        while (*cp)
            std::cout << *cp++;

    std::cout << std::endl;
}

void print (const int *beg, const int *end)
{
    while (beg != end)
        std::cout << *beg++;
    
    std::cout << std::endl;
}

void print (const int ia[], std::size_t size)
{
    for (std::size_t i = 0; i != size; ++i)
    {
        std::cout << ia[i];
    }
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    int i[3] = {0, 2, 3};
    char j[3] = "12";
    int m[] = {0, 1, 2, 3};

    /* * * * * *  数组本身包含一个结束标记（适合c风格） * * * * * */
    print(i); // int类型中0与空字符混淆
    print(j); // c风格字符串遇到最后得空字符会停止

    /* * * * 使用标准库规范：传递指向首元素和尾后元素得指针 * * * */
    print(std::begin(i), std::end(i));

    /* * * * * * * * 专门定义一个表示数组大小的形参  * * * * * * */
    print(i, 3);
    print(m, std::end(m) - std::begin(m));
    print(m, std::size(m));

    return 0;
} 