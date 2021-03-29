#include "Game.h"

Game::Game()
{
	bool vsync = 0;
	int frame_limit = 30;
	int height = 800, width = 600;

	std::ifstream read("settings.txt");
	read >> width >> height;
	read >> frame_limit;
	read >> vsync;
	read.close();

	/*window = new sf::RenderWindow(sf::VideoMode(width, height), "Sudoku Solver", sf::Style::Default);
	window->setFramerateLimit(frame_limit);
	window->setVerticalSyncEnabled(vsync);
	*/
}

Game::~Game()
{
}

void Game::initGame()
{
}

void Game::render()
{ 
	//window->clear();
}

void Game::update()
{
}
