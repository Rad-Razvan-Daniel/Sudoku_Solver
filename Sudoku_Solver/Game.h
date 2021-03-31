#pragma once
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include "Table.h"
#include "GameSprite.h"
#include "Button.h"
class Game
{
	Button *btn;
	Button *btn2;
	sf::RenderWindow* window = nullptr;
	sf::Event event;
	GameSprite* maingame = nullptr;
	int bg;
	sf::Font font;

public:
	sf::Text text;
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
