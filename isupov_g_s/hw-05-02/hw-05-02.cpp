#include <iostream>
#include <cmath>
#include <array>

std::array<double, 2> accumulate(int &a, int &b, double &step, double &eps) {
    auto expression = [&](double x) -> double {
        double resForXOnInfinity = 0;
        double temp;
        double lastElem = 0;
        for (int i = 1; i < 100; i++) {
            temp = std::pow(x, i) * std::sin(i * std::numbers::pi / 4);
            if (std::abs(temp - lastElem) < eps && i % 4 != 0) {
                break;
            }
            resForXOnInfinity += temp;
            lastElem = temp;
        }
        return resForXOnInfinity;
    };

    auto compareExpression = [](double x) -> double {
        return x * std::sin(std::numbers::pi / 4) / (1 - 2 * x * std::cos(std::numbers::pi / 4));
    };

    double resA = 0;
    double resR = 0;
    double x;
    for (int i = 0; i < (std::abs(a) + std::abs(b) / step); i++) {
        x = a + i * step;
        double temp = expression(x);
        double compareTemp = compareExpression(x);
        printf("%8.5f | %8.5f | %8.5f\n", x, temp, compareTemp);
        resA += temp;
        resR += compareTemp;
    }
    return std::array<double, 2> {resA, resR};
}

int main() {
    int a = 0;
    int b = 1;
    double step = 0.05;
    double eps = 10e-3;
    printf("%8s | %8s | %8s\n", "x", "s(x)", "f(x)");
    std::array<double, 2> res = accumulate(a, b, step, eps);
    printf("SumAnalytical: %.5f\tSumReal: %.5f", res[0], res[1]);
}
