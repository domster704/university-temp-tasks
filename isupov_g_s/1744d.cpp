#include <iostream>
#include <array>
#include <string>

std::array<int, 10001> res{};

int countTwo(int a) {
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
    int n;
    for (int i = 0; i < t; i++) {
        std::cin >> n;
        int count = 0;
        int a;
        for (int j = 0; j < n; j++) {
            std::cin >> a;
            count += countTwo(a);
        }
        if ((count + n / 2 + n % 2) < n) {
            res[i] = -1;
        } else {

        }
        std::cout << count << "\n";
    }
    for (int i = 0; i < t; i++) {
        std::cout << res[i] << '\n';
    }
}
