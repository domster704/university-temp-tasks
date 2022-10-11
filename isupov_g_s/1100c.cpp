#include <iostream>
#include <cmath>

int main() {
    double n, r;
    std::cin >> n >> r;
    double a = std::numbers::pi / n;
    printf("%.6f", r * std::sin(a) / (1 - std::sin(a)));
}
