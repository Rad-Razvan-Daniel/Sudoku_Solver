#include "Game.h"

Game::Game()
{
	initWindow();
	initGame();
}

Game::~Game()
{
}

void Game::runPlease()
{
	while (window->isOpen())
	{

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
	window->setVerticalSyncEnabled(1);
}

void Game::initGame()
{
}

void Game::render()
{ /*
	window->clear(sf::Color::Black);*/
	window->display();
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

}
