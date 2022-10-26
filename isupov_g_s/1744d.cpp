#include <iostream>
#include <array>
#include <cmath>
#include <vector>

std::array<int, 100001> res{};

int countTwo(int a) {
    if (a == 0) return 0;
    int count = 0;
    while (a % 2 == 0) {
        a /= 2;
        count++;
    }
    return count;
}

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        int count = 0;
        int max2n = -10;
        std::array<int, 100001> a{};
        for (int j = 0; j < n; j++) {
            std::cin >> a[i];
            count += countTwo(a[i]);
            max2n = std::max((int) std::log2(a[i]), j + 1);
        }
        if (count >= n) {
            res[i] = 0;
            continue;
        }
        std::vector<int> d(max2n + 1, 0);
        for (int j = 0; j < n; j++) {
            if ((j + 1) % 2 != 0) {
                d.at(0)++;
            } else {
                d.at(countTwo(j + 1))++;
            }
        }

        bool flag = false;
        int countOfAction = 0;
        for (int j = max2n; j >= 0; j--) {
            for (int k = 0; k < d.at(j); k++) {
                if (j == 0) break;
                countOfAction++;
                count += j;
                if (count >= n) {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        res[i] = flag ? countOfAction : -1;
    }
    for (int i = 0; i < t; i++) {
        std::cout << res[i] << '\n';
    }
}
