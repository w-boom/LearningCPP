调用[gnuplot](https://sourceforge.net/projects/gnuplot/)绘制数据

下载对应版本之后，将bin文件路径添加到系统路径。在cmd中输入gnuplot测试是否可用

# 1、GNUplot1.cpp

生成正弦波->输出到数据文件方便gnuplot调用->创建gnuplot脚本文件（plot.plt）->设置参数和输出文件->生成图像文件->显示图像文件

# 2、GNUplot2.cpp

用管道处理，不需要输出数据文件和脚本文件

# 3、MultiGNUplt.cpp

一张图绘制多个信号