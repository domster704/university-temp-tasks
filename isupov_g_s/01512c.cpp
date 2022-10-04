#include <iostream>
#include "array"
#include "string"

std::array<std::string, 10001> res{""};

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        std::cin >> a >> b;
        std::string s;
        std::cin >> s;

        for (int j = 0; j < (a + b) / 2; j++) {
            if (s[j] != s[s.size() - j - 1] && s[j] != '?' && s[s.size() - j - 1] != '?') {
                res[i] = "-1";
                break;
            }
        }
        if (res[i] == "-1") continue;

        int unusedA = a, unusedB = b;
        for (int j = 0; j < a + b; j++) {
            if (s[j] == '1') {
                unusedB--;
            } else if (s[j] == '0') {
                unusedA--;
            }
        }
        for (int j = 0; j < (a + b) / 2; j++) {
            int indexFromTheEnd = s.size() - j - 1;
            if (s[j] != '?' && s[indexFromTheEnd] == '?') {
                s[indexFromTheEnd] = s[j];
                s[j] == '1' ? unusedB -= 1 : unusedA -= 1;
            } else if (s[j] == '?' && s[indexFromTheEnd] != '?') {
                s[j] = s[indexFromTheEnd];
                s[j] == '1' ? unusedB -= 1 : unusedA -= 1;
            }
        }

        for (int j = 0; j < (a + b) / 2; j++) {
            int indexFromTheEnd = s.size() - j - 1;
            if (s[j] == '?' && s[indexFromTheEnd] == '?') {
                if (unusedB >= 2) {
                    s[j] = '1';
                    s[indexFromTheEnd] = '1';
                    unusedB -= 2;
                } else if (unusedA >= 2) {
                    s[j] = '0';
                    s[indexFromTheEnd] = '0';
                    unusedA -= 2;
                }
            }
        }
        if ((a + b) % 2 == 1 && s[(a + b) / 2] == '?') {
            char c = unusedB >= 1 ? '1' : '0';
            s[(a + b) / 2] = c;
            s[(a + b) / 2] == '1' ? unusedB -= 1 : unusedA -= 1;
        }
        if (unusedA != 0 && unusedB != 0) {
            res[i] = "-1";
        } else {
            res[i] = s;
        }
    }

    for (int i = 0; i < t; i++) {
        std::cout << res[i] << "\n";
    }
}
