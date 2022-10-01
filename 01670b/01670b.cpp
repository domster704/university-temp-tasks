#include <iostream>
#include "array"
#include "string"
#include "vector"

int deleteElems(std::string& s, auto c, int k) {
    int count = 0;
    std::vector<int> indexes;
    for (int i = 0; i < s.size() - 1; i++) {
        if (std::find(std::begin(c), std::end(c), s[i + 1]) != std::end(c)) {
            count = 1;
            indexes.push_back(i);
        }
    }
    if (indexes.size() == 1) {
        s = s.substr(indexes.at(0) + 1, s.size() - indexes.at(0));
        return indexes.at(0) + 1;
    }

    int l = 0;
    for (int index: indexes) {
        s.erase(index - l, 1);
        l++;
    }
    return count;
}

std::array<int, 100001> res{0};

int main() {
    std::ios_base::sync_with_stdio(false);
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, k;
        std::string s;
        std::array<char, 26> c{""};
        std::cin >> n >> s >> k;
        for (int _ = 0; _ < k; _++) {
            std::cin >> c[_];
        }
        int checkingValue = deleteElems(s, c, k);
        int countOfDeleting = 0;
        while (checkingValue > 0) {
            countOfDeleting += checkingValue;
            checkingValue = deleteElems(s, c, k);
        }
        res[i] = countOfDeleting;
    }

    for (int i = 0; i < t; i++) {
        std::cout << res[i] << "\n";
    }
}
