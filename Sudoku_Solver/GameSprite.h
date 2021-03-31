#pragma once
#include <string>
#include <memory>
#include "SFML/Graphics.hpp"
class GameSprite
{

public:
	GameSprite();
	std::vector<sf::Sprite> sprites;
	std::vector<std::unique_ptr<sf::Texture>> textures;
	size_t newSprite(const std::string& PATH);
	
};

