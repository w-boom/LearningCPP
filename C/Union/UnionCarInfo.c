#include <stdio.h>

// 汽车属于驾驶者
struct owner
{
    char name[40];
    char gender[8];
    char date[20];
};

// 汽车属于出租公司
struct leasecompany
{
    char name[40];
    char tel[40];
};

// 联合
union info
{
    struct owner owncar;
    struct leasecompany leasecar;
};

struct car_info
{
    char number[15];
    int status; // 私有为0，租赁为1
    union info ownerinfo;
};

int main(void)
{
    struct car_info car1 = {
        .status = 0,
        .number = "a8888",
        .ownerinfo.owncar.name = "hele",
        .ownerinfo.owncar.gender = "female",
        .ownerinfo.owncar.date = "2015-01-05"
    };

    return 0;
}