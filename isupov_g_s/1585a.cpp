#include <iostream>
#include <array>

std::array<int, 101> res;

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::array<int, 101> a{};
        for (int j = 0; j < n; j++) {
            std::cin >> a[j];
        }

        res[i] = 1;
        int previousWatered = -1;
        for (int j = 0; j < n; j++) {
            int isWatered = a[j];
            if (previousWatered == 0 && isWatered == 0) {
                res[i] = -1;
                break;
            } else if (isWatered == 1 && previousWatered == 1) {
                res[i] += 5;
            } else if (isWatered == 1) {
                res[i]++;
            }
            previousWatered = isWatered;
        }
    }

    for (size_t i = 0; i < t; i++) {
        std::cout << res[i] << "\n";
    }
}
