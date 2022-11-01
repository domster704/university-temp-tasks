#include <iostream>
#include <array>

int main() {
    long long n, k;
    std::cin >> n >> k;
    std::array<int, 501> a{};
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int max1 = *std::max_element(a.begin(), a.end());
    if (k >= n) {
        std::cout << max1;
    } else {
        int rowWin = 0;
        int lastWinner = a[0];
        for (int i = 1; i < n; i++) {
            if (lastWinner > a[i]) {
                rowWin++;
            } else {
                lastWinner = a[i];
                rowWin = 1;
            }
            if (rowWin == k) {
                break;
            }
        }
        std::cout << lastWinner;
    }
}
