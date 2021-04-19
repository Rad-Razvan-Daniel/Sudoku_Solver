#pragma once
#include <fstream>
#include <vector>
#include <iostream>
#include <string>

#include "Table.h"
#include "Sprite.h"
#include "Button.h"
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
	Button* solve = nullptr;
	Button* generate = nullptr;
	Button* play = nullptr;
	Button* settings = nullptr;
	Button* media = nullptr;
	Button* linkedin = nullptr;
	Button* back = nullptr;
	//BUTTON GRAPHICS SPECIFIC
	sf::Texture* defaultTexture = nullptr;
	sf::Texture* hoverTexture = nullptr;
	sf::Texture* activeTexture = nullptr;

	sf::Texture* defaultBoxTexture = nullptr;
	sf::Texture* hoverBoxTexture = nullptr;
	sf::Texture* activeBoxTexture = nullptr;


	sf::Texture* defaultBackTexture = nullptr;
	sf::Texture* hoverBackTexture = nullptr;
	sf::Texture* activeBackTexture = nullptr;

	sf::Vector2i mousePos;
	//Rendering
	void drawObject(Button button);
	sf::Texture* makeTexture(std::string PATH);
//TABLE
	Table* sudoku;
	Button* makeButton(std::string str, sf::Font* font, sf::Texture* def, sf::Texture* hover, sf::Texture* active,sf::Sound* sound, float x, float y, float width, float height, int id);
	bool solvingAlgorithmLoop(int table[9][9]);

	void solvingAlgorithmAnimation(int table[9][9]);
	void updateButton(int identifier = INT_MIN, int changeState = 0, int nr = INT_MIN);
	sf::SoundBuffer buffer;
	sf::Music music;
	sf::Sound buttonsound;
	sf::SoundBuffer boxbuffer;
	sf::Sound boxsound;
public:

	void updateButtonEvent(Button* button); //can change gamestate
	std::vector<std::vector<Button>> boxes;
	std::vector<std::vector<Button>> buttons;
	int gamestate = 0;
	sf::RenderWindow* window = nullptr;
	void mainLoop();
	void initTable();
	Game();
	~Game();
};
