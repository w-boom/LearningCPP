#include <stdio.h>

#define ROWS 3
#define COLS 4

// 数组表示法，方括号表明ar是一个指针
// 编译器会将ar[1]转换为ar+1，ar所指对象大小为COLS
// void sum_rows(int ar[ROWS][COLS], int rows) 
// 上式与下式等价，编译器会忽略ROWS
void sum_rows(int ar[][COLS], int rows);
// 缺省
void sum_cols(int [][COLS], int);
// ar为指向内含4个int类型值的指针
int sum2d(int (*ar)[COLS], int rows);

int main(void)
{
    int junk[ROWS][COLS] = {
        {2, 4, 6, 8},
        {3, 5, 7, 9},
        {12, 10, 8, 6}
    };

    sum_rows(junk, ROWS);
    sum_cols(junk, ROWS);
    printf("Sum of all elements = %d\n", sum2d(junk, ROWS));

    return 0;
}

void sum_rows(int ar[][COLS], int rows)
{
    int r;
    int c;
    int tot;
    for (r = 0; r < rows; r++)
    {
        tot = 0;
        for(c = 0; c < COLS; c++)
        {
            tot += ar[r][c];
        }
        printf("row %d: sum = %d\n", r, tot);
    }
}

void sum_cols(int ar[][COLS], int rows)
{
    int r;
    int c;
    int tot;
    for(c = 0; c < COLS; c++)
    {
        tot = 0;
        for(r = 0; r < rows; r++)
        {
            tot += ar[r][c];
        }
        printf("col %d: sum = %d\n", c, tot);
    }
}

int sum2d(int ar[][COLS], int rows)
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