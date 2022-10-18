#include <iostream>
#include <array>
#include <string>

std::array<std::string , 10001> res{};

int main() {
    int t;
    std::cin >> t;
    int n;
    std::string s;
    for (int i = 0; i < t; i++) {
        std::cin >> n >> s;
        int cB = 0, cR = 0;
        res[i] = "-1";
        for (int j = 0; j < n; j++) {
            if (s[j] == 'B') {
                cB++;
            } else if (s[j] == 'R') {
                cR++;
            }
            if (s[j] == 'W') {
                if (cB + cR == 1) {
                    res[i] = "NO";
                    break;
                }
                if ((cB == 0 || cR == 0) && cB + cR != 0) {
                    res[i] = "NO";
                    break;
                }
                cB = 0;
                cR = 0;
            }
        }
        if ((cB == 0 || cR == 0) && cB + cR != 0) {
            res[i] = "NO";
        } else if (res[i] == "-1") {
            res[i] = "YES";
        }
    }
    for (int i = 0; i < t; i++) {
        std::cout << res[i] << '\n';
    }
}
