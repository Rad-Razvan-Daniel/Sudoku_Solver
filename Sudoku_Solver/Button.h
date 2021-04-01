#pragma once
#include "SFML/Graphics.hpp"
#include "Text.h"
#include "Sprite.h"
class Button : public Text, public Sprite
{
public:
	Button(std::string str, std::string PATH, int x, int y);
};
