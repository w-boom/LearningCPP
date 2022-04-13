20世纪70年代以前，一个函数经过编译器编译后，存储在目标文件内的符号与函数名相同。比如定义一个函数func1，在目标函数中的符号名称也为func1。
但是随着汇编编写库的丰富，定义的函数很有可能与库中的函数名冲突。为了解决这一问题，编译器在将源代码编译成目标文件时，会将函数和变量的名字进行修饰，形成符号名，也就是**符号修饰/名字修饰（Decorated Name）**。
# 1、函数签名（Function Sginature）
函数签名包含了一个函数的信息，包括函数名、参数类型、所在类、名称空间及其他信息。
比如：
函数```int func(int x)```的函数签名为：```int func(int)```
每个函数签名对应一个修饰后的名字。
# 2、C语言中的名字修饰
Windows平台，C语言源代码文件中所有全局变量和函数经过编译后，符号名前加下划线“_”。

LINUX平台的gcc编译器中，默认去掉了C语言符号加下划线的方式。

fortran语言则前后都加下划线“_”。
比如
```
func1
Windows:_func1
LINUX：func1
fortran:_func1_
```
简单举个例子，aa.c文件中代码如下：
```
int f(int x)
{
	return 0;
}

int main(int argc, char *argv[])
{
	int j = f(1);
	
	return 0;
}
```
Windows平台上，命令行输入：
```
cl aa.c
dumpbin /SYMBOLS aa.obj
```
生成可执行文件，然后利用dumpbin.exe工具查看符号名：
![在这里插入图片描述](https://img-blog.csdnimg.cn/a0d140d7b03444079d9d2e35b3158335.png)
Linux平台上，输入
```
gcc aa.c
nm -a a.out
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/012a27ec1dea4a3a8b21e031ccc6e260.png)
# 3、C++名字修饰
c++拥有类、继承、虚机制、重载、名称空间等，相同名字的函数，可能参数列表不同，为了支持这些复杂的特性，发明了符号修饰和符号改变。
 aa.cpp文件代码如下：
 ```
 int f(void)
{
	return 1;
}

 int f(int x)
{
	return 0;
}

int main(int argc, char **argv)
{
	int i = f();
	int j = f(1);
	
	return 0;
}
```
Windows平台运行结果如下：
![在这里插入图片描述](https://img-blog.csdnimg.cn/11e0f04972054658bf134f274553e66f.png)
Linux平台运行结果如下：
![在这里插入图片描述](https://img-blog.csdnimg.cn/ea2f6a89acc4491d80b835252e5d1a0c.png)
# 4、extern "C"
vs中默认.cpp文件用c++方式编译，.c文件用c方式编译。如果遇到混合编程的话，就需要用到extern "C"来设定编译方式。
新建aa.h文件：
```
#ifdef __cplusplus
	extern "C" int f(int x);
#else
	int f(int x);
#endif
```
__cplusplus是cpp中自定义的宏，如果是cpp文件，则会执行extern "C"，用C的方式编译f函数。
aa.cpp文件代码：
```
#include "aa.h"

int f(int x)
{
	return 0;
}

int main(int argc, char **argv)
{
	int j = f(1);
	
	return 0;
}
```
执行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/447e6f618a8c4643b4906619c1900ea2.png)
# 5、myd7349编写的dump_all_exports.py