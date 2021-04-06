#include "ButtonSprite.h"
ButtonSprite::ButtonSprite(std::string PATH)
	: Sprite(PATH)
{
	texture.loadFromFile(PATH);
	sprite.setTexture(texture);
}