#include <cmath>
#include <iostream>

namespace Mantel::Utils{
    struct Rotation{
            int x, y;
            Rotation(double angle) : angleDeg(angle){}
            int ToRadians();
            void Rotate(int& x, int& y); 
        private:
            float cosA, sinA;
            int angleDeg, angleRad;
            int tempX, tempY;
    };
    std::ostream& operator<<(std::ostream& stream, Rotation rot){
        return stream << "\033[31mRotation X: " << rot.x << "\033[34mRotation Y: " << rot.y << std::endl;
    }
}