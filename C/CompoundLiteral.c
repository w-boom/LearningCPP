#include <stdio.h>

#define COLS 4

int sum2d(const int ar[][COLS], int rows);
int sum(const int ar[], int n);

int main(void)
{
    int total1, total2, total3;
    int *pt1;
    int (*pt2)[COLS];

    /* 符合字面量是匿名的，必须在创建的同时使用它
     * C++有相似的用法
     * 复合字面量具有块作用域，一旦离开定义复合字面量的块，
     * 程序无法保证该字面量是否存在
     */
    pt1 = (int[2]){10, 20};
    pt2 = (int[2][COLS]){
        {1, 2, 3, -9},
        {4, 5, 6, -8}
    };
    
    total1 = sum(pt1, 2);
    total2 = sum2d(pt2, 2);
    total3 = sum((int []){4, 4, 4, 5, 5, 5}, 6);

    printf("total1 = %d\n", total1);
    printf("total2 = %d\n", total2);
    printf("total3 = %d\n", total3);

    return 0;
}

int sum(const int ar[], int n)
{
    int i;
    int total = 0;
    
    for(i = 0; i < n; i++)
    {
        total += ar[i];
    }

    return total;
}

int sum2d(const int ar[][COLS], int rows)
{
    int r;
    int c;
    int tot = 0;

    for(r = 0; r < rows; r++)
    {
        for(c = 0; c < COLS; c++)
        {
            tot += ar[r][c];
        }
    }

    return tot;
}