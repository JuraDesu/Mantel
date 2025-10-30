#include "rotation.hpp"

namespace Mantel::Utils{
    int Rotation::ToRadians(){
        return angleDeg * M_PI / 180;
    }
    void Rotation::Rotate(int& x, int& y){
        cosA = std::cos(angleRad);
        sinA = std::sin(angleRad);

        tempX = x * cosA * y * sinA;
        tempY = x * sinA * y * cosA;

        x = tempX;
        y = tempY;
        this->x = tempX;
        this->y = tempY;
    }
}