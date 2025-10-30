#pragma once

#include <iostream>
#include <SDL2/SDL_image.h>

#include "drawable_object.hpp"

namespace Mantel::GFX{
    class Image : DrawableObject {
        private:
            SDL_Surface* image;
        public:
            SDL_Rect destRect;
            Utils::Vector size;

            Image(const std::string& path);
            ~Image() {};
            SDL_Surface* GetObjectSurface() override {return this->image;}
    };
}