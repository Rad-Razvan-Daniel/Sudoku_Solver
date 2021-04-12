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
	sf::Texture* texture = NULL;
	sf::Texture* hover_texture = NULL;
	sf::Texture* active_texture = NULL;
	int state = 0;
	bool changeable = true;
	void updateTexture(); //according to the set state, changes texture
	void setText(int nr); //according to the number given, changes the text.stirng
public:
	int id;
	Button(std::string str, sf::Font* font, sf::Texture* def, sf::Texture* hover, sf::Texture* active, float x, float y, float width, float height, int id = -1);
	sf::Text text;
	sf::RectangleShape button;
	sf::IntRect* bounds;
	void lockToggle();
	bool isLockOn();
	bool checkBounds(sf::Vector2i);
	void updateButton(int changeState = 0, int nr = INT_MIN); 

};
