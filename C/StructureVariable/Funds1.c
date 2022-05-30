/* * * * 向函数传递结构的信息 * * * */
#include <stdio.h>

#define FUNDLEN 50

// 结构变量
struct funds{
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

// 形参为结构的信息
double sum(double, double);
// 形参是一个指针
double sum1(const struct funds *);
// 传递结构
double sum2(struct funds moolah);

int main(void)
{
	struct funds stan = {
		"Garlic-Melon Bank",
		4032.27,
		"Lucky's Savings and Loan",
		8543.94
	};
	
	printf("Stan has a total of $%.2f.\n",
			sum(stan.bankfund, stan.savefund));
	// 注意：结构名不是首地址，需要用&
	printf("Stan has a total of $%.2f.\n",
			sum1(&stan));
	// 传递结构
	printf("Stan has a total of $%.2f.\n", sum2(stan));
	
	return 0;
}

// 两个double类型的数相加
double sum(double x, double y)
{
	return (x+y);
}

double sum1(const struct funds *money)
{
	return (money -> bankfund + money -> savefund);
}

double sum2(struct funds moolah)
{
	return (moolah.bankfund + moolah.savefund);
}