#include "image.hpp"

namespace Mantel::GFX{
    Image::Image(const std::string& path)
    : size(0), destRect({0,0,0,0}){
        image = IMG_Load(path.c_str());
        if(!image)
            std::cout << "Could not load image in " << path << " " << IMG_GetError() << std::endl;
        std::cout << "Loaded image: \033[32m" << path << "\033[0m" << std::endl;
        size.x = image->w;
        size.y = image->h;
        objSurface = image;
        size = this->size;
    }
}