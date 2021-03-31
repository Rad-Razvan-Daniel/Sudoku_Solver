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
	int vsync = 0;
	int height = 800,
		width = 600,
		frame_limit = 30;

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
	btn = new Button("Solve", font);
	btn2 = new Button("Restart",font,30,30);
	btn->text.setFillColor(sf::Color::Black);
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

	window->draw(btn->text);
	renderFonts();
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

void Game::renderFonts()
{
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