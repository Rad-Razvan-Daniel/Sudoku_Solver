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
	void initWindow();
	void initMisc();
	void initUI();
	void initTable();
	//LOGIC

	void update();
	void updateEvents();
	sf::Event event;

	//RENDERING
	int bg;
	std::vector<sf::Text> texts;
	std::vector<sf::Sprite> sprites;
	std::vector<std::unique_ptr<sf::Texture>> textures;
	sf::Font* font;
	size_t pushSprite(const std::string& PATH);
	void popSprite();

	void render();
	void renderTextures();
	void renderMisc();

//BUTTONS
	Button* solve;
	Button* play;
	std::vector<std::vector<Button>> buttons;
	//BUTTON GRAPHICS SPECIFIC
	sf::Texture* def;
	sf::Texture* hover;
	sf::Texture* active;
	sf::Texture* box;
	sf::Texture* hover_box;
	sf::Texture* active_box;

	sf::Vector2i mousePos;
	//Rendering
	void drawButton(Button button);
	void updateButton(Button* button, int state = 0);
	sf::Texture* makeTexture(std::string PATH);
//TABLE
	Table* sudoku;
	bool solvingAlgorithmLoop(int row=0, int col=0);

public:
	int gamestate = 1;
	sf::RenderWindow* window = nullptr;
	void mainLoop();
	Game();
	~Game();
};
