// 比较队列和数组维护缓冲区运行时间差别
#include <deque>
#include <chrono>
#include <iostream>
#include <numeric>

int main() {
    std::deque<int> dq;
    int a[500];
    int fixed_length = 500;
    int iterations = 1000;
    for (int i = 0; i < fixed_length; ++i) {
        dq.push_back(i); // 初始化deque
        a[i] = i;
    }

    auto start1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 500; i++)
    {
        dq.pop_front();
        dq.push_back(i+500);
    }

    double cc1 = std::inner_product(dq.begin(), dq.end(), dq.begin(), 0.00);

    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1 - start1;
    std::cout << "Deque method took " << diff1.count() << " seconds." << std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 500; i++)
    {
        for (int j = 0; j < 499; j++)
        {
            a[j] = a[j+1];
        }
        a[499] = a[498]+1;
    }
    double sum = 0.00;
    for (int i = 0; i < 500; i++)
    {
        sum = sum + a[i] * a[i];
    }

    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2 - start2;
    std::cout << "Deque method took " << diff2.count() << " seconds." << std::endl;
    

}
