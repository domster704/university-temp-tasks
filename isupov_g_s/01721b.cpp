#include <iostream>
#include "array"

std::array<int, 10000> results{0};

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m, sn, sm, d;
        std::cin >> n >> m >> sn >> sm >> d;
        if (sn + d >= n && sm + d >= m || sn - d - 1 <= 0 && sm - d - 1 <= 0
            || sn + d >= n && sn - d - 1 <= 0 || sm + d >= m && sm - d - 1 <= 0) {
            results[i] = -1;
        } else {
            results[i] = n + m - 2;
        }
    }

    for (int i = 0; i < t; i++) {
        std::cout << results[i] << "\n";
    }
    return 0;
}
