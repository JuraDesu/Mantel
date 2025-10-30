#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include "../utils/vector.hpp"
#include "../gfx/image.hpp"
#include "../gfx/text.hpp"
#include "../gfx/drawable_object.hpp"

namespace Mantel::Core{
        enum WindowMode{
        WINDOWED,
        BORDERLESS,
        FULLSCREEN,
    };
    enum PositionRelativeToWindow{
        TOP_LEFT,
        TOP_CENTER,
        TOP_RIGHT,
        MIDDLE_LEFT,
        MIDDLE_CENTER,
        MIDDLE_RIGHT,
        BOTTOM_LEFT,
        BOTTOM_CENTER,
        BOTTOM_RIGHT,
    };

    class Window{
            SDL_Window* win;
            SDL_Renderer* rend;
            SDL_Texture* texBuffer;
            std::string title;

            bool isFullscreen;
        public:
            Utils::Vector size, position;

            Window();
            Window(std::string title, const Utils::Vector& size);
            Window(std::string title, const Utils::Vector& size, Uint32 flags);
            ~Window();
            void SetWindowSize(int w, int h);
            void SetWindowPosition(int posX, int posY);
            void SetWindowSize(float w, float h);
            void SetWindowPosition(float posX, float posY);
            void SetWindowMode(WindowMode mode);
            void UpdateWindowSize();

            void RenderBackground(const SDL_Color& bgCol);
            void RenderLine(const Utils::Vector& begin, const Utils::Vector& end, const SDL_Color& lineCol);
            void RenderPoint(const Utils::Vector& position, const SDL_Color& color);
            Utils::Vector GetAbsolutePosition(PositionRelativeToWindow relativePosition, const Utils::Vector& offset);
            template<typename T>
            inline void RenderDrawable(T& obj, const Utils::Vector& position){
                static_assert(std::is_base_of<Mantel::GFX::DrawableObject, T>::value);
                obj.destRect = {position.x, position.y, obj.size.x, obj.size.y};
                texBuffer = SDL_CreateTextureFromSurface(rend, obj.GetObjectSurface());
                SDL_RenderCopy(rend, texBuffer, nullptr, &obj.destRect);
                SDL_DestroyTexture(texBuffer);
            }

            void Display();

            SDL_Renderer* GetRenderer(){return rend;}
            SDL_Window* GetWindow(){return win;}
            Utils::Vector GetWindowSize(){return size;}
    };
}

