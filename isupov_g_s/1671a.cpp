#include <iostream>
#include <array>

std::array<std::string , 1001> res{};

int main() {
    int t;
    std::string s;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::cin >> s;
        if (s.size() == 1) {
            res[i] = "NO";
            continue;
        }
        int countA = s[0] == 'a' ? 1 : 0;
        int countB = s[0] == 'b' ? 1 : 0;
        res[i] = "-1";
        for (int j = 1; j < s.size(); j++) {
            if (s[j] == 'b') {
                countB++;
            }
            if (s[j] == 'a') {
                countA++;
            }
            if (s[j] == 'a' && s[j - 1] == 'b') {
                if (countB == 1) {
                    res[i] = "NO";
                    break;
                }
                countB = 0;
            } else if (s[j] == 'b' && s[j - 1] == 'a') {
                if (countA == 1) {
                    res[i] = "NO";
                    break;
                }
                countA = 0;
            }
        }
        if (countB == 1 || countA == 1) {
            res[i] = "NO";
        } else if (res[i] == "-1") {
            res[i] = "YES";
        }
    }
    for (int i = 0; i < t; i++) {
        std::cout << res[i] << "\n";
    }
}
