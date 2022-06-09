Union（联合）是一种数据类型，能在同一个内存空间中储存不同的数据类型（不是同时储存）。  
```
union hold
{
	int digit;
	double bigfl;
	char letter;
};
```
以上声明的联合只能储存一个int类型的值或一个double类型的值或一个char类型的值。本例中，占用空间最大的是double类型的数据，8个字节，则该联合占8个字节。  
# 1、初始化
```
union hold valA;
valA.letter = 'R';
union hold valB = valA; // 用另一个联合来初始化
union hold valC = {88}; // 初始化联合的digit成员
union hold valD = {.bigfl = 118.2}; // 初始化器
```
# 2、访问
```
fit.digit = 23;
pu = &fit;
x = pu->digit;
