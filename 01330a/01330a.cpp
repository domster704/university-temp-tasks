#include <iostream>
#include "array"

std::array<int, 5> results{0};

int main() {
    int t;
    std::cin >> t;
    for (int _ = 0; _ < t; _++) {
        std::array<int, 400> a{0};
        int n, x;
        std::cin >> n >> x;
        for (int i = 0; i < n; i++) {
            int tempVar;
            std::cin >> tempVar;
            a[tempVar - 1] = tempVar;
        }

        int index = 0;
        int lastElementAfterZeroValue;
        for (int i = 0;;i++) {
            if (index > x) break;
            if (a[i] == 0) {
                index++;
            }
            lastElementAfterZeroValue = i;
        }
        results[_] = lastElementAfterZeroValue;
    }
    for (int i = 0; i < t; i++) {
        std::cout << results[i] << "\n";
    }
    return 0;
}
