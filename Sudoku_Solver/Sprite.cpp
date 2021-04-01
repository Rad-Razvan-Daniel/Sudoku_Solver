#include "Sprite.h"

Sprite::Sprite(std::string PATH)
{
	texture.loadFromFile(PATH);
	sprite.setTexture(texture);
}