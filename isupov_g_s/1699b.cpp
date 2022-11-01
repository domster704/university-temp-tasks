#include <iostream>
#include <array>

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        std::cin >> n >> m;
        std::array<std::array<int, 51>, 51> a{};
        a[0][0] = 1;
        int bC = 0, wC = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (j == 0 && k == 0) {
                    a[1][0] = 0;
                    a[0][1] = 0;
                    continue;
                }
            }
        }
    }
}
