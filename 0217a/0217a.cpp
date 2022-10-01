#include <iostream>
#include <string>
#include <set>

bool checkOnBeautifulYear(int year) {
    std::string s = std::to_string(year);
    std::set<char> a;
    a.insert(s[0]);
    a.insert(s[1]);
    a.insert(s[2]);
    a.insert(s[3]);
    return a.size() == 4;
}

int main() {
    int year;
    bool isNeededToExit = false;
    std::cin >> year;
    while (!checkOnBeautifulYear(++year)) {
           }
    std::cout << year;
}
