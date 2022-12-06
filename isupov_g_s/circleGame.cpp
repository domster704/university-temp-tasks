#include <iostream>
#include <cmath>
#include <fstream>
#include "Vector.hpp"

int main() {
    std::ofstream out ("../report.csv");
    if (out.is_open()) {
        out << "n;t;x;y;v.x;v.y;a.x;a.y\n";
    }

    VectorDec2D r{10, 0};
    VectorDec2D velocity{0, 2};
    int m1 = 1, m2 = 1, G = 100;
    VectorDec2D centerAcceleration = G * r / std::pow(getLen(r), 3);
    double dt = 1e0;
    for (int i = 0; i < 1000 * 1 / dt; i++) {
        velocity = velocity - dt * dt * centerAcceleration / 2;
        r = r + velocity * dt;
        centerAcceleration = G * r / std::pow(getLen(r), 3);

        if (out.is_open()) {
            out << i << ";" << dt * i << ";" << r.x << ";" << r.y << ";" << velocity.x << ";" << velocity.y << ";"
                << centerAcceleration.x << ";" << centerAcceleration.y << "\n";
        }
    }
    out.close();
}
