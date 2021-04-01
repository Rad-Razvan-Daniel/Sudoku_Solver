#include "Button.h"

Button::Button(std::string str, std::string PATH, int x, int y) :Text(str, x, y), Sprite(PATH)
{
	sprite.setPosition(x, y);
	texture.getSize();
}