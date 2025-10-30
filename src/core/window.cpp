#include "window.hpp"
#include "../gfx/drawable_object.hpp"

namespace Mantel::Core{
        Window::Window(){
        title = "Mantel Test";
        position = {SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED};
        size = {1600, 900};

        win = SDL_CreateWindow(title.c_str(), position.x, position.y, size.x, size.y, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        if(!win)
            std::cout << "Could not create window " << SDL_GetError() << std::endl;
        rend = SDL_CreateRenderer(win, -1, 0);
    }
    Window::~Window(){
        if(texBuffer && win && rend){
            SDL_DestroyTexture(texBuffer);
            SDL_DestroyRenderer(rend);
            SDL_DestroyWindow(win);
        }
    }
    void Window::SetWindowMode(WindowMode mode){
        switch (mode)
        {
        case FULLSCREEN:
            SDL_SetWindowFullscreen(win, SDL_WINDOW_FULLSCREEN);
            break;
        case BORDERLESS:
            SDL_SetWindowFullscreen(win, SDL_WINDOW_BORDERLESS);
            break;
        case WINDOWED:
            SDL_SetWindowFullscreen(win, 0);
            SetWindowSize(size.x, size.y);
            SetWindowPosition(position.x, position.y);
        default:
            break;
        }
    }
    Utils::Vector Window::GetAbsolutePosition(PositionRelativeToWindow relativePosition, const Utils::Vector& offset){
        switch (relativePosition){
            case TOP_LEFT:
                return {0,0};
            case TOP_CENTER:
                return {(size.x - offset.x) / 2, 0};
            case TOP_RIGHT:
                return {size.x - offset.x, 0};
            case MIDDLE_LEFT:
                return {0,(size.y - offset.y) / 2};
            case MIDDLE_CENTER:
                return {(size.x - offset.x) / 2, (size.y - offset.y) / 2};
            case MIDDLE_RIGHT:
                return {size.x - offset.x, (size.y - offset.y) / 2};
            case BOTTOM_LEFT:
                return {0, size.y - offset.y};
            case BOTTOM_CENTER:
                return {(size.x - offset.x) / 2, size.y - offset.y};
            case BOTTOM_RIGHT:
                return {size.x - offset.x, size.y - offset.y};
        default:
            break;
        }
    }
    void Window::SetWindowSize(int w, int h){
        SDL_SetWindowSize(win, w, h);
    }
    void Window::SetWindowPosition(int x, int y){
        SDL_SetWindowPosition(win, x, y);
    }
    void Window::UpdateWindowSize(){
        SDL_GetWindowSize(win, &size.x, &size.y);
        std::cout << "Window size: " << size;
    }
    void Window::RenderBackground(const SDL_Color& col){
        SDL_SetRenderDrawColor(rend, col.r, col.g, col.g, col.a);
        SDL_RenderClear(rend);
        }
    void Window::RenderLine(const Utils::Vector& begin, const Utils::Vector& end,const SDL_Color& lineCol){
        SDL_SetRenderDrawColor(rend, lineCol.r, lineCol.g, lineCol.b, lineCol.a);
        SDL_RenderDrawLine(rend, begin.x, begin.y, end.x, end.y);
    }
    void Window::RenderPoint(const Utils::Vector& position, const SDL_Color& color){
        SDL_SetRenderDrawColor(rend, color.r,color.g,color.b,color.a);
        SDL_RenderDrawPoint(rend, position.x, position.y);
        std::cout << "Drew point: " << position;
    }
    void Window::Display(){
        SDL_RenderPresent(rend);
    }
}

