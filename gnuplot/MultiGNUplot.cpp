#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream> // �����ַ�����
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

// ������ת��Ϊ�ַ��������std::to_string��
std::string to_string(int value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

// ʹ�ùܵ��������ݸ�GNUplot�������ź�
void plot_signals_with_gnuplot(const std::vector<std::vector<double>>& signals, const std::string& title, double fs) {
    // ����·��
    const char* gnuplotPath = "\"D:\\program\\gp601-win64-mingw\\gnuplot\\bin\\gnuplot.exe\" -persistent";
    FILE *gnuplotPipe = _popen(gnuplotPath, "w");
    if (gnuplotPipe) {
        // ����GNUplot����
        fprintf(gnuplotPipe, "set terminal pngcairo\n");
        fprintf(gnuplotPipe, "set output '%s.png'\n", title.c_str());
        fprintf(gnuplotPipe, "set title '%s'\n", title.c_str());
        fprintf(gnuplotPipe, "set xlabel 'Time (s)'\n");
        fprintf(gnuplotPipe, "set ylabel 'Amplitude'\n");

        // ���� plot ����
        std::string plot_command = "plot ";
        for (size_t i = 0; i < signals.size(); ++i) {
            plot_command += "'-' with lines title 'Signal " + to_string(static_cast<int>(i + 1)) + "'";
            if (i < signals.size() - 1) {
                plot_command += ", ";
            }
        }
        plot_command += "\n";
        fprintf(gnuplotPipe, "%s", plot_command.c_str());

        // ����ÿ���źŵ�����
        for (size_t i = 0; i < signals.size(); ++i) {
            const std::vector<double>& signal = signals[i];
            for (size_t j = 0; j < signal.size(); ++j) {
                fprintf(gnuplotPipe, "%f %f\n", j / fs, signal[j]);
            }
            fprintf(gnuplotPipe, "e\n");
        }

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
    std::vector<double> sine_signal1 = generate_sine_signal(amplitude, frequency, phase, duration, fs);
    std::vector<double> sine_signal2 = generate_sine_signal(amplitude, frequency, phase, duration, fs);
    std::vector<double> sine_signal3 = generate_sine_signal(amplitude, frequency, phase, duration, fs);

    // �����ڶ����źţ���ȥ2
    for (size_t i = 0; i < sine_signal2.size(); ++i) {
        sine_signal2[i] -= 2;
		sine_signal3[i] -= 4;
    }

    // ���źŴ洢�ڶ�ά vector ��
    std::vector<std::vector<double>> signals;
    signals.push_back(sine_signal1);
    signals.push_back(sine_signal2);
	signals.push_back(sine_signal3);

    // ʹ�ùܵ��������ݸ�GNUplot�������ź�
    plot_signals_with_gnuplot(signals, "Sine_Waves", fs);

    std::cout << "Plot generated: Sine_Waves.png" << std::endl;

    return 0;
}
