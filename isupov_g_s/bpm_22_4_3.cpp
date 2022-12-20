#include <iostream>
#include "string"

int main() {
    std::string firstStr;
    std::string secondStr;
    std::cin >> firstStr >> secondStr;
    if (firstStr == secondStr) {
        std::cout << 0;
        return 0;
    }
    int actionsCount = 0;
    int len = abs(firstStr.length() - secondStr.length());
    for (int i = 0; i < len; i++) {
        if (firstStr.length() == secondStr.length()) {
            break;
        } else if (firstStr.length() > secondStr.length()) {
            firstStr.erase(0, 1);
            actionsCount++;
        } else if (firstStr.length() < secondStr.length()) {
            secondStr.erase(0, 1);
            actionsCount++;
        }
    }
    if (firstStr == secondStr) {
        std::cout << actionsCount;
        return 0;
    }
    for (int i = 0; i < firstStr.length(); i++) {
        firstStr.erase(0, 1);
        secondStr.erase(0, 1);
        actionsCount += 2;
        if (firstStr == secondStr) {
            break;
        }
    }
    std::cout << actionsCount;
    return 0;
}
