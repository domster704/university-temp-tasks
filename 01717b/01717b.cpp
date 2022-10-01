#include <iostream>
#include "array"

std::array<std::array<int, 1000>, 1000> b{};

std::array<std::array<char, 1000>, 1000> createTable(int n, int k, int shift) {
    std::array<std::array<char, 1000>, 1000> a{};

    for (int i1 = 0; i1 < n; i1++) {
        for (int j = 0; j < n; j++) {
            a[i1][j] = '.';
        }
    }
    for (int l = 0; l < n; l += k) {
        int columnIndex = l + shift;
        if (columnIndex >= n) {
            columnIndex = columnIndex - n;
        }

        if (columnIndex < 0) {
            columnIndex = n + columnIndex;
        }
        a[0][columnIndex] = 'X';
    }
    for (int j = 1; j < n; j++) {
        for (int l = 0; l < n; l++) {
            int columnIndex = l + 1;
            if (columnIndex >= n) {
                columnIndex = columnIndex - n;
            }
            if (columnIndex < 0) {
                columnIndex = n + columnIndex;
            }
            a[j][columnIndex] = a[j - 1][l];
        }
    }
    std::array<std::array<char, 1000>, 1000> c{};
    int indexR = 0, indexC = 0;
    for (int i1 = 0; i1 <= n; i1++) {
        indexC = 0;
        for (int j = n - 1; j >= 0; j--) {
            c[indexR][indexC] = a[i1][j];
            indexC++;
        }
        indexR++;
    }
    return c;
}

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k, r, c;
        std::cin >> n >> k >> r >> c;
        b[i] = {n, k, r, c};
    }

    for (int i = 0; i < t; i++) {
        int n = b[i][0],
                k = b[i][1],
                r = b[i][2],
                c = b[i][3];

        std::array<std::array<char, 1000>, 1000> a = createTable(n, k, 0);

        int xPos = 0;
        int shift = 0;
        for (int l = 0; l < n; l++) {
            if (a[r - 1][l] == 'X') {
                xPos = l;
                break;
            }
        }
        shift = c - 1 - xPos;

        if (shift >= 0) {
            for (int j = 0; j < n; j++) {
                for (int l = n - shift; l < n; l++) {
                    std::cout << a[j][l];
                }
                for (int l = 0; l < n - shift; l++) {
                    std::cout << a[j][l];
                }
                std::cout << "\n";
            }
        } else {
            shift *= -1;
            for (int j = 0; j < n; j++) {
                for (int l = shift; l < n; l++) {\
                    std::cout << a[j][l];
                }
                for (int l = 0; l < shift; l++) {
                    std::cout << a[j][l];
                }
                std::cout << "\n";
            }
        }
    }
    return 0;
}
