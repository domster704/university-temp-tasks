#include <iostream>
#include <array>
#include <cmath>

std::array<int, 101> res{};

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::array<std::array<int, 2>, 100> iTime{};
        std::array<int, 100> tm{};
        for (int j = 0; j < n; j++) {
            std::cin >> iTime[j][0] >> iTime[j][1];
        }
        for (int j = 0; j < n; j++) {
            std::cin >> tm[j];
        }
        int finalTime = iTime[0][0] + tm[0];
        int aMb = std::ceil((float) (iTime[0][1] - iTime[0][0]) / 2);
        int delta = iTime[0][1] > finalTime + aMb ? iTime[0][1] : finalTime + aMb;
        for (int j = 1; j < n; j++) {
            finalTime = iTime[j][0] + tm[j] - iTime[j - 1][1] + delta;
            aMb = std::ceil((float) (iTime[j][1] - iTime[j][0]) / 2);
            delta = iTime[j][1] > finalTime + aMb ? iTime[j][1] : finalTime + aMb;
        }
        res[i] = finalTime;
    }

    for (int i = 0; i < t; i++) {
        std::cout << res[i] << "\n";
    }
}
