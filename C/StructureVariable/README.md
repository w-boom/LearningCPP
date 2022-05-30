# 1、book.c 建立包含书名、作者和价格的结构变量  
结构声明(structure declaration)
```
struct book{
	char title[MAXTITL];  // 书名
	char author[MAXAUTL]; // 作者名
	float value;          // 价格
};
```
* 结构声明并未创建实际的数据对象，只描述了该对象由什么组成。  
* 也可称为模板，因为它勾勒出结构是如何存储数据的。  
* 声明结构的过程和定义结构变量的过程可以组合成一个步骤： 
```
struct {                  // 无结构标记
	char title[MAXTITL];  // 书名
	char author[MAXAUTL]; // 作者名
	float value;          // 价格
}libary;                  
```
初始化：
## (1)第一种方法：
```
struct book libary = {
	"The Pious Pirate and the Devious Damsel",
	"Renee Vivotte",
	1.95
};
```
## (2)第二种方法：
```
	struct book libary;
	libary.title = "The Pious Pirate and the Devious Damsel";
	libary.author = "Renee Vivotte";
	libary.value = 1.95;
```
## (3)初始化器（C99 & C11）
```
struct book libary = { // 任意结构，逗号结尾
	.value = 1.95,
	.title = "The Pious Pirate and the Devious Damsel",
	.author = "Renee Vivotte",

};
```
# 2、指向结构的指针  friends.c  
* 声明结构指针：（该声明并未创建一个新的结构，并且与数组不同，结构名并不是结构的地址，因此要在结构名前面加上&运算符）  
```
struct guy *him;
him = &barney;
```
* 用指针访问成员  
```
him -> income;
// 相当于
barney.income;
```
# 3、传递结构 funds1.c  

# 4、结构和结构指针的选择  
* 把指针作为参数有两个优点：  
无论是以前还是现在的C实现都能使用着中国方法，并且执行起来很快，只需要传递一个地址。  
缺点是无法保护数据，被调函数中的某些操作可能会意外影响原来结构中的数据。ANSI C新增的const限定符解决了这个问题。  
* 把结构作为参数传递的优点：  
函数处理的是原始数据的副本，保护了原始数据。  
代码风格也更清楚。  
* 传递结构的两个缺点：  
较老版本的实现可能无法处理这样的代码，而且传递结构浪费时间和存储空间。  

