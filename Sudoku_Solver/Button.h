#pragma once
#include "Text.h"
#include "ButtonSprite.h"
#include <string>
class Button
{
	//the PATH will be <<image.jpg>>.  Resources\\Textures\\ will be added.
	// i did this because I want to load in inactive_texture and we can't do that
	//unless we load the path after we add the identifier before the texture

	sf::Font* font = NULL;

public:
	sf::Texture* texture = NULL;
	sf::Texture* hover_texture = NULL;
	sf::Texture* active_texture = NULL;
	Button(std::string str, sf::Font* font, sf::Texture* def, sf::Texture* hover, sf::Texture* active, float x, float y, int width, int height);

	sf::Text text;
	sf::RectangleShape button;
	int state = 0;
	sf::IntRect buttonbounds;
	void updateTexture();
	void updateNumber(int nr);
};
