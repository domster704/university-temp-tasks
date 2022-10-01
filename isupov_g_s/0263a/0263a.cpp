#include <iostream>
#include <cstdlib>

int main() {
    int n;
    int rowIndex, columnIndex;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cin >> n;
            if (n == 1) {
                rowIndex = i;
                columnIndex = j;
            }
        }
    }

    std::cout << abs(rowIndex - 2) + abs(columnIndex - 2);
}
