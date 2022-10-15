#include <iostream>

int main() {
    short t;
    std::cin >> t;
    for (short i = 0; i < t; i++) {
        short n;
        std::cin >> n;
        for (short j = 0; j < n; j++) {
            std::cout << "1 ";
            for (short l = 1; l < j; l++) {
                std::cout << "0 ";
            }

            if (j != 0)
                std::cout << "1";
            std::cout << "\n";
        }
    }
}
