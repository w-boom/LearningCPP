#include <iostream>
#include <ranges>
// 不太清楚这个头文件，cppreference查到contains是包含在algorithm
#include <vector>
#include <algorithm>
 
int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 
    // 使用新的 ranges 适配器
    auto even_numbers = numbers | std::views::filter([](int n) { return n % 2 == 0; });
    // lambda函数
    auto squared_numbers = even_numbers | std::views::transform([](int n) { return n * n; });
 
    for (int n : squared_numbers) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;
 
    // 新的 range 算法
    bool contains_five = std::ranges::contains(numbers, 5);
    std::cout << "Contains 5: " << std::boolalpha << contains_five << std::endl;


    // 获取前 5 个元素
    auto first_five = numbers | std::views::take(5);

    // 跳过前 5 个元素
    auto after_five = numbers | std::views::drop(5);
 
    return 0;
}