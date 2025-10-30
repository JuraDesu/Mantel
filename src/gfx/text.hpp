#pragma once

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <iostream>

#include "drawable_object.hpp"

namespace Mantel::GFX{
    class Text : DrawableObject{
        private:
            TTF_Font* font;
            SDL_Surface* textSurface;
            std::string text;
            int textSize;
        public: 
            SDL_Rect destRect;
            Utils::Vector size;

            Text(const std::string& path, const std::string& text, const SDL_Color& textColFg, int textSize);
            Text() = default;
            ~Text() {};
            SDL_Surface* GetObjectSurface() override {return this->textSurface;}
    };
}