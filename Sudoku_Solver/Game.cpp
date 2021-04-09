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
	initTable(); //back end algorithm
	initUI(); //Table, Buttons

	//used for rendering background
	pushSprite("background.jpg");
}
Game::~Game()
{
	delete window;
}

void Game::mainLoop()
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
	temp->loadFromFile("Resources\\font.ttf");

	font = temp;
	def = makeTexture("image.jpg");
	hover = makeTexture("hover_image.jpg");
	active = makeTexture("active_image.jpg");
	box = makeTexture("box.jpg"); 
	active_box = makeTexture("active_box.jpg"); 
	hover_box = makeTexture("hover_box.jpg"); 
} 

void Game::initUI()
{
	Table table;
				//		string, font,path,path,  path    x  y, width, height
	solve =  new Button("solve", font,def,hover,active, 300, 20, 180,  80);
	play = new Button("play", font, def,hover,active, 100, 20,  180,  80);
	std::vector<Button> x;

	
	for (int j = 0, xoffset = 0, yoffset = 0; j < 9; j++,yoffset+=(j%3 ==0 && j!=0)?55:50) //column iter
	{
		buttons.push_back(x);
		for (int i = 0; i < 9; i++, xoffset += 50) // row iter
		{
			Button* btn = new Button("nr", font, box, hover_box, active_box, ((i%3==2)? 50: 55) +xoffset, 100 + yoffset, 50, 50);
			std::cout << i << " " << j << std::endl;
			buttons[j].push_back(*btn);
		}
		xoffset = 0;
	}
	//table.printTable();
	//std::cout << table.solve() << std::endl;
	//table.printTable();
}
void Game::initTable()
{

}
sf::Texture* Game::makeTexture(std::string PATH)
{
	sf::Texture* temp = new sf::Texture;
	temp->loadFromFile("Resources\\Textures\\" + PATH);
	return temp;
}
void Game::render()
{
	//remember to add button to the vector of printable stuff before you try to print it
	window->clear();
	//draws everything except interractables.
	renderTextures();
	//draws buttons
	renderMisc();

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
	drawButton(*solve);
	drawButton(*play);

	for (int j = 0; j < 9; j++) //column iter
	{
		for (int i = 0; i < 9; i++)
		{
			drawButton(buttons[j][i]);
		}
	}
}

void Game::updateEvents()
{

	mousePos = sf::Mouse::getPosition();
	while (window->pollEvent(event))
	{
		switch (event.type)
		{

		case sf::Event::Closed:
			window->close();	break;


		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				window->close();	break;

		default:
			break;
		}
		
	}
	
}

void Game::update()
{
	updateEvents();
	updateButton(play);
	updateButton(solve);

	for (int j = 0; j < 9; j++) //column iter
	{
		for (int i = 0; i < 9; i++)
		{
			updateButton(&buttons[j][i]);
		}
	}
}

void Game::drawButton(Button button)
{
	window->draw(button.button);
	window->draw(button.text);
}

void Game::updateButton(Button* button)
{
	std::cout << std::endl << button->buttonbounds.left << "|" << button->buttonbounds.top << "|" << button->buttonbounds.height << "|" << button->buttonbounds.width << "|";

	if (button->buttonbounds.contains(mousePos))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			std::cout << "State 2 \n";
			button->state = 2;

		}
		else
		{
			std::cout << "State 1 \n";
			button->state = 1;
		}
	}
	else button->state = 0;
	button->updateTexture();
}
