#include "Sprite.h"

Sprite::Sprite(std::string PATH)
{
	texture.loadFromFile("Resources\\Textures\\" + PATH);
	sprite.setTexture(texture);
}