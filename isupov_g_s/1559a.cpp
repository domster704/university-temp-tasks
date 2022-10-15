#include <iostream>
#include <array>

std::array<int, 101> res;

int main() {
    short t;
    std::cin >> t;
    for (short i = 0; i < t; i++) {
        short n;
        std::cin >> n;
        int currentVar;
        std::cin >> res[i];
        for (short j = 1; j < n; j++) {
            std::cin >> currentVar;
            res[i] &= currentVar;
        }
    }
    for (short i = 0; i < t; i++) {
        std::cout << res[i] << "\n";
    }
}
