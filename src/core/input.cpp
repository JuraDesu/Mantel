#include "input.hpp"

namespace Mantel::Core{
    Input* Input::instance = nullptr;

    Input* Input::GetInstance(){
        if(!instance){
            instance = new Input();
        }
        return instance;
    }
    void Input::ProcessMouseInput(SDL_Event& e, Window& win){
        if(e.type == SDL_MOUSEMOTION){
            SDL_GetMouseState(&mousePos.x, &mousePos.y);
            std::cout << mousePos;
        } else if(e.type == SDL_MOUSEBUTTONDOWN){
            if(e.button.button == SDL_BUTTON_LEFT){
                win.RenderPoint(mousePos, {255,255,255,255});
                SDL_RenderPresent(win.GetRenderer());
            }
        }
    }
}