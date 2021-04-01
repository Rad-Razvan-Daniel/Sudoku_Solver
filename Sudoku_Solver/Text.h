#pragma once
#include "SFML/Graphics.hpp"
class Text
{
	sf::Font font;

	int x = 0, y = 0;
public:
	sf::Text text;
	Text(std::string str, int x, int y);
};
