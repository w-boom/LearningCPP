#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <windows.h> // ����ShellExecuteA

// ����M_PI����
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// ���������ź�
std::vector<double> generate_sine_signal(double amplitude, double frequency, double phase, double duration, double fs) {
    int num_samples = static_cast<int>(duration * fs);
    std::vector<double> signal(num_samples);
    for (int i = 0; i < num_samples; ++i) {
        double t = i / fs;
        signal[i] = amplitude * std::sin(2 * M_PI * frequency * t + phase);
    }
    return signal;
}

// ʹ�ùܵ��������ݸ�GNUplot�������ź�
void plot_signal_with_gnuplot(const std::vector<double>& signal, const std::string& title, double fs) {
    const char* gnuplotPath = "\"D:\\program\\gp601-win64-mingw\\gnuplot\\bin\\gnuplot.exe\" -persistent";
    FILE *gnuplotPipe = _popen(gnuplotPath, "w");
    if (gnuplotPipe) {
        // ����GNUplot����
        fprintf(gnuplotPipe, "set terminal pngcairo\n");
        fprintf(gnuplotPipe, "set output '%s.png'\n", title.c_str());
        fprintf(gnuplotPipe, "set title '%s'\n", title.c_str());
        fprintf(gnuplotPipe, "set xlabel 'Time (s)'\n");
        fprintf(gnuplotPipe, "set ylabel 'Amplitude'\n");
        fprintf(gnuplotPipe, "plot '-' with lines title 'Sine Wave'\n");

        // ��������
        for (size_t i = 0; i < signal.size(); ++i) {
            fprintf(gnuplotPipe, "%f %f\n", i / fs, signal[i]);
        }
        fprintf(gnuplotPipe, "e\n");

        // �رչܵ�
        fflush(gnuplotPipe);
        _pclose(gnuplotPipe);

        // �����ɵ�ͼ���ļ�
        ShellExecuteA(0, 0, (title + ".png").c_str(), 0, 0, SW_SHOW);
    } else {
        std::cerr << "Error: Could not open pipe to GNUplot." << std::endl;
    }
}

int main() {
    // ��������
    double amplitude = 1.0;
    double frequency = 5.0; // 5 Hz
    double phase = 0.0;
    double duration = 2.0; // 2 seconds
    double fs = 1000; // ����Ƶ�� 1000 Hz

    // ���������ź�
    std::vector<double> sine_signal = generate_sine_signal(amplitude, frequency, phase, duration, fs);

    // ʹ�ùܵ��������ݸ�GNUplot�������ź�
    plot_signal_with_gnuplot(sine_signal, "Sine_Wave", fs);

    std::cout << "Plot generated: Sine_Wave.png" << std::endl;

    return 0;
}
