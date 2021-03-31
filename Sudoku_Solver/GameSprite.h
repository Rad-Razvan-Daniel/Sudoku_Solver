#pragma once
#include <string>
#include <memory>
#include "SFML/Graphics.hpp"
class GameSprite {
public:
	std::vector<sf::Sprite> sprites;
	std::vector<std::unique_ptr<sf::Texture>> textures;
	size_t pushSprite(const std::string& PATH);
	void popSprite();
};
