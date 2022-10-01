#include <iostream>
#include "array"

std::array<std::array<int, 100>, 100> res;
std::array<int, 100> indexes;

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        indexes[i] = n;
        std::array<int, 100> code{0};
        for (int j = 0; j < n; j++) {
            std::cin >> code[j];
        }
        for (int j = 0; j < n; j++) {
            int b;
            std::string c;
            std::cin >> b >> c;
            int shift = 0;
            for (char k: c) {
                if (k == 'D') shift++;
                else if (k == 'U') shift--;
            }
            int l = code[j] + shift;
            if (l >= 0 && l < 10) res[i][j] = l;
            else if (l >= 10) res[i][j] = l - 10;
            else res[i][j] = l + 10;
        }
    }
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < indexes[i]; j++) {
            std::cout << res[i][j] << " ";
        }
        std::cout << "\n";
    }
}
