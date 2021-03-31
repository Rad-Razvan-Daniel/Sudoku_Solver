#include "Game.h"
Game::Game()
{
	initWindow();
	initGame();
	maingame = new GameSprite;
	maingame->newSprite("img.jpg");

}

Game::~Game()
{
	delete window;
}

void Game::runPlease()
{
	while (window->isOpen())
	{
		update();
		render();
	}
}

void Game::initWindow()
{
	int vsync = 0;
	int height = 800, 
		width = 600, 
		frame_limit = 30;

	std::ifstream read;
	read.open("settings.txt");
	if (read.is_open())
	{
		read >> width >> height;
		read >> frame_limit;
		read >> vsync;
		read.close();
	}

	window = new sf::RenderWindow(sf::VideoMode(800, 600), "tet");
	window->setFramerateLimit(frame_limit);
	window->setVerticalSyncEnabled(vsync);
}

void Game::initGame()
{

	
	Table table;
	//table.printTable();
	//std::cout << table.solve() << std::endl;
	//table.printTable();
}

void Game::render()
{ 
	window->clear();
	renderTextures();
	window->display();
}

void Game::renderTextures()
{
	window->draw(maingame->sprites[bg]);
	for (int i = 0; i < maingame->sprites.size(); i++)
	{
		window->draw(maingame->sprites[i]);
	}
}

void Game::updateEvents()
{

	while (window->pollEvent(event))
	{
		switch (event.type)
		{

		case sf::Event::Closed:
			window->close();
			break;

			// key pressed
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				window->close();
			break;

			// we don't process other types of events
		default:
			break;
		}
	}
}

void Game::update()
{
	updateEvents();
}
