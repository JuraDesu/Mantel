#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "../text.hpp"

namespace Mantel::GFX::UI{
    class Button{
        private:
            Utils::Vector size;
            SDL_Surface* buttonSurface;
            std::string buttonText;
            Text text;
        public:
            Button(const std::string& buttonText, const Utils::Vector& size);
            ~Button();
    };
}