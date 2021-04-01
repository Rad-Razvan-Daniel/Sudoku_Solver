#pragma once
#include <memory>
#include "SFML/Graphics.hpp"
class Sprite {
public:
	//creates sprites. Storing currently done in Game class.
	Sprite(std::string PATH);

	sf::Sprite sprite;
protected:
	sf::Texture texture;
};
