#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a;
    int x;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        a.push_back(x);
    }
    std::sort(a.begin(), a.end());
    int day = 1;
    int count = 0;
    for (int i : a) {
        if (i >= day) {
            count++;
            day++;
        }
    }
    std::cout << count;
}
