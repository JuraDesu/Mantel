#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

#include "window.hpp"

namespace Mantel::Core{
    class Game {
        public:
            void Loop();
            static Game* GetInstance();
            
        private:
            Mantel::Core::Window win;
            SDL_Event e;
            static Game* instance;
            Game();
            ~Game();
    };
}
