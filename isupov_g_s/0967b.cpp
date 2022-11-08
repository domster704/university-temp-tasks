#include <iostream>
#include <array>
#include <vector>

int main() {
    int n = 0, a = 0, b = 0;
    std::cin >> n >> a >> b;
    std::vector<int> holes;

    int firstHole = 0;
    std::cin >> firstHole;

    int x = 0;
    double sumHoles = firstHole;
    for (int i = 1; i < n; i++) {
        std::cin >> x;
        sumHoles += x;
        holes.push_back(x);
    }

    if (firstHole * a / sumHoles >= b) {
        std::cout << 0;
    } else {
        std::sort(holes.begin(), holes.end());
        std::reverse(holes.begin(), holes.end());
        for (int i = 0; i < holes.size(); i++) {
            sumHoles -= holes.at(i);
            if (firstHole * a / sumHoles >= b) {
                std::cout << i + 1;
                break;
            }
        }
    }
}
