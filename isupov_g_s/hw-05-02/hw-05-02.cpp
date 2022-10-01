#include <iostream>
#include <cmath>

double accumulate(int &a, int &b, double &step, double &eps) {
    auto expression = [](double x) -> double {
        double resForXOnInfinity = 0;
        for (int i = 1; i < 100; i++) {
            resForXOnInfinity += std::pow(x, i) * std::sin(i * std::numbers::pi / 4);
        }
        return resForXOnInfinity;
    };

    auto compareExpression = [](double x) -> double {
        return x * std::sin(std::numbers::pi / 4) / (1 - 2 * x * std::cos(std::numbers::pi / 4));
    };

    double res = 0;
    double x;
    for (int i = 0; i < (std::abs(a) + std::abs(b) / step); i++) {
        x = a + i * step;
        double temp = expression(x);
        double compareTemp = compareExpression(x);
        printf("%8.5f | %8.5f | %8.5f\n", x, temp, compareTemp);
        if (std::abs(temp - compareTemp) > eps) {
            return res;
        }
        res += temp;
    }
    return res;
}

int main() {
    int a = 0;
    int b = 1;
    double step = 0.05;
    double eps = 10e-3;
    double res = accumulate(a, b, step, eps);
    printf("Sum: %.5f", res);
}
