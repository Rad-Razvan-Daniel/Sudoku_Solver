#include "Button.h"

Button::Button(std::string str, sf::Font font, int x, int y, sf::Color color)
{

	this->font = font;
	text.setFont(this->font);
	text.setFillColor(color);
	text.setString(str);
	text.setPosition(x, y);
}

void Button::display()
{
}
