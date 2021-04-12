#include "Button.h"
#include <iostream>
Button::Button(std::string str, sf::Font* font, sf::Texture* def, sf::Texture* hover, sf::Texture* active, float x, float y, float width, float height,int id)
{
#pragma region
	this->font = font;
	texture = def;
	hover_texture = hover;
	active_texture = active;

	button.setSize(sf::Vector2f(width, height));
	button.setTexture(texture);
	button.setPosition(x, y);

	this->id = id;
	buttonbounds.left = x;
	buttonbounds.top = y;
	buttonbounds.height = height;
	buttonbounds.width = width;
#pragma endregion

	text.setFont(*font);
	text.setString(str);

	//TODO: center the text within the box using the getGlobalPosition
	//we move the text by x to the right, to accomodate for the offset
	//
	//we estmate the text length. we substract that from the total length.
	if (def->getSize().x > 100)
	{
		text.setPosition(x + str.length() * 10, y + 10);
	}
	else text.setPosition(x + 10, y + 10);
	text.setFillColor(sf::Color::Black);

}
void Button::updateTexture()
{
	switch (state)
	{
	case 1: // hover
		button.setTexture(hover_texture);

		break;
	case 2: //active
		button.setTexture(active_texture);
		break;
	default:
		button.setTexture(texture);
	}
}


void Button::setText(int nr)
{
	if (nr == 0)
	{
		text.setString("");
		return;
	}
	text.setString(std::to_string(nr));
}

void Button::lockToggle()
{
	changeable = !changeable;
}
bool Button::isLockOn()
{
	return !changeable;
}
void Button::updateButton(int changeState, int nr)
{
	if (changeable)
	{
		if (nr != INT_MIN)
			setText(nr);
		state = changeState;
		updateTexture();
	}
}
