#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream> // 用于字符串流
#include <windows.h> // 用于ShellExecuteA

#include "GNUplotPlot.h"


// 将整数转换为字符串（替代std::to_string）
std::string to_string(int value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

// 使用管道传递数据给GNUplot并绘制信号
void plot_signals_with_gnuplot(const std::vector<std::vector<double>>& signals, const std::string& title, double fs) {
    // 绝对路径
    const char* gnuplotPath = "\"D:\\program\\gp601-win64-mingw\\gnuplot\\bin\\gnuplot.exe\" -persistent";
    FILE *gnuplotPipe = _popen(gnuplotPath, "w");
    if (gnuplotPipe) {
        // 设置GNUplot参数
        fprintf(gnuplotPipe, "set terminal pngcairo\n");
        fprintf(gnuplotPipe, "set output '%s.png'\n", title.c_str());
        fprintf(gnuplotPipe, "set title '%s'\n", title.c_str());
        fprintf(gnuplotPipe, "set xlabel 'Time (s)'\n");
        fprintf(gnuplotPipe, "set ylabel 'Amplitude'\n");

        // 生成 plot 命令
        std::string plot_command = "plot ";
        for (size_t i = 0; i < signals.size(); ++i) {
            plot_command += "'-' with lines title 'Signal " + to_string(static_cast<int>(i + 1)) + "'";
            if (i < signals.size() - 1) {
                plot_command += ", ";
            }
        }
        plot_command += "\n";
        fprintf(gnuplotPipe, "%s", plot_command.c_str());

        // 传递每个信号的数据
        for (size_t i = 0; i < signals.size(); ++i) {
            const std::vector<double>& signal = signals[i];
            for (size_t j = 0; j < signal.size(); ++j) {
                fprintf(gnuplotPipe, "%f %f\n", j / fs, signal[j]);
            }
            fprintf(gnuplotPipe, "e\n");
        }

        // 关闭管道
        fflush(gnuplotPipe);
        _pclose(gnuplotPipe);

        // 打开生成的图像文件
        ShellExecuteA(0, 0, (title + ".png").c_str(), 0, 0, SW_SHOW);
    } else {
        std::cerr << "Error: Could not open pipe to GNUplot." << std::endl;
    }
}
