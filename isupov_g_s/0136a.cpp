#include <iostream>
#include <array>

std::array<int, 101> res{};
std::array<int, 101> a{};

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        res[a[i] - 1] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        std::cout << res[i] << " ";
    }
}
