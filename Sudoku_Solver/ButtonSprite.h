#pragma once
#include "Sprite.h"
class ButtonSprite
{
public:
    sf::Sprite activeSprite;
    sf::Sprite hoverSprite;
    sf::Sprite sprite;
    ButtonSprite(std::string PATH);
protected:
    sf::Texture texture;
    sf::Texture activeTexture;
    sf::Texture hoverTexture;
};

