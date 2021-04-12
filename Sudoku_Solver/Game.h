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
	enum gamestates{
		_INTRO,
		_MAIN,
		_SOLVING,
		_GENERATING,
		_SETTINGS,
	};
	enum buttons{
		_play_,
		_settings_,
		_generate_,
		_solve_,
		_box_
		
	};
	void initWindow();
	void initMisc(); //checks state
	void initFont();
	void initState(); //checks state
	//LOGIC

	void update(); //calls updating for every element manually added
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
	//when given an id, we go to index[id] and return the actual position
	int index[10] = { 0,0,0,0,0,0,0,0,0,0};
//BUTTONS
	Button* solve;
	Button* generate;
	Button* play;
	Button* settings;
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
	sf::Texture* makeTexture(std::string PATH);
//TABLE
	Table* sudoku;
	Button* makeButton(std::string str, sf::Font* font, sf::Texture* def, sf::Texture* hover, sf::Texture* active, float x, float y, float width, float height, int id);
	bool solvingAlgorithmLoop(int table[9][9]);

	void solvingAlgorithmAnimation(int table[9][9]);
	void updateButton(int identifier = INT_MIN, int changeState = 0, int nr = INT_MIN);
public:

	void updateEventButton(Button* button, int state = 0); //can change gamestate
	std::vector<std::vector<Button>> boxes;
	std::vector<std::vector<Button>> buttons;
	int gamestate = 0;
	sf::RenderWindow* window = nullptr;
	void mainLoop();
	void initTable();
	Game();
	~Game();
};
