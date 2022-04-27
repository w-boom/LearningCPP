# 1.预处理：gcc -E HelloWorld.c -o hello.i

将预编译结果输出到hello.txt2：
展开所有宏定义
处理条件预编译指令
处理include包含预编译指令
删除所有注释
添加行号和文件名标识
保留所有的#pragma编译器指令，编译器须使用它们

# 2.编译：gcc -S hello.i -o helloS.s
词法分析、语法分析、语义分析及优化后生产相应的汇编代码文件

# 3.汇编：gcc -c hello.s -o hello.o
将汇编代码转变为机器可执行的指令，输出目标文件，每个汇编语句几乎都对应一条机器指令。

查看hello.c文件结构

objdump -h hello.o

# 4.链接：地址和空间分配、符号决议和重定位等步骤


增加宏
预处理器命令是程序代码以“#”号开头的行。比如我们常见的代码：
```
#inlcude <stdio.h>
#define PI 3.14
...
```
预处理命令与常规语句不同，面向的不是编译器而是预处理器。在编译开始之前，预处理器会检查代码，解析所有的预处理命令。
__预处理命令：__
* 预处理命令末尾没有分号，只要找到换行符就代表结束了
* 预处理命令末尾加“\”可以多行定义
以下是具体的预处理命令：
# 1、文件包含（#include）
文件包含是常见的预处理命令，当预处理器找到#include指令会将需要包含的头文件或其它文件在该命令处全部展开。
可以简单地编写个HelloWorld.c文件来观察效果，在命令行输入：
```
// gcc编译工具
gcc -E *.c
//vs编译工具
cl -E *.c
```
文件包含有两种形式：
* __#include < header >形式__： 包含系统提供的头文件需要这种形式，这种情况下，预处理器会直接到系统目录对应文件中搜索头文件，搜索不到则报错。系统提供的头文件一般采用该包含方式，而自定义的头文件不能采用该方式。
* __#include "file"形式__：包含自定义的头文件，一般采用该方式。这种形式下，预处理器首先到当前工作目录下查找该文件，如果没有找到，再到系统目录下查找。
# 2、宏定义(#define， #undef)
宏定义语法如下：
```
#define identifier replacement // 宏定义
#undef identifier // 取消宏定义
```
当预处理器遇到“#define”时，会用replacement替换其余代码中出现的identifier。遇到“#undef identifier”会删除已定义过的宏identifier。
举个常见的宏定义：
```
#define PI 3.14

int main()
{
	double pi = PI;	
	#undef PI 
		
	return 0;
}
```
如果将取消宏定义放到main()之前，则会报错。
* replacement可以是一个表达式、一个语句、一个块或任何简单的东西。
* 宏定义只是简单的替换，并不会进行语法检查
## （1）值
```
#define PI 3.14
#define TABLE_SIZE 100
int table1[TABLE_SIZE];
```
## （2）函数宏
比如：
```
// function macro
#include <iostream>

#define GetMax(a,b) ((a)>(b)?(a):(b))

int main()
{
  int x = 5, y;
  y = GetMax(x,1+1);
  std::cout << y << std::endl;
  std::cout << GetMax(7,x) << std::endl;
  
  return 0;
}
```
预处理器会在代码出现“GetMax(a,b)”的时候，用“((a)>(b)?(a):(b))”来替换，这样更容易理解代码。
__但是这种函数宏一定要小心使用，因为预处理器只会简单地替换宏，并不会进行语法检查。__
比如：
```
#include <iostream>
#define GetMul(x) x*x

int main()
{
  int x=5, z;
  
  z = GetMul(x + x);
  std::cout << z << std::endl;
  
  return 0;
}
```
输出：
```
35
```
我们想要的输出应该是100，（5+5）*（5+5），但简单替换的是5+5*5+5；对于这种问题，如果真的要使用宏定义，可以__给每个元素加上括号__：
```
#define GetMul(x) (x)*(x)
```
另外举个例子：
```
// function macro
#include <iostream>
#define GetMul(x,y) x*y;

int main()
{
  int x=5, y, z;
  
  z = GetMul(x, 8.9);

  std::cout << z << std::endl;
  
  return 0;
}
```
输出为：
```
44
```
可以看到直接进行了类型转换，这种可以注意类型可以避免。
另外：
```
#define S(a,b) t=a;a=b;b=t

int main()
{
	S(3,4);
	
	return 0;
}
```
看上去没有问题，但是预处理之后
```
int main()
{
        t=3;3=4;4=t;

        return 0;
}
```
还有：
```
// str(test)输出x
#define str(x) "x" 
// str(test)输出test
#define str(x) #x
```
所以函数宏定义需要谨慎使用。

# 3、条件编译(#ifdef, #ifndef, #if, #endif, #else and #elif)
条件编译主要是为了有选择性地执行相应操作：如果满足某个条件，这些指令允许包含或丢弃程序的部分代码。
* __“#ifdef identifier”__：只允许identifier宏执行后续的操作，不管它的值是什么。
```
#ifdef PI
	std::cout << PI << std::endl;
#endif
```
只有PI宏已经定义的情况下，才会输出PI的值。
* __“#ifndef identifier”__：只允许identifier宏未被定义的情况下执行后续的操作。
* __“#if, #endif, #else and #elif”__，类似于条件语句，比如：
```
#if TABLE_SIZE>200
#undef TABLE_SIZE
#define TABLE_SIZE 200
 
#elif TABLE_SIZE<50
#undef TABLE_SIZE
#define TABLE_SIZE 50
 
#else
#undef TABLE_SIZE
#define TABLE_SIZE 100
#endif
 
int table[TABLE_SIZE]; 
```
* __“#ifdef” & “#ifndef” 可以用“if defined”和"if !defined"替代__。
# 4、行控制（#line）
当一个程序在编译过程中发生了错误时，编译器会显示错误消息，其中引用了发生错误的文件的名称和行号，使得更容易找到产生错误的代码。
#line指令允许我们控制这两件事，代码文件中的行号以及发生错误时我们希望显示的文件名。它的格式是:
```
#line number "filename"
```
举个例子：
```
#include <stdio.h>

int main()
{
    printf( "This code is on line %d, in file %s\n", __LINE__, __FILE__ );
#line 10
    printf( "This code is on line %d, in file %s\n", __LINE__, __FILE__ );
#line 20 "hello.cpp"
    printf( "This code is on line %d, in file %s\n", __LINE__, __FILE__ );
    printf( "This code is on line %d, in file %s\n", __LINE__, __FILE__ );
}
```
输出：
```
This code is on line 5, in file /app/example.c
This code is on line 10, in file /app/example.c
This code is on line 20, in file hello.cpp
This code is on line 21, in file hello.cpp
```
*注*：上面的__LINE__ 和__FILE__都是预定义宏
# 5、#error
#error使预处理器输出指定的错误信息，通常用于调试程序。
# 6、#pragma
#pragma指令为每个编译器提供了一种提供计算机和操作系统特定功能的方法，同时保持与 c 和 c + + 语言的总体兼容性。
常用的就是
```
#pragma once
```
这条指令常定义在头文件，保证同一个文件不会被包含多次。
# 7、预定义宏
预定义宏仅针对特定生成环境或编译器选项定义。 除非另行说明，否则这些宏的定义范围适用于整个翻译单元。 定义后，预处理器先将这些宏展开为指定的值，然后再编译。 预定义宏不带参数，不能重新定义。
## 标准预定义标识符
__ func __ 作为函数本地静态 const 数组的封闭函数的未限定和未限定名称 char。
```
#include <stdio.h>

void example()
{
    printf("%s\n", __func__);
} 

int main()
{
    example();

    return 0;
}
// 输出函数名：example
```
## 常用的标准预定义宏
* __cplusplus：当翻译单元编译为 C++ 时，定义为整数文本值。 其他情况下则不定义。
* __ DATE __：当前源文件的编译日期。 
* __ FILE __：当前源文件的名称。
* __ LINE __：定义为当前源文件中的整数行号。
```

// standard macro names
#include <iostream>
using namespace std;

int main()
{
  cout << "This is the line number " << __LINE__;
  cout << " of file " << __FILE__ << ".\n";
  cout << "Its compilation began " << __DATE__;
  cout << " at " << __TIME__ << ".\n";
  cout << "The compiler gives a __cplusplus value of " << __cplusplus;
  return 0;
}
```
输出
```
This is the line number 8 of file /app/example.cpp.
Its compilation began Apr 14 2022 at 08:21:37.
The compiler gives a __cplusplus value of 202002
```
除此之外，还有其它的标准预定义宏,参考<a href = "https://docs.microsoft.com/zh-cn/cpp/preprocessor/predefined-macros?view=msvc-170">Microsoft官方预定义宏文档</a>