#include "Game.h"
size_t Game::pushSprite(const std::string& PATH)
{
	//std::unique_ptr<sf::Texture>texture = std::make_unique<sf::Texture>();
	auto texture = std::make_unique<sf::Texture>();
	texture->loadFromFile("Resources\\Textures\\" + PATH);
	sf::Sprite sprite;

	sprite.setTexture(*texture);

	sprites.push_back(sprite);
	textures.push_back(std::move(texture));

	return sprites.size();
}
void Game::popSprite()
{
	textures.pop_back();
}
Game::Game()
{
	initWindow();
	initMisc(); //Font, Textures
	initGame(); //Table, Button, Button

	pushSprite("img.jpg");
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

void Game::initMisc()
{
	sf::Font* temp = new sf::Font;
	sf::Texture* tTexture = new sf::Texture;
	sf::Texture* tHover = new sf::Texture;
	sf::Texture* tActive = new sf::Texture;

	temp->loadFromFile("font.ttf"); /*TODO add		Resources\\Fonts\\		before path*/ 
	tTexture->loadFromFile("Resources\\Textures\\image.jpg");
	tHover->loadFromFile("Resources\\Textures\\hover_image.jpg");
	tActive->loadFromFile("Resources\\Textures\\active_image.jpg");

	font = temp;
	def = tTexture;
	hover = tHover;
	active= tActive;
}

void Game::initGame()
{
	Table table;
	//remember to make the buttons as part of a matrix made out of buttons, and whenever you render, make a for() and check for every button, if anything changed
				//		string, font,path,path,path   x     y, width, height
	solve = new Button("solve", font,def,hover,active, 300, 50, 180,  80);
	play = new Button("play", font, def,hover,active, 100, 50,  180,  80);
	//table.printTable();
	//std::cout << table.solve() << std::endl;
	//table.printTable();
}

void Game::render()
{
	//remember to add button to the vector of printable stuff before you try to print it
	window->clear();

	renderTextures();
	//renderMisc();
	drawButton(*solve);
	drawButton(*play);

	window->display();
}

void Game::renderTextures()
{
	//this works like a stack.
	//we add the textures to a vector and we draw them in order.
	window->draw(sprites[bg]);
	for (int i = 0; i < sprites.size(); i++)
	{
		window->draw(sprites[i]);
	}
}

void Game::renderMisc()
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
			
			else if (event.key.code == sf::Keyboard::P)
			{

			}
		default:
			break;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
		//sf::Vector2i v2i = sf::Mouse::getPosition();
		}
		
	}
	
}

void Game::update()
{
	updateEvents();
	updateButton(play);
	updateButton(solve);
}

void Game::drawButton(Button button)
{
	window->draw(button.button);
	window->draw(button.text);
}

void Game::updateButton(Button* button)
{
	sf::Vector2i v2i = sf::Mouse::getPosition();
	//std::cout << v2i.x << "  " << v2i.y << std::endl;
	//button->temp(v2i);
	std::cout << "bounds:\n" << button->buttonbounds.left << "  " << button->buttonbounds.top;

	if (button->buttonbounds.contains(v2i))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			std::cout << "2";
			button->state = 2;

		}
		else
		{
			std::cout << "1";
			button->state = 1;
		}
	}
	else button->state = 0;
	button->updateTexture();
}
