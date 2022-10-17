#include <iostream>
#include <array>
#include <set>

std::array<int, 17> res{};

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        if (a + b + c + d == 4) {
            res[i] = 2;
        } else if (a + b + c + d != 0) {
            res[i] = 1;
        } else {
            res[i] = 0;
        }
    }
    for (int i = 0; i < t; i++) {
        std::cout << res[i] << "\n";
    }
}
