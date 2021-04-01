#pragma once
#include <memory>
#include "SFML/Graphics.hpp"
class GameSprite {
public:
	//used as a container to sort and hold textures and sprites for rendering
	//i want to use it to easily create sprites. Storing should be done in Game class.
	GameSprite(std::string PATH);

};
