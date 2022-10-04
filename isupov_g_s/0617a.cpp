#include <iostream>

int main() {
    int coord, sumOfSteps = 0;
    std::cin >> coord;
    for (int i = 5; i > 0; i--) {
        if (coord / i > 0) {
            sumOfSteps += coord / i;
            coord -= coord / i * i;
        }
    }

    std::cout << sumOfSteps;
}
