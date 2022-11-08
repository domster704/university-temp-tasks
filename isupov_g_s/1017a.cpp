#include <iostream>
#include <array>
#include <algorithm>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::array<std::array<int, 4>, 1001> a{};
    std::vector<int> res{};
    int thomasRes = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> a[i][j];
        }
        if (i == 0) {
            thomasRes = a[i][0] + a[i][1] + a[i][2] + a[i][3];
        }
        res.push_back(a[i][0] + a[i][1] + a[i][2] + a[i][3]);
    }
    std::sort(res.begin(), res.end());
    for (int i = n - 1; i >= 0; i--) {
        if (res.at(i) == thomasRes) {
            std::cout << n - i;
            break;
        }
    }
}
