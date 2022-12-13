#include <iostream>
#include <cmath>
#include <fstream>
#include "Vector.hpp"

int main() {
    std::ofstream out ("../report.txt");
    if (out.is_open()) {
        out << "n;t;x;y;v.x;v.y;a.x;a.y\n";
    }

    VectorDec2D r{5, -10};
    VectorDec2D velocity{0, 0.5};
    int m1 = 1, m2 = 1;
    double G = 1;
    VectorDec2D centerAcceleration = G * r / std::pow(getLen(r), 3);
    double dt = 1e-1;
    double k = 1;
    for (int i = 0; i < 1000; i++) {
        velocity = velocity - dt * centerAcceleration;
        r = r + velocity * dt;
        centerAcceleration = G * r / std::pow(getLen(r), 3);

        // if distance to zero point is so small, we need to teleport them to negative coordinates
//        if (std::abs(r.x) < 1 * k && std::abs(r.y) < 1 * k) {
//            r = r - velocity * dt;
//            velocity = velocity - dt * centerAcceleration;
//            r = r * -1;
//            G = -G;
//        }
        if (out.is_open()) {
            out << i << ";" << dt * i << ";" << r.x << ";" << r.y << ";" << velocity.x << ";" << velocity.y << ";"
                << centerAcceleration.x << ";" << centerAcceleration.y << "\n";
        }
    }
    std::cout << r;
    out.close();
}
