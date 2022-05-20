#include <iostream>

/* 相较于C\CallVariableArray.cpp
 */

#define ROWS 3
#define COLS 4

int sum2d(int rows, int cols, void *ar);

int main(void)
{
    int i, j;
    int rs = 3;
    int cs = 10;
    int junk[ROWS][COLS] = {
        {2, 4, 6, 8},
        {3, 5, 7, 9},
        {12, 10, 8, 6}
    };
    int morejunk[ROWS -1][COLS + 2] = {
        {20, 30, 40, 50, 60, 70},
        {5, 6, 7, 8, 9, 10}
    };
    int varr[rs][cs]; // 变长数组
    for(i = 0; i < rs; i++)
    {
        for(j = 0; j < cs; j++)
        {
           varr[i][j] = i * j + j; 
        }
    }

    std::cout << "3x5 array" << std::endl;
    std::cout << "Sum of all elements = " << sum2d(ROWS, COLS, junk) << std::endl;
    std::cout << "2x6 array" << std::endl;
    std::cout << "Sum of all elements = " << sum2d(ROWS - 1, COLS + 2, morejunk) << std::endl;
    std::cout << "3x10 VLA" << std::endl;
    std::cout << "Sum of all elements = " << sum2d(rs, cs, varr) << std::endl;

    return 0;
}

// 带变长数组形参的函数
int sum2d(int rows, int cols, void *ar)
{
    int (*ptr)[cols] = static_cast<int (*)[cols]>(ar);
    int r;
    int c;
    int tot = 0;
    for(r = 0; r < rows; r++)
    {
        for(c = 0; c < cols; c++)
        {
            tot += ptr[r][c];
        }
    }

    return tot;
}


