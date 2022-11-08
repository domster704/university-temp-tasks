#include <iostream>
#include <array>
#include <set>

int main() {
    int n;
    std::cin >> n;
    std::array<int, 200001> a{};
    std::set<int> s;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        s.insert(a[i]);
    }

    std::set<int> beenVisited;
    bool flag = false;
    for (int i = n - 1; i >= 0; i--) {
        if (s.size() - beenVisited.size() == 1) {
            flag = true;
        }

        if (!flag) {
            beenVisited.insert(a[i]);
        } else {
            if (!beenVisited.contains(a[i])) {
                std::cout << a[i];
                break;
            }
        }
    }
}
