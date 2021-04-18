#include "Text.h"

Text::Text(std::string str, sf::Font* tempfont)
{
	this->font = tempfont;
	this->text.setFont(*tempfont);
	this->text.setString(str);
	text.setFillColor(sf::Color::Black);
	printf("made ");
}

sf::Text Text::getText()
{
	return text;
}
