#include <iostream>
#include <array>

std::array<std::string , 5001> res{};

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        std::cin >> n >> m;
        int minR = 1000, minC = 1000;
        int r = 1000, c = 1000;
        for (int j = 0; j < n; j++) {
            std::string s;
            std::cin >> s;
            for (int k = 0; k < m; k++) {
                if (s[k] == 'R') {
                    minR = std::min(minR, j);
                    minC = std::min(minC, k);
                    if (j < r && k < c) {
                        r = j;
                        c = k;
                    }
                }
            }
            res[i] = minR == r && minC == c ? "YES" : "NO";
        }
    }
    for (int i = 0; i < t; i++) {
        std::cout << res[i] << "\n";
    }
}
