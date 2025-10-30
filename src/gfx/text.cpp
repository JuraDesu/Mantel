#include "text.hpp"

namespace Mantel::GFX{
    Text::Text(const std::string& path,const std::string& text, const SDL_Color& textColFg, int textSize)
    : text(text), size(0), destRect({0,0,0,0}), textSize(textSize){
        font = TTF_OpenFont(path.c_str(), textSize);
        if(!font)
            std::cout << "Could not load font: " << path << " " << TTF_GetError() << std::endl;
        textSurface = TTF_RenderText_Solid(font, text.c_str(), textColFg);
        if(!textSurface)
            std::cout << "Nemohl jsem nadzgat teho fonta do teho povrchu, protoze jsi debil a neco jsi posral " << SDL_GetError() << std::endl;
        size.x = textSurface->w;
        size.y = textSurface->h;
        objSurface = textSurface;
        size = this->size;
    }
}