#include <iostream>
#include <string>
#include <typeinfo>

int main()
{
    std::string str("some string!!!");

    // 每行输出str中的一个字符
    for (auto c : str)
    {
        std::cout << c << std::endl;
        // std::cout << typeid(c).name() << std::endl;
    }

    // 统计string对象中标点符号的个数：
    decltype(str.size()) punctCnt = 0; // 此处需要注意str.size()的类型
    std::cout << typeid(punctCnt).name() << std::endl;
    for (auto c : str)
        if (ispunct(c))
            ++punctCnt;
    
    std::cout << punctCnt << std::endl;
	
	// 转换为大写形式，改变单个字符的值，必须把循环变量定义为引用类型
	for (auto &c : str)
		c = toupper(c);
	
	std::cout << str << std::endl;
	
	

    return 0;  
}