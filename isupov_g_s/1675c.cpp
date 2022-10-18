#include <iostream>
#include <array>
#include <string>

std::array<int, 10001> res{};

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::string s;
        std::cin >> s;
        int pos1 = 0;
        int pos0 = s.size() - 1;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '0') {
                break;
            }
            if (s[j] == '1') {
                pos1 = j;
            }
        }
        for (int j = s.size() - 1; j >= 0; j--) {
            if (s[j] == '1') {
                break;
            }
            if (s[j] == '0') {
                pos0 = j;
            }
        }
        res[i] = std::abs(pos0 - pos1) + 1;
    }
    for (int i = 0; i < t; i++) {
        std::cout << res[i] << '\n';
    }
}
