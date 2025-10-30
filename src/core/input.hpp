#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "../utils/vector.hpp"
#include "window.hpp"

namespace Mantel::Core{
    class Input{
    private:
        Input() {};
        static Input* instance;
        Utils::Vector mousePos;
        void MousePress(SDL_MouseButtonEvent& b, Window& win);
    public:
        static Input* GetInstance();
        void ProcessMouseInput(SDL_Event& e, Window& win);
    };
}
