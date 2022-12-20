#include <iostream>
#include "cmath"

double eps = 0.0001;
double step = 0.05;
double start = 0.1;
double end = 1.0;

double expression(double x) {
    double sum = 0.0;
    double current;
    for (int i = 0; i < 10000; i++) {
        current = std::pow(x, 2 * i) / std::tgamma(2 * i + 1);
        if (current < eps) {
            break;
        }
        sum += current;
    }
    return sum;
}

int main() {
    printf("%8s | %8s\n", "x", "f");
    for (double i = start; i <= end + step; i += step) {
        printf("%8.5f | %8.5f\n", i, expression(i));
    }
    return 0;
}
