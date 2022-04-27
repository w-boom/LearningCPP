/******************* 管理引用形参 *******************/

#include <iostream>

void print (int (&arr)[10])
{
    // int &arr[10] 错误：将arr声明为引用的数组
    for (auto elem : arr)
        std::cout << elem;

    std::cout << std::endl;
}

// matrix指向数组的首元素，该数组的元素是由10个整数构成的数组
// int *matrix[10] 为10个指针构成的数组
void print(int (*matrix)[2], int rowSize)
{
    for (int i = 0; i < rowSize; ++i)
    {
        std::cout << matrix[i][0] << " " << matrix[i][1] << std::endl;
    }
}

int main(int argc, char** argv)
{
    int i = 0, j[2] = {0, 1};
    int k[10] = {0, 1, 2, 3};
    int m[][2] = {{1, 2},
                {3, 4},
                {5, 6}};
    // print(&i); 
    print(k);
    print(m, 3);

} 