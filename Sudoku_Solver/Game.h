#pragma once
#include <fstream>
#include <vector>
#include "Table.h"
#include "GameSprite.h"
#include "Button.h"
#include <iostream>
#include <string>
class Game
{
/*	Button *btn;
	Button *btn2;*/
	std::vector<sf::Text> texts;
	std::vector<sf::Sprite> sprites;
	std::vector<std::unique_ptr<sf::Texture>> textures;

	sf::RenderWindow* window = nullptr;
	sf::Event event;
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
	size_t pushSprite(const std::string& PATH);
	void popSprite();
	void updateEvents();
	void update();
};
