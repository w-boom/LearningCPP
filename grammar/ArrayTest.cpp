/******************* 数组 *******************/
#include <array>
#include <iostream>
#include <typeinfo>
#include <string>

int main(int argc, char** argv)
{
    const unsigned arrSize = 10;
    int arr1[arrSize] = {};
    
    int *ptrs[10]; // ptrs是含有10个整形指针的数组
    // int &refs[10] = ,, 错误：不存在引用的数组
    int (*ptr1)[10] = &arr1; // 指向一个含有10个整数的数组
    int (&arrRef)[10] = arr1;// 引用一个含有10个整数的数组
    int *(&arr2)[10] = ptrs;
    // arr2是10个元素数组的引用，该数组含有10个指针

    /* * * * * * 注意要点 * * * * * *
     * 不能将数组的内容拷贝给其它数组作为初始值
       e.g. int a[] = arr1;
     * 不能用数组为其它数组赋值
       e.g. a = arr1;
     * 字符串定义数组时一定要注意最后的空字符
     */
    
    for (auto i : arr1)
    {
        // std::cout << typeid(i).name() << std::endl;
        std::cout << i << "";
    }
    std::cout << std::endl;

    /* * * * * * 数组与指针 * * * * * */
    std::string nums[] = {"one", "two", "three"};
    std::string *p = &nums[0]; // p指向nums得第一个元素
    std::string *p1 = nums;

    std::cout << p << " " <<  p1 << std::endl;
    // 等价于p
    std::cout << *(++p) << std::endl;

    std::string *beg = begin(nums);
    std::string *last = end(nums);
    while (beg != last)
    {
        std::cout << *beg << " ";
        ++beg;
    }
    std::cout << std::endl;
    // 两指针相减的结果类型为ptrdiff_t

    /* * * * * * 多维数组 * * * * * */
    // 严格来讲，c++中没有多维数组，通常所说的多维数组其实时数组的数组
	int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    int ia1[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    return 0;
}