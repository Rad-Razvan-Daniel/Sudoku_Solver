#pragma once
#include <string>
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
class GameSprite
{
	//this vector will be used to store all of the sprites required.
	//it will store a pointer to a sprite. 
public:
	GameSprite();
	std::vector<sf::Sprite> sprites;
	int newSprite(std::string PATH);
	
};

