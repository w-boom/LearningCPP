#include <iostream>
#include <vector>
#include <algorithm>

// 结构体用于检测离群点
struct OutlierDetector {
    double Q1;
    double Q3;
    double IQR;

    OutlierDetector(double q1, double q3, double iqr) : Q1(q1), Q3(q3), IQR(iqr) {}

    bool operator()(double x) const {
        return x < (Q1 - 1.5 * IQR) || x > (Q3 + 1.5 * IQR);
    }
};

// 函数用于计算四分位数并去除离群点
void removeOutliers(std::vector<double>& data) {
    if (data.size() < 4) {
        std::cerr << "Data set too small to calculate quartiles and remove outliers." << std::endl;
        return;
    }

    // Sort the data to access quartiles
    std::sort(data.begin(), data.end());
    size_t const Q1_pos = data.size() / 4;
    size_t const Q3_pos = 3 * data.size() / 4;
    double Q1 = data[Q1_pos];
    double Q3 = data[Q3_pos];
    double IQR = Q3 - Q1;
    std::cout << Q1 << std::endl;
    std::cout << Q3 << std::endl;
    std::cout << IQR << std::endl;


    // Instantiate the detector
    OutlierDetector detector(Q1, Q3, IQR);

    // Remove outliers
    data.erase(std::remove_if(data.begin(), data.end(), detector), data.end());
}

// 主函数，展示使用 removeOutliers 函数
int main() {
    std::vector<double> data(15);
    double dataT[15] = {-15, 23, 12, 35, 67, 89, 24, 10, 23, 20, 35, 99, 24, 21, 23};

    std::cout << "Original Data: ";
    for (size_t i = 0; i < data.size(); ++i) {
        data[i] = dataT[i];
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    removeOutliers(data);

    std::cout << "Data after removing outliers: ";
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    system("pause");
    return 0;
}
