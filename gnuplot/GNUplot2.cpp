#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <windows.h> // 用于ShellExecuteA

// 定义M_PI常量
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// 生成正弦信号
std::vector<double> generate_sine_signal(double amplitude, double frequency, double phase, double duration, double fs) {
    int num_samples = static_cast<int>(duration * fs);
    std::vector<double> signal(num_samples);
    for (int i = 0; i < num_samples; ++i) {
        double t = i / fs;
        signal[i] = amplitude * std::sin(2 * M_PI * frequency * t + phase);
    }
    return signal;
}

// 使用管道传递数据给GNUplot并绘制信号
void plot_signal_with_gnuplot(const std::vector<double>& signal, const std::string& title, double fs) {
    const char* gnuplotPath = "\"D:\\program\\gp601-win64-mingw\\gnuplot\\bin\\gnuplot.exe\" -persistent";
    FILE *gnuplotPipe = _popen(gnuplotPath, "w");
    if (gnuplotPipe) {
        // 设置GNUplot参数
        fprintf(gnuplotPipe, "set terminal pngcairo\n");
        fprintf(gnuplotPipe, "set output '%s.png'\n", title.c_str());
        fprintf(gnuplotPipe, "set title '%s'\n", title.c_str());
        fprintf(gnuplotPipe, "set xlabel 'Time (s)'\n");
        fprintf(gnuplotPipe, "set ylabel 'Amplitude'\n");
        fprintf(gnuplotPipe, "plot '-' with lines title 'Sine Wave'\n");

        // 传递数据
        for (size_t i = 0; i < signal.size(); ++i) {
            fprintf(gnuplotPipe, "%f %f\n", i / fs, signal[i]);
        }
        fprintf(gnuplotPipe, "e\n");

        // 关闭管道
        fflush(gnuplotPipe);
        _pclose(gnuplotPipe);

        // 打开生成的图像文件
        ShellExecuteA(0, 0, (title + ".png").c_str(), 0, 0, SW_SHOW);
    } else {
        std::cerr << "Error: Could not open pipe to GNUplot." << std::endl;
    }
}

int main() {
    // 参数设置
    double amplitude = 1.0;
    double frequency = 5.0; // 5 Hz
    double phase = 0.0;
    double duration = 2.0; // 2 seconds
    double fs = 1000; // 采样频率 1000 Hz

    // 生成正弦信号
    std::vector<double> sine_signal = generate_sine_signal(amplitude, frequency, phase, duration, fs);

    // 使用管道传递数据给GNUplot并绘制信号
    plot_signal_with_gnuplot(sine_signal, "Sine_Wave", fs);

    std::cout << "Plot generated: Sine_Wave.png" << std::endl;

    return 0;
}
