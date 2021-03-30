#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <fstream>
#include <vector>
#include <iostream>


struct textures
{
	//std::vector<sf::Sprite> sprites;
};
class Game
{
	sf::Window* window = nullptr;
	sf::Event event;
public:
	Game();
	~Game();
	void runPlease();
	void initWindow();
	void initGame();
	void render();
	void updateEvents();
	void update();
};

