#pragma once
//#include "SFML/Graphics.hpp"
#include <fstream>
#include <vector>
#include <iostream>


struct textures
{
	//std::vector<sf::Sprite> sprites;
};
class Game
{/*
	sf::RenderWindow* window;
	sf::Event event;*/
public:
	Game();
	~Game();
	void initGame();
	void render();
	void update();
};

