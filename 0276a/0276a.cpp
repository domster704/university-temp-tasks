#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>

int main() {
    int n, k;
    int maxSatisfaction = INT_MIN;
    std::cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int f, t;
        std::cin >> f >> t;
        if (t > k) f -= t - k;

        maxSatisfaction = std::max(f, maxSatisfaction);
    }
    std::cout << maxSatisfaction;
}
