#pragma once
#include "Text.h"
#include "BaseObject.h"
#include "SFML/Audio.hpp"
#include "ButtonSprite.h"
#include <string>
#include <iostream>
#include "enums.h"
class Button:public BaseObject,public Text
{
	//the PATH will be <<image.jpg>>.  Resources\\Textures\\ will be added.
	// i did this because I want to load in inactive_texture and we can't do that
	//unless we load the path after we add the identifier before the texture

	sf::Texture* texture = NULL;
	sf::Texture* hover_texture = NULL;
	sf::Texture* active_texture = NULL;
	sf::Sound* sound;
	bool changeable = true;
	void refreshTexture(); //according to the set state, changes texture
	void setText(int nr); //according to the number given, changes the text.stirng

public:

	int state = 0;
	Button(std::string str, sf::Font* font, sf::Texture* def, sf::Texture* hover, sf::Texture* active, sf::Sound* sound,float x, float y, float width, float height, int id = -1);
	sf::RectangleShape button;
	void lockToggle();
	bool isLockOn();
	void updateButton(int changeState = 0, int nr = INT_MIN); 
	
};
