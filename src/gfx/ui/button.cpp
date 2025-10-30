#include "button.hpp"

namespace Mantel::GFX::UI{
    Button::Button(const std::string& buttonText, const Utils::Vector& size)
    : buttonText(buttonText), size(size){
        
    }
}