#pragma once
#include "Text.h"
#include "ButtonSprite.h"
class Button :
	public Text, public ButtonSprite
{
	//the PATH will be <<image.jpg>>.  Resources\\Textures\\ will be added. 
	// i did this because I want to load in inactive_texture and we can't do that
	//unless we load the path after we add the identifier before the texture
public:
	Button(std::string str, std::string PATH, int x, int y);
};
