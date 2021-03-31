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
	sf::Font font;
	sf::Text text;
public:
	Game();
	~Game();
	void runPlease();
	void initWindow();
	void initFont();
	void initGame();
	void render();
	void renderTextures();
	void renderFonts();
	void updateEvents();
	void update();
};

