#include <iostream>
#include <array>
#include <string>

std::array<std::string, 8> a{};
std::array<std::array<int, 2>, 37> res{};

int countReshetka(std::string s) {
    int count = 0;
    for (char i : s) {
        if (i == '#') {
            count++;
        }
    }
    return count;
}

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 8; ++j) {
            std::cin >> a[j];
        }
        int row = 0;
        int col = 0;
        for (int j = 0; j < 6; j++) {
            if (countReshetka(a[j + 1]) == 1 && countReshetka(a[j]) == 2 && countReshetka(a[j + 2]) == 2) {
                for (int l = 0; l < 8; l++) {
                    if (a[j + 1][l] == '#') {
                        row = j + 2;
                        col = l + 1;
                    }
                }
            }
        }
        res[i] = {row, col};
    }

    for (int i = 0; i < t; i++) {
        std::cout << res[i][0] << " " << res[i][1] << "\n";
    }
}
