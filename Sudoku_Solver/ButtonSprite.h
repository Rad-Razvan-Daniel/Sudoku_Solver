#pragma once
#include "Sprite.h"
class ButtonSprite :
    public Sprite
{
public:
    sf::Sprite activeSprite;
    sf::Sprite hoverSprite;
    ButtonSprite(std::string PATH);
protected:
    sf::Texture activeTexture;
    sf::Texture hoverTexture;
};

