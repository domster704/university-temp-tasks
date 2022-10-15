#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <cmath>

std::string convertFromDecToOtherBase(int decN, short finalBase) {
    std::string res;
    while (decN > 0) {
        res += std::to_string(decN % finalBase);
        decN /= finalBase;
    }
    std::reverse(res.begin(), res.end());
    return res;
}

int convertFromOtherBaseToDec(const std::vector<int> &a, int base) {
    int res = 0;
    int powDegree = a.size() - 1;
    for (int i: a) {
        res += i * std::pow(base, powDegree--);
    }
    return res;
}

int main() {
    int a, c;
    std::cin >> a >> c;
    std::string a3 = convertFromDecToOtherBase(a, 3);
    std::string c3 = convertFromDecToOtherBase(c, 3);

    std::string plusZero;
    for (size_t i = 0; i < abs(a3.size() - c3.size()); i++) {
        plusZero += "0";
    }

    if (a3.size() < c3.size()) {
        a3 = plusZero + a3;
    } else if (a3.size() > c3.size()) {
        c3 = plusZero + c3;
    }

    std::vector<int> res3;
    int currSymC = 0;
    int currSymA = 0;
    for (size_t i = 0; i < std::max(a3, c3).size(); i++) {
        currSymA = a3[i] - '0';
        currSymC = c3[i] - '0';

        int localRes = currSymC - currSymA;
        localRes = localRes < 0 ? 3 + localRes : localRes % 3;
        res3.push_back(
                localRes
        );
    }
    std::cout << convertFromOtherBaseToDec(res3, 3);
}
