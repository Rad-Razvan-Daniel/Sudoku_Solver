#pragma once
#include "SFML/Graphics.hpp"
class Text
{
	sf::Font font;
	sf::Text text;

	int x =0, y=0;
public:
	Text(std::string str, int x, int y);
};

