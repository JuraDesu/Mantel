#include "game.hpp"
#include "window.hpp"

#include "../gfx/image.hpp"

#include "input.hpp"

#include "../utils/transform.hpp"

namespace Mantel::Core{
    Game* Game::instance = nullptr;

    Game* Game::GetInstance(){
        if(instance == nullptr)
            instance = new Game();
        return instance;
    }
    Game::~Game(){
        delete instance;
    }
    Game::Game(){
        if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
            std::cout << "Failed to init SDL " << SDL_GetError() << std::endl;
        } else if(IMG_Init(IMG_INIT_PNG) < 0){
            std::cout << "Failed to init SDL_image " << IMG_GetError() << std::endl;
        } else if(TTF_Init() < 0){
            std::cout << "Failed to init SDL_ttf " << TTF_GetError() << std::endl;
        }
        win.UpdateWindowSize();
    }
    void Game::Loop(){
        bool running = true;
        float deltaTime;
        int timeToWait;
        int maxFrameRate = 60;
        int lastFrameTime = 0;

        GFX::Image bg("resources/images/Loading_screen.png");
        GFX::Text test("resources/fonts/Default.ttf", "Test",{255,255,255,255}, 50);
        Utils::Transform testTran({0,0}, {80, 10}, 180);
        std::cout << testTran;

        
        while(running){
            deltaTime = (SDL_GetTicks() - lastFrameTime) / 1000.0f;
            lastFrameTime = SDL_GetTicks();

            timeToWait = 1000.0f / maxFrameRate - deltaTime;

            if (timeToWait > 0 && timeToWait <= maxFrameRate)
                SDL_Delay(timeToWait);

            win.RenderBackground({26, 32, 52, 255});
            //win.RenderLine({windowSize.x / 2, 600},{windowSize.x /2, 120}, {255,255,255,255});
            //win.RenderLine({(windowSize.x + 600) / 2, windowSize.y / 2},{(windowSize.x - 600) / 2, windowSize.y /2}, {255,255,255,255});
            win.RenderDrawable<GFX::Image>(bg, win.GetAbsolutePosition(TOP_CENTER, bg.size));
            win.RenderDrawable<GFX::Text>(test, win.GetAbsolutePosition(BOTTOM_CENTER, test.size));
            win.Display();
            while(SDL_PollEvent(&e) != 0){
                if(e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE){
                    running = false;
                } else if(e.window.event == SDL_WINDOWEVENT_RESIZED){
                    win.UpdateWindowSize();
                } else if(e.key.keysym.sym == SDLK_F11){
                    win.SetWindowMode(FULLSCREEN);
                }
            }
        }
        win.~Window();
        SDL_Quit();
    }
}
