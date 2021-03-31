#pragma once
#include <fstream>
#include <vector>
#include <iostream>

#include "Table.h"
#include "GameSprite.h"

class Game
{
	sf::RenderWindow* window = nullptr;
	sf::Event event;
	GameSprite* maingame = nullptr;
	int bg;
public:
	Game();
	~Game();
	void runPlease();
	void initWindow();
	void initGame();
	void render();
	void renderTextures();
	void updateEvents();
	void update();
};

