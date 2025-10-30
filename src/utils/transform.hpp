#pragma once

#include "vector.hpp"
#include "rotation.hpp"

#include <iostream>

namespace Mantel::Utils{
    struct Transform{
        Vector size;
        Vector position;
        Rotation rotation;
        Transform(Vector size = 0, Vector position = 0, Rotation rotation = 0): size(size), position(position), rotation(rotation){};
    };
    std::ostream& operator<<(std::ostream& stream, const Transform& transform){
        return stream << "Object size: " << transform.size << "Object position: " << transform.position << "Object rotation: " << transform.rotation << std::endl;
    }
}
