#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream> // �����ַ�����
#include <windows.h> // ����ShellExecuteA

#include "GNUplotPlot.h"


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
