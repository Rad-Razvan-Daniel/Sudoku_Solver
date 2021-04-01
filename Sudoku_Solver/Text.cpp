#include "Text.h"

Text::Text(std::string str, int x, int y)
{
	this->font.loadFromFile("font.ttf");
	this->text.setFont(font);
	this->text.setString(str);
	this->text.setPosition(x, y);
}
