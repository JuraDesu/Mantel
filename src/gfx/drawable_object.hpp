#pragma once

#include <SDL2/SDL.h>

#include "../utils/vector.hpp"

namespace Mantel::GFX{
    class DrawableObject{
        public:
            Utils::Vector size;
            SDL_Rect destRect;
            SDL_Surface* objSurface;
        protected:

            DrawableObject() : objSurface(nullptr), size({0,0}), destRect({0,0,0,0}){}
            virtual ~DrawableObject(){};
            virtual SDL_Surface* GetObjectSurface() = 0;
    };
}