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
//GAME
	sf::RenderWindow* window = nullptr;
	sf::Event event;
	int bg;
	//RENDERING
	std::vector<sf::Text> texts;
	std::vector<sf::Sprite> sprites;
	std::vector<std::unique_ptr<sf::Texture>> textures;
	sf::Font* font;
//BUTTONS
	Button* solve;
	Button* play;
	//BUTTON GRAPHICS SPECIFIC
	sf::Texture* def;
	sf::Texture* hover;
	sf::Texture* active;


	void initWindow();
	void initMisc();
	void initGame();
	void render();
	void renderTextures();
	void renderMisc();
	size_t pushSprite(const std::string& PATH);
	void popSprite();
	void updateEvents();
	void update(int state);
	void drawButton(Button button);
	void updateButton(Button button, int state);
	bool isButtonHover(Button button, sf::Vector2f xy);

public:
	Game();
	~Game();
	void runPlease();
};
