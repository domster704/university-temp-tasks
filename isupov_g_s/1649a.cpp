#include <iostream>
#include <array>

std::array<int, 101> res{};

int main() {
    int t;
    std::cin >> t;
    std::array<int, 101> a{};
    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;

        int lastFirst1Index = 0;
        int lastSecond1Index = 0;
        bool flag = true;
        for (int j = 0; j < n; j++) {
            std::cin >> a[j];
            if (a[j] == 0) {
                flag = false;
            }
            if (a[j] == 1 && flag) {
                lastFirst1Index = j;
            }
        }
        for (int j = n - 1; j >= 0; j--) {
            if (a[j] == 0) {
                break;
            }
            if (a[j] == 1) {
                lastSecond1Index = j;
            }
        }
        if (lastSecond1Index - lastFirst1Index < 0) {
            res[i] = 0;
        } else {
            res[i] = lastSecond1Index - lastFirst1Index;
        }
    }

    for (int i = 0; i < t; i++) {
        std::cout << res[i] << "\n";
    }
}
