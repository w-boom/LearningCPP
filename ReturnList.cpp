/* * * * * * * * * 列表初始化返回值C++11后 * * * * * * * * * */

#include <iostream>
#include <vector>

std::vector<std::string> process()
{
     std::string expected = "gun";

     if (expected == "actual")
        return {"hello", "gun"};
    else
        return {"hello", "world", "!"};
}

int main(int argc, char **argv)
{
    std::vector<std::string> vec1(process());

    for(std::vector<std::string>::size_type i = 0; i < vec1.size(); ++i)
    {
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}