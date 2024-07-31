#include <print>
 
int main()
{
    /*
    1) Equivalent to std::println(stdout, fmt, std::forward<Args>(args)...).
    2) Equivalent to std::print(stream, std::runtime_format(std::string(fmt.get()) + '\n'),
           std::forward<Args>(args)...).
    3) Equivalent to std::println(stdout).
    4) Equivalent to std::print(stream, "\n").
    */
    // Each call to std::println ends with new-line
    std::println("Please"); // overload (1)
    std::println("enter"); // (1)
 
    std::print("pass");
    std::print("word");
 
    std::println(); // (3); valid since C++26; same effect as std::print("\n"); 

    std::println("Please", "enter");

    std::println("Hello, {}!", "World"); // 使用C++23特性
}