#pragma once
#include "SFML/Graphics.hpp"
class Text
{
protected:

	sf::Font* font = NULL;

	int x = 0, y = 0;
	sf::Text text;
	Text(std::string str,sf::Font* tempfont);
public:
	sf::Text getText();
};
