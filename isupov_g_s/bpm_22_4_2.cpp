#include <iostream>

bool isInArea(double x, double y) {
    return x * x + y * y <= 1 && (y >= x + 1 || y <= x - 1);
}

int main() {
    double x, y;
    std::cin >> x >> y;
    long allCount = 0;
    long pointCountInArea = 0;
    while (!std::cin.fail()) {
        std::cin >> x >> y;
        allCount++;
        pointCountInArea += isInArea(x, y) ? 1 : 0;
    }

    std::cout << 1.0 * pointCountInArea / allCount;
    return 0;
}
