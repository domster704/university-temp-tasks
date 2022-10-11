#include <iostream>
#include "array"
#include "vector"
#include "string"

std::array<std::string, 10001> res{""};

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        std::string s;
        std::cin >> n >> k >> s;
        bool flag = true;
        for (int j = 0; j < k; j++) {
            if (s[j] != '?') continue;
            for (int l = j + k; l < n; l += k) {
                if (s[l] == '?') continue;
                s[j] = s[l];
                break;
            }
        }
        // check possibility to fill other ? places after k position
        for (int j = 0; j < k + 0; j++) {
            if (s[j] == '?') continue;
            for (int l = j + k; l < n; l += k) {
                if (s[l] == '?') {
                    s[l] = s[j];
                } else if (s[l] != s[j]) {
                    flag = false;
                }
            }
        }
        int sum0 = 0, sum1 = 0;
        for (int j = 0; j < k; j++) {
            if (s[j] == '0')
                sum0++;
            if (s[j] == '1')
                sum1++;
        }
        res[i] = (flag && sum1 <= k / 2 && sum0 <= k / 2) ? "YES" : "NO";
    }

    for (int i = 0; i < t; i++) {
        std::cout << res[i] << "\n";
    }
}
