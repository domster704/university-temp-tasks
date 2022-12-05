#include <iostream>
#include <vector>
#include "Vector.hpp"

bool isCaughtInRadius(VectorDec2D &mouse, VectorDec2D &cat, double radius) {
    return getLen(mouse - cat) <= radius;
}

int main() {
    VectorDec2D r_c{10, -1};
    VectorDec2D r_m{-5, -20};

    VectorDec2D v_c;
    VectorDec2D v_m{0, 5};

    const double radius = 0.7;
    double last = getLen(r_m - r_c);

    double dt = 1e-6;
    double countTime = 0;

    std::vector<VectorDec2D> wayNotes{};
    VectorDec2D lastCoord;
    while (r_m.y < 0) {
        r_m = r_m + v_m * dt;
        countTime++;
        wayNotes.push_back(r_m);
    }

    lastCoord = r_m;
    double lenOfOrdVector = 0;
    double lenOfDividedCircle = getLen(lastCoord - r_c) * std::numbers::pi;
    for (int i = 0; i < countTime; i++) {
        v_c = (wayNotes.at(i) - r_c) * (1 / getLen(wayNotes.at(i) - r_c));
        r_c = r_c + v_c * dt;
        lenOfOrdVector += getLen(v_c * dt);
    }
    std::cout << lenOfDividedCircle << " " << lenOfOrdVector << '\n';
    double v0 = lenOfDividedCircle / (2 * lenOfOrdVector);
    std::cout << v0;
}
