#include "Game.h"
size_t Game::pushSprite(const std::string& PATH)
{
	auto texture = std::make_unique<sf::Texture>();				//std::unique_ptr<sf::Texture>texture = std::make_unique<sf::Texture>();
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
	int gamestate = 2;
	while (window->isOpen())
	{
		if (gamestate == 1)
		{
			update();
			render();
		}
		else
		{
			solvingAlgorithmLoop();/*
			update();
			render();*/
		}
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

	//		string, font,path,path,  path    x  y, width, height
	solve = new Button("solve", font, def, hover, active, 300, 20, 180, 80);
	play = new Button("play", font, def, hover, active, 100, 20, 180, 80);
	std::vector<Button> x;

	for (int j = 0, yoffset = 0, xoffset = 50; j < 9; j++, yoffset += (j % 3 == 0 && j != 0) ? 55 : 50, xoffset = 50) //col iter
	{
		buttons.push_back(x);
		for (int i = 0; i < 9; i++, xoffset += ((i % 3 == 0 && i != 0) ? 55 : 50)) // row iter
		{
			Button* btn = new Button((std::to_string(sudoku->table[j][i]) == "0") ? "" : std::to_string(sudoku->table[j][i]), font, box, hover_box, active_box, xoffset, 105 + yoffset, 50, 50);
			buttons[j].push_back(*btn);
		}
	}
}
void Game::initTable()
{
	sudoku = new Table();



	//sudoku->consoleSolve();
	//sudoku->printTable();
}
sf::Texture* Game::makeTexture(std::string PATH)
{
	sf::Texture* temp = new sf::Texture;
	temp->loadFromFile("Resources\\Textures\\" + PATH);
	return temp;
}

bool Game::solvingAlgorithmLoop(int row, int col) //returns if it's solved or not
{

	if (row == 8 && col == 9)
		return true; 
	//safety check because when we solve() we will encounter col+1, which can be 9
	if (col == 9) {
		row++;
		col = 0;
	}
	updateButton(&buttons[row][col], 2); //

	render(); 
	if (sudoku->table[row][col] != 0)
		return solvingAlgorithmLoop(row, col + 1);

	for (int nr = 1; nr < 10; nr++)
	{
		buttons[row][col].updateNumber(nr); //
		//check validity
		if (isValid(row, col, nr))
		{
			sudoku->table[row][col] = nr;
			if (solvingAlgorithmLoop(row, col))
				return true;
		}
		//if we got here, n was wrong, meaning we should make this position the initial value; 0
		updateButton(&buttons[row][col]);
		sudoku->table[row][col] = 0;
	}
	return false;
}
bool Game::isValid(const int row, const int col, int val)
{
	for (int i = 0; i < 8; i++)
		if (sudoku->table[row][i] == val) return false;

	//check col
	for (int i = 0; i < 8; i++)
		if (sudoku->table[i][col] == val) return false;

	//check box
	int x = row - row % 3; //lets say row is 8. row%8 = 2. 8-2 = 6 ; starting from the row 6 we can play around with [6],[7],[8]
	int y = col - col % 3;
	for (int i = 0; i < 3; i++)
		for (int ii = 0; ii < 3; ii++)
			if (sudoku->table[i + x][ii + y] == val)return false;

	return true;
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
	//we add the textures to a vector and we draw them from front to back
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

	for (int j = 0; j < 9; j++) //col iter
	{
		for (int i = 0; i < 9; i++)
		{
			drawButton(buttons[j][i]);
		}
	}
}

void Game::updateEvents()
{
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();	break;

		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				window->close();
			break;

		case sf::Event::MouseMoved:
			mousePos = sf::Mouse::getPosition(*window);
			break;

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

	for (int j = 0; j < 9; j++) //col iter
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

void Game::updateButton(Button* button, int forceState)
{
	if (forceState != 0)
	{
		button->state = forceState;
	}
	else if (button->buttonbounds.contains(mousePos))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
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