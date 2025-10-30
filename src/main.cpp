#include <iostream>
#include "core/window.hpp"
#include "core/game.hpp"

using namespace Mantel::Core;

int main(){
    Game::GetInstance()->Loop();
    SDL_Quit();
}