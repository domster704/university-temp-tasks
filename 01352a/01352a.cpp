#include <iostream>
#include <string>
#include <cmath>

int a[10000];

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std:: cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        int countOfElem = 0;
        std::string s;
        for (int j = 0; j < std::to_string(a[i]).size(); j++) {
            int roundNumber;
            if (j == 0) {
                roundNumber = a[i] % 10;
            } else {
                roundNumber = a[i] % (int) pow(10, j + 1) - a[i] % (int) pow(10, j);
            }
            if (roundNumber != 0) {
                countOfElem++;
                s += std::to_string(roundNumber) + " ";
            }
        }
        std::cout << countOfElem << "\n";
        std::cout << s << "\n";
    }
}
