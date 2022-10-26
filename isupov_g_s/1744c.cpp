#include <iostream>
#include <string>
#include <array>

std::array<int, 10001> res{};

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        char c;
        std::string s;
        std::cin >> n >> c >> s;
        if (c == 'g') {
            res[i] = 0;
            continue;
        }
        s += s;

        int start = 0;
        for (int j = 0; j < n * 2; j++) {
            if (s[j] == 'g') {
                start = j;
                break;
            }
        }

        int end = n - 1;
        for (int j = n * 2 - 1; j >= 0; j--) {
            if (s[j] == 'g') {
                end = j;
                break;
            }
        }

        int maxDistance = -100000;
        int last = 0;
        for (int j = end; j >= start; j--) {
            if (s[j] == 'g') {
                last = j;
            } else if (s[j] == c) {
                maxDistance = std::max(maxDistance, last - j);
            }
        }
        res[i] = maxDistance;
    }

    for (int i = 0; i < t; i++) {
        std::cout << res[i] << '\n';
    }
}
