#include <iostream>
#include <cmath>
#include "Vector.hpp"

bool isCaughtInRadius(VectorDec2D &mouse, VectorDec2D &cat, double radius) {
    return getLen(mouse - cat) <= radius;
}

int main() {
    VectorDec2D r_c{10, -1};
    VectorDec2D r_m{-5, -20};

    double v0 = 6;
    VectorDec2D v_c = (r_m - r_c) * (1 / getLen(r_m - r_c)) * v0;
    VectorDec2D v_m{0, -5};

    const double radius = 1e-5;
    double last = getLen(r_m - r_c);

    double dt = 1e-6;
    double countTime = 0;
    bool isNeededToCheckDifferenceBetweenVelocities = std::sin(convertToRpol2DFromRdec2D(r_m - VectorDec2D{1, 0}).phi) < 0;
    while (r_m.y < 0 && !isCaughtInRadius(r_m, r_c, radius)) {
        if (isNeededToCheckDifferenceBetweenVelocities) {
            last = getLen(r_m - r_c);
        }
        v_c = (r_m - r_c) * (1 / getLen(r_m - r_c)) * v0;
        r_c = r_c + v_c * dt;
        r_m = r_m + v_m * dt;
        countTime += dt;
        if (isNeededToCheckDifferenceBetweenVelocities && last < getLen(r_m - r_c)) {
            break;
        }
    }

    if (r_m.y >= 0) {
        std::cout << "Mouse is survived in " << countTime << "\n";
        std::cout << r_c;
        std::cout << r_m;
    } else if (isCaughtInRadius(r_m, r_c, radius)) {
        std::cout << "Catch in " << countTime << "\n";
        std::cout << "Cat: " << r_c;
        std::cout << "Mouse: " << r_m;
    } else if (isNeededToCheckDifferenceBetweenVelocities && last < getLen(r_m - r_c)) {
        std::cout << last << " " << getLen(r_m - r_c) << "\n";
        std::cout << v_c << v_m;
        std::cout << "Mouse run away in " << countTime << "\n";
    }
}
