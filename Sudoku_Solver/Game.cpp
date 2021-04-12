#include "Game.h"


Game::Game()
{
	std::cout << "intro" << _INTRO;
	initWindow();
	initFont();
	pushSprite("background.jpg");
	pushSprite("bgoverlay.jpg");
}

void Game::mainLoop()
{
	//initMisc();
	initState();

	while (window->isOpen())
	{
		switch (gamestate)
		{
		case _INTRO:
		case _MAIN:

			update();
			render();
			break;
		case _SOLVING:
			buttons[gamestate][_solve_].updateButton(2);

			solve->lockToggle();

solvingAlgorithmLoop(sudoku->table);
solve->lockToggle();
solvingAlgorithmAnimation(sudoku->table);
gamestate--;
break;


		case _GENERATING:

			update();
			render();
			break;
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
	switch (gamestate)
	{
	case _INTRO:


		break;
	case _MAIN:


		break;

	}

}

void Game::initState()
{

	std::vector<Button> x;
	switch (gamestate)
	{
	case _INTRO:

		active = makeTexture("active_image.jpg");
		def = makeTexture("image.jpg");
		hover = makeTexture("hover_image.jpg");

		box = makeTexture("box.jpg");
		hover_box = makeTexture("hover_box.jpg");
		active_box = makeTexture("active_box.jpg");



		play = new Button("play", font, def, hover, active, 280, 300, 150, 50, _play_);

		settings = new Button("stgs", font, box, hover_box, hover_box, 250, 355, 50, 50, _settings_);

		buttons.push_back(x);
		buttons[gamestate].push_back(*play);
		buttons[gamestate].push_back(*settings);

		break;
	case _MAIN:
		for (int j = 0, yoffset = 0, xoffset = 50; j < 9; j++, yoffset += (j % 3 == 0 && j != 0) ? 55 : 50, xoffset = 50) //col iter
		{
			std::cout << "boxes.size = " << boxes.size();

			std::vector<Button> y;
			boxes.push_back(y);

			for (int i = 0; i < 9; i++, xoffset += ((i % 3 == 0 && i != 0) ? 55 : 50)) // row iter
			{
				//						                |we set the number of the string. If it's 0 we set string to ""         |

				std::string tenmpstr;
				if (&sudoku->table[j][i] == 0)
				{
					tenmpstr = "";
				}
				else
				{
					tenmpstr = std::to_string(&sudoku->table[j][i]);
				}
				Button* btn = new Button(tenmpstr,
					font, box, hover_box, active_box, xoffset, 105 + yoffset, 50, 50, _box_);

				std::cout << "created button. \n";
				boxes[j].push_back(*btn);
			}
		}
		solve = new Button("solve", font, def, hover, active, 300, 20, 150, 50, _solve_);
		generate = new Button("generate", font, def, hover, active, 100, 20, 150, 50, _generate_);


	}

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
			boxes[row][col].updateButton(1, val);
			boxes[row][col].lockToggle();
			table[row][col] = val;


			if (solvingAlgorithmLoop(table))
				return true;
			boxes[row][col].lockToggle();
			//tru again!
			table[row][col] = 0;
			boxes[row][col].updateButton(0, 0);

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
			if (boxes[j][i].isLockOn())
			{
				count++;
				boxes[j][i].lockToggle();
				boxes[i][j].updateButton(0);
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

	for (int i = 0; i < buttons[gamestate].size(); i++)
	{
		updateEventButton(&buttons[gamestate][i]);
	}

	if (gamestate != _INTRO)
	{
		for (int j = 0; j < 9; j++) //col iter
		{
			for (int i = 0; i < 9; i++)
			{
				updateEventButton(&boxes[j][i]);
			}
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
				if (gamestate == _MAIN) gamestate = _INTRO;
				else if (gamestate == _INTRO) gamestate = _MAIN;
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
			switch (button->id)
			{
			case _solve_:

				std::cout << "entered gamestate 2";
				gamestate = 2;
				break;
			case _generate_:

				std::cout << "entered gamestate 3";
				gamestate = 3;
				break;
			case _play_:

				gamestate = 1;
				initMisc(); initState();
				break;
			case _box_:
				std::cout << "pressed a box\n";
			}
			return;
		}
		std::cout << "hovering";
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
	renderMisc();
	//draws boxes


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
	for (int i = 0; i < buttons[gamestate].size(); i++)
	{
		drawButton(buttons[gamestate][i]);
	}

	if (gamestate == _MAIN)
		for (int j = 0; j < 9; j++) //col iter
		{
			for (int i = 0; i < 9; i++)
			{
				drawButton(boxes[j][i]);
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

void Game::initFont()
{
	sf::Font* temp = new sf::Font;
	temp->loadFromFile("Resources\\Fonts\\font.ttf");
	font = temp;
}
