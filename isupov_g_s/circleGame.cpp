#include <iostream>
#include <cmath>
#include "Vector.hpp"

int main() {
    VectorDec2D r{3, 5};
    VectorDec2D velocity{5, 2};
    int m1 = 1, m2 = 1, G = 1;
    VectorDec2D centerAcceleration = -1 * m1 * m2 * G * r / std::pow(getLen(r), 3);
    std::cout << centerAcceleration;
    double dt = 1e-1;
    for (int i = 0; i < 10; i++){
        velocity = velocity + centerAcceleration;
        r = r + velocity * dt;
        centerAcceleration = -1 * m1 * m2 * G * r / std::pow(getLen(r), 3);
        std::cout << "r: " << r << "v: " << velocity << "a: " << centerAcceleration << "\n";
    }
}
