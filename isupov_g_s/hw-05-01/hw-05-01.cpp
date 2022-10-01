#include <iostream>
#include <cmath>

double accumulate(int &a, int &b, double &step, double &eps) {
    auto expression = [](double x) -> double {
        double resForXOnInfinity = 0;
        for (int i = 0; i < 100; i++) {
            resForXOnInfinity += std::pow(-1, i) * (std::pow(x, 2 * i) / (std::tgamma(2 * i + 1)));
        }
        return resForXOnInfinity;
    };

    auto compareExpression = [](double x) -> double {
        return std::cos(x);
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
    int a = -1;
    int b = 1;
    double step = 0.1;
    double eps = 10e-3;
    double res = accumulate(a, b, step, eps);
    printf("Sum: %.5f", res);
}
