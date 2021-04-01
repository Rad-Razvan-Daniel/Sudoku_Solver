#pragma once
#include "SFML/Graphics.hpp"
#include "Text.h"
#include "GameSprite.h"
class Button : Text, GameSprite
{
public:
	Button(std::string str,std::string PATH,int x,int y);
};

