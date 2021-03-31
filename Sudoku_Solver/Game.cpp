#include "Game.h"
Game::Game()
{

	initWindow();
	initGame();
	initFont();
	maingame = new GameSprite;
	maingame->pushSprite("img.jpg");
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
	//given initial values in case we can't open settings
	int vsync = 0;
	int height = 800,
		width = 600,
		frame_limit = 30;

	//open settings and read parameters
	std::ifstream read;
	read.open("Resources\\settings.txt");
	std::string x = "Solver";
	if (read.is_open())
	{
		read >> width >> height;
		read >> frame_limit;
		read >> vsync;
		read >> x;
		read.close();
	}

	window = new sf::RenderWindow(sf::VideoMode(800, 600), x);
	window->setFramerateLimit(frame_limit);
	window->setVerticalSyncEnabled(vsync);
}

void Game::initFont()
{
	font.loadFromFile("font.ttf");
	btn = new Button("Solve", font,50,200);
	btn2 = new Button("Restart",font,50,400);
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
	renderFonts();
	window->display();
}

void Game::renderTextures()
{
	//this works like a stack.
	//we add the textures to a vector and we draw them in order.
	window->draw(maingame->sprites[bg]);
	for (int i = 0; i < maingame->sprites.size(); i++)
	{
		window->draw(maingame->sprites[i]);
	}
}

void Game::renderFonts()
{
	window->draw(btn->text);
	window->draw(btn2->text);
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