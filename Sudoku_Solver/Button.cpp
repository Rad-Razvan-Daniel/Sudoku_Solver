#include "Button.h"
#include <iostream>
Button::Button(std::string str,sf::Font *font, std::string PATH, float x, float y,int width, int height)
{
	sf::Font *tempfont = new sf::Font;
	font = tempfont;
	font->loadFromFile("font.ttf");
	text.setFont(*font); 
	text.setString(str);
	text.setPosition(x+(90-str.length()*12)  , y+20);
	button.setSize(sf::Vector2f(width, height));
	text.setFillColor(sf::Color::Black);

	texture.loadFromFile("Resources\\Textures\\" + PATH);
	button.setTexture(&texture);
	button.setPosition(x,y);
}