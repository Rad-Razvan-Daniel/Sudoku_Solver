#pragma once
#include "Text.h"
#include "Sprite.h"
class Button : 
	public Text, public Sprite
{
public:
	Button(std::string str, std::string PATH, int x, int y);
};
