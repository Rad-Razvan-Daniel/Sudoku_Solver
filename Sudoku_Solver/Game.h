#pragma once
#include <fstream>
#include <vector>
#include "Table.h"
#include "Sprite.h"
#include "Button.h"
#include <iostream>
#include <string>
class Game
{
	std::vector<sf::Text> texts;
	std::vector<sf::Sprite> sprites;
	std::vector<std::unique_ptr<sf::Texture>> textures;
	Button* solve;
	Button* play;
	sf::RenderWindow* window = nullptr;
	sf::Event event;
	int bg;
	sf::Font *font;

	void initWindow();
	void initFont();
	void initGame();
	void render();
	void renderTextures();
	void renderMisc();
	size_t pushSprite(const std::string& PATH);
	void popSprite();
	void updateEvents();
	void update();
	void drawbutton(Button button);
	bool isButtonHover(sf::FloatRect sprite, sf::Vector2f xy);

public:
	Game();
	~Game();
	void runPlease();
};
