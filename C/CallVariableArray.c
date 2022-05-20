#include <stdio.h>

/* 变长数组必须是存储类别，无论在函数中声明还是作为函数形参
 * 声明，都不能使用static 或 extren存储类别说明符
 * 不能在声明中初始化它们
 * 变长数组一旦创建，大小则不能改变
 */
 
 
#define ROWS 3
#define COLS 4

// 这种形式在C++中不可使用 
// 参考grammer/CallVariableArray.cpp 
int sum2d(int rows, int cols, int ar[rows][cols]);

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

    printf("3x5 array\n");
    printf("Sum of all elements = %d\n", sum2d(ROWS, COLS, junk));
    printf("2x6 array\n");
    printf("Sum of all elements = %d\n", sum2d(ROWS - 1, COLS + 2, morejunk));
    printf("3x10 VLA\n");
    printf("Sum of all elements = %d\n", sum2d(rs, cs, varr));

    return 0;
}

// 带变长数组形参的函数
int sum2d(int rows, int cols, int ar[rows][cols])
{
    int r;
    int c;
    int tot = 0;
    for(r = 0; r < rows; r++)
    {
        for(c = 0; c < cols; c++)
        {
            tot += ar[r][c];
        }
    }

    return tot;
}