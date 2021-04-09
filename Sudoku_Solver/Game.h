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
	std::vector<Button> buttons;
	//BUTTON GRAPHICS SPECIFIC
	sf::Texture* def;
	sf::Texture* hover;
	sf::Texture* active;
	sf::Texture* box;
	sf::Texture* hover_box;
	sf::Texture* active_box;

	sf::Vector2i mousePos;
	void initWindow();
	void initMisc();
	void initUI();

	void render();
	void renderTextures();
	void renderMisc();

	size_t pushSprite(const std::string& PATH);
	void popSprite();

	void update();
	void updateEvents();


	void drawButton(Button button);
	void updateButton(Button* button);
	void initTable();
	sf::Texture* makeTexture(std::string PATH);
public:
	void mainLoop();
	Game();
	~Game();
	
};
