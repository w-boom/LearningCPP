#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
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

// �����ź�
void plot_signal(const std::vector<double>& signal, const std::string& title, double fs) {
    // ���������ļ�
    std::ofstream data_file("data.dat");
    for (size_t i = 0; i < signal.size(); ++i) {
        data_file << i / fs << " " << signal[i] << std::endl;
    }
    data_file.close();

    // ����GNUplot�ű��ļ�
    std::ofstream plot_file("plot.plt");
    plot_file << "set terminal pngcairo\n";
    plot_file << "set output '" << title.c_str() << ".png'\n";
    plot_file << "set title '" << title.c_str() << "'\n";
    plot_file << "set xlabel 'Time (s)'\n";
    plot_file << "set ylabel 'Amplitude'\n";
    plot_file << "plot 'data.dat' with lines\n";
    plot_file.close();

    // ʹ�þ���·������GNUplot����
    std::string gnuplot_command = "\"D:\\program\\gp601-win64-mingw\\gnuplot\\bin\\gnuplot.exe\" plot.plt";
    std::system(gnuplot_command.c_str());

	// std::system("gnuplot plot.plt");

    // �����ɵ�ͼ���ļ�
    ShellExecuteA(0, 0, (title + ".png").c_str(), 0, 0, SW_SHOW);
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

    // �����ź�
    plot_signal(sine_signal, "Sine Wave", fs);

    std::cout << "Plot generated: Sine Wave.png" << std::endl;

    return 0;
}
