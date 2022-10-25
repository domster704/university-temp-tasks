#include <iostream>
#include <array>
#include <string>

std::array<int, 10001> res{};

int main() {
    int t;
    std::cin >> t;
    int n, k;
    std::string s;
    for (int i = 0; i < t; i++) {
        std::cin >> n >> k >> s;
        int minW = 1000000;
        int countW = 0;
        for (int h = 0; h < k; h++) {
            if (s[h] == 'W') {
                countW++;
            }
        }
        minW = std::min(minW, countW);
        for (int j = k; j < n; j++) {
            if (s[j] == 'W') {
                countW++;
            }
            if (s[j - k] == 'W') {
                countW--;
            }
            minW = std::min(minW, countW);
        }
        res[i] = minW;
    }
    for (int i = 0; i < t; i++) {
        std::cout << res[i] << '\n';
    }
}
