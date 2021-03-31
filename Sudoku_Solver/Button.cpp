#include "Button.h"

Button::Button(std::string str, sf::Font font, int x, int y)
{

	
	text.setFont(font);
	text.setFillColor(sf::Color::Blue);
	text.setString(str);
	text.setPosition(x, y);
}

void Button::display()
{
}
