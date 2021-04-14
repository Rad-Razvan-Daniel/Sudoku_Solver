#include "BaseObject.h"
#include "SFML/Graphics.hpp"

BaseObject::BaseObject(float x, float y, float width, float height, int id)
{
	this->id = id;
	bounds = new sf::IntRect(x, y, width, height);
}

bool BaseObject::checkBounds(sf::Vector2i v2i)
{
	return bounds->contains(v2i);
}

