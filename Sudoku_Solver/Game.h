#pragma once
#include <fstream>
#include <vector>
#include "Table.h"
#include "Sprite.h"
#include "Button.h"
#include <iostream>
#include "SFML/Audio.hpp"
#include <string>
#include "enums.h"
class Game
{
//GAME

	bool wasinit[10];
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
	void renderSprites();
	void renderUIbuttons();
	//when given an id, we go to index[id] and return the actual position
	int index[10] = { 0,0,0,0,0,0,0,0,0,0};
	int textureIndex[4];
//BUTTONS
	Button* solve;
	Button* generate;
	Button* play;
	Button* settings; 
	Button* unknown;
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
	Button* makeButton(std::string str, sf::Font* font, sf::Texture* def, sf::Texture* hover, sf::Texture* active,sf::Sound* sound, float x, float y, float width, float height, int id);
	bool solvingAlgorithmLoop(int table[9][9]);

	void solvingAlgorithmAnimation(int table[9][9]);
	void updateButton(int identifier = INT_MIN, int changeState = 0, int nr = INT_MIN);
	sf::SoundBuffer buffer;
	sf::Music music;
	sf::Sound sound;
	sf::SoundBuffer boxbuffer;
	sf::Sound boxsound;
public:

	void updateEventButton(Button* button); //can change gamestate
	std::vector<std::vector<Button>> boxes;
	std::vector<std::vector<Button>> buttons;
	int gamestate = 0;
	sf::RenderWindow* window = nullptr;
	void mainLoop();
	void initTable();
	Game();
	~Game();
};
