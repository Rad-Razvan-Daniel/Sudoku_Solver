#include "Button.h"
Button::Button(std::string str, sf::Font* font, sf::Texture* def, sf::Texture* hover, sf::Texture* active,sf::Sound* sound, float x, float y, float width, float height, int id) 
	:BaseObject(x,y,width,height, id) 
	,Text(str,font)
{
	this->sound = sound;
	texture = def;
	hover_texture = hover;
	active_texture = active;

	button.setSize(sf::Vector2f(width, height));
	button.setTexture(texture);
	button.setPosition(x, y);

	if (def->getSize().x > 100)
	{
		text.setPosition(x+30, y + 10);
	}
	else text.setPosition(x + 15, y + 5);

}
void Button::refreshTexture()
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
		
		if (changeState != state)
		{
			if (changeState == _hover && state == _active && (id == _box_ || id == _back_)) sound->play();
			else if ( (id == _play_ || id == _generate_ || id == _solve_) && changeState == _active)sound->play();
			state = changeState;
			refreshTexture();
		}
		
	}
}