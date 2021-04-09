#include "Button.h"
#include <iostream>
Button::Button(std::string str,sf::Font *font, sf::Texture* def, sf::Texture* hover, sf::Texture* active, float x, float y,int width, int height)
{
	sf::Font *tempfont = new sf::Font;
	font = tempfont;
	font->loadFromFile("font.ttf");

	text.setFont(*font); 
	text.setString(str);
	//TODO: center the text within the box using the getGlobalPosition
	text.setPosition(x+(90-str.length()*12)  , y+20);
	text.setFillColor(sf::Color::Black);

	
	texture = def;
	hover_texture = hover;
	active_texture = active;

	button.setSize(sf::Vector2f(width, height));
	button.setTexture(texture);
	button.setPosition(x,y);

	buttonbounds.left =x;
	buttonbounds.top =y;
	buttonbounds.height=height;
	buttonbounds.width =width;

}
void Button::updateTexture()
{
	switch (state)
	{
	case 1: // hover
		std::cout << "hover" << std::endl;
		button.setTexture(hover_texture);
		break;
	case 2: //active
		std::cout << "active" << std::endl;
		button.setTexture(active_texture);
		break;
	default:
		button.setTexture(texture);
	}
}