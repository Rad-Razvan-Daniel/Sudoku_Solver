#pragma once
#include "SFML/Graphics.hpp"
#include <string>
class Button
{


	sf::Font font;
public:
	sf::Text text;
	Button(std::string str, sf::Font font, int x = 0, int y = 0, sf::Color color = sf::Color::Black);
	void display();
};

