#pragma once

#include <cmath>
#include <iostream>

namespace Mantel::Utils{
    struct Vector{
        int x,y;

        Vector(int x = 0, int y = 0) : x(x), y(y){};
        inline Vector operator+(const Vector& vec) const {
            return Vector(x + vec.x, y + vec.y);
        }
        inline Vector operator-(const Vector& vec) const {
            return Vector(x - vec.x, y - vec.y);
        }
        inline Vector operator*(const Vector& vec) const {
            return Vector(x * vec.x, y * vec.y);
        }
        inline Vector operator/(const Vector& vec) const {
            return Vector(x / vec.x, y / vec.y);
        }
    };
    inline std::ostream& operator<<(std::ostream& stream, Vector vec){
        return stream << "\033[31mX: " << vec.x << "\t\033[34mY: " << vec.y << "\033[0m" << std::endl;
    }
}