#include <iostream>
#include <string>

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;
    int sum = 0, x = 0, y = 0;
    bool wasInXY = false;
    for (int i = 0; i < n; i++) {
        s[i] == 'U' ? y += 1 : x += 1;
        if (x == y) {
            wasInXY = true;
        } else if (wasInXY && s[i] == s[i - 1]) {
            wasInXY = false;
            sum++;
        } else {
            wasInXY = false;
        }
    }
    std::cout << sum;
}
