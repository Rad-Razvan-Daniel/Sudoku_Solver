#include "Game.h"

Game::Game()
{
	initWindow();
	initMisc(); //Font, Textures
	initTable(); //back end algorithm
	initUI(); //Table, Buttons

	pushSprite("bgoverlay.jpg");
	pushSprite("background.jpg");
}

void Game::mainLoop()
{

	while (window->isOpen())
	{
		if (gamestate == 2)
		{
			solve->updateButton(2);

			solve->lockToggle();
			solvingAlgorithmLoop(sudoku->table);
			solvingAlgorithmAnimation(sudoku->table);
			solve->lockToggle();
			update();
			render();
			gamestate--;
			continue;
		}
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

	//string, font,path,path,path,x,y,width,height
	solve = new Button("solve", font, def, hover, active, 300, 20, 150, 50);
	play = new Button("play", font, def, hover, active, 100, 20, 150, 50);
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
	for (int j = 0; j < 9; j++)
		for (int i = 0; i < 9; i++)
			if (sudoku->table[j][i] != 0)
				sudoku->validityTable[j][i];

}


bool Game::solvingAlgorithmLoop(int table[9][9]) //returns if it's solved or not
{
	update();
	render();


	int row, col;
	if (!sudoku->emptyBoxes(row, col)) return true;

	for (int val = 1; val <= 9; val++)
	{
		if (sudoku->isSafe(row, col, val))
		{
			buttons[row][col].updateButton(1, val);
			buttons[row][col].lockToggle();
			table[row][col] = val;


			if (solvingAlgorithmLoop(table))
				return true;
			buttons[row][col].lockToggle();
			//tru again!
			table[row][col] = 0;
			buttons[row][col].updateButton(0, 0);

		}
	}

	// trigger for backtracking
	return false;
}
void Game::solvingAlgorithmAnimation(int table[9][9])
{
	int count = 0;
	for (int j = 0; j < 9; j++)
	{
		for (int i = 0; i < 9; i++)
		{
			if (buttons[j][i].isLockOn())
			{
				count++;
				buttons[j][i].lockToggle();
				buttons[i][j].updateButton(0);
			}
			update();
			render();
		}
	}
	std::cout << count;
}


void Game::update()
{
	updateEvents();
	updateEventButton(play);
	updateEventButton(solve);

	for (int j = 0; j < 9; j++) //col iter
	{
		for (int i = 0; i < 9; i++)
		{
			updateEventButton(&buttons[j][i]);
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

				gamestate = 1;
			//window->close();
			break;

		case sf::Event::MouseMoved:
			mousePos = sf::Mouse::getPosition(*window);
			break;

		default:
			break;
		}
	}
}

void Game::updateEventButton(Button* button, int changeState)
{
	if (button->buttonbounds.contains(mousePos))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			button->updateButton(2);
			if (button == solve)
			{
				gamestate = 2;
			}
			return;
		}
		button->updateButton(1);
		return;
	}
	button->updateButton(0);
}



void Game::render()
{
	sf::Color bgcol(245, 243, 194);
	//remember to add button to the vector of printable stuff before you try to print it
	window->clear(bgcol);
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

void Game::drawButton(Button button)
{
	window->draw(button.button);
	window->draw(button.text);
}



Game::~Game()
{
	delete window;
}



sf::Texture* Game::makeTexture(std::string PATH)
{
	sf::Texture* temp = new sf::Texture;
	temp->loadFromFile("Resources\\Textures\\" + PATH);
	return temp;
}

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