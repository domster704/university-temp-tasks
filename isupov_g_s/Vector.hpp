#include "iosfwd"
#include <cmath>

struct VectorDec2D {
    double x = 0.0,
            y = 0.0;
};

struct VectorPol2D {
    double r = 0.0,
            phi = 0.0;
};

VectorDec2D operator+(const VectorDec2D &a, const VectorDec2D &b) {
    VectorDec2D newV{a.x + b.x, a.y + b.y};
    return newV;
}

VectorDec2D operator-(const VectorDec2D &a, const VectorDec2D &b) {
    VectorDec2D newV{a.x - b.x, a.y - b.y};
    return newV;
}

VectorDec2D operator*(const VectorDec2D &a, const double &s) {
    VectorDec2D newV{a.x * s, a.y * s};
    return newV;
}

VectorDec2D operator*(const double &s, const VectorDec2D &a) {
    VectorDec2D newV{a.x * s, a.y * s};
    return newV;
}

VectorDec2D operator/(const VectorDec2D &a, const double &s) {
    VectorDec2D newV{a.x / s, a.y / s};
    return newV;
}

bool operator==(const VectorDec2D& a, const VectorDec2D& b) {
    if (a.x - b.x < std::numeric_limits<double>::epsilon() * 3 && a.y - b.y < std::numeric_limits<double>::epsilon() * 3) {
        return true;
    } else {
        return false;
    }
}

std::ostream &operator<<(std::ostream &out, const VectorDec2D &a) {
    return out << a.x << " " << a.y << "\n";
}

double operator*(const VectorDec2D &a, const VectorDec2D &b) {
    return a.x * b.x + a.y * b.y;
}

VectorPol2D operator+(const VectorPol2D &a, const VectorPol2D &b) {
    double tempX = a.r * std::cos(a.phi) + b.r * std::cos(b.phi);
    double tempY = a.r * std::sin(a.phi) + b.r * std::sin(b.phi);
    VectorPol2D newV{
            std::sqrt(tempX * tempX + tempY * tempY),
            std::atan(tempY / tempX)
    };
    return newV;
}

VectorPol2D operator-(const VectorPol2D &a, const VectorPol2D &b) {
    double tempX = b.r * std::cos(b.phi) + a.r * std::cos(a.phi);
    double tempY = b.r * std::sin(b.phi) + a.r * std::sin(a.phi);
    VectorPol2D newV{
            std::sqrt(tempX * tempX + tempY * tempY),
            std::atan(tempY / tempX)
    };
    return newV;
}

VectorPol2D operator*(const VectorPol2D &a, const double &s) {
    VectorPol2D newV{
            a.r * s,
            a.phi
    };
    return newV;
}

VectorPol2D operator/(const VectorPol2D &a, const double &s) {
    VectorPol2D newV{
            a.r / s,
            a.phi
    };
    return newV;
}

VectorPol2D operator*(const double &s, const VectorPol2D &a) {
    VectorPol2D newV{
            a.r * s,
            a.phi
    };
    return newV;
}

double operator*(const VectorPol2D &a, const VectorPol2D &b) {
    double aX = a.r * std::cos(a.phi),
            bX = b.r * std::cos(b.phi);
    double aY = a.r * std::sin(a.phi),
            bY = b.r * std::sin(b.phi);
    return aX * bX + aY * bY;
}

std::ostream &operator<<(std::ostream &out, const VectorPol2D &a) {
    return out << a.r << " " << a.phi << "\n";
}

VectorDec2D convertToRdec2DFromRpol2D(VectorPol2D a) {
    VectorDec2D newV{
            a.r * std::cos(a.phi),
            a.r * std::sin(a.phi)
    };
    return newV;
}

VectorPol2D convertToRpol2DFromRdec2D(VectorDec2D a) {
    VectorPol2D newV{
            std::sqrt(a.x * a.x + a.y * a.y),
            std::atan(a.y / a.x)
    };
    return newV;
}

double getLen(VectorDec2D a) {
    return std::sqrt(a.x * a.x + a.y * a.y);
}

double getLen(VectorPol2D a) {
    return a.r;
}
