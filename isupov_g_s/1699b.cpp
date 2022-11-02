#include <iostream>
#include <array>

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        std::cin >> n >> m;
        int x1 = 1, x2 = 0;
        int out = 0;
        for (int j = 1; j <= n; j++) {
            if (j % 2 == 0) {
                std::swap(x1, x2);
            }
            for (int k = 1; k <= m; k++) {
                out = k % 4 <= 1 ? x1 : x2;
                std::cout << out << " ";
            }
            std::cout << "\n";
        }
    }
}
