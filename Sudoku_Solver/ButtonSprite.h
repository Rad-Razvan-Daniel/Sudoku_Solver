#pragma once
#include "Sprite.h"
class ButtonSprite :
    public Sprite
{
    sf::Sprite activeSprite;
    sf::Sprite hoverSprite;
    ButtonSprite(std::string PATH);
    sf::Texture activeTexture;
    sf::Texture hoverTexture;
};

