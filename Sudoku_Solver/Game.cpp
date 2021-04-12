#include "Game.h"


Game::Game()
{
	initWindow();
	initFont();
	textureIndex[0] = pushSprite("background.jpg");
	textureIndex[1] = pushSprite("introBackground.jpg");
	sprites[1].setScale(4, 4);
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
			break;
		case _SOLVING:
			//change state to active
			updateButton(_solve_, 2);
			solve->lockToggle();
			//lock the state
			solvingAlgorithmLoop(sudoku->table);
			//unlock state
			solve->lockToggle();
			solvingAlgorithmAnimation(sudoku->table);
			gamestate--;
			break;


		case _GENERATING:
			break;
		case _SETTINGS:
			break;
		}

		update();
		render();
	}
}
void Game::updateButton(int identifier, int changeState, int nr)
{
	for (int i = 0; i < sizeof(index); i++)
	{
		if (index[i] == identifier)
		{
			buttons[gamestate][i].updateButton(changeState, nr);

		}
	}
}
void Game::initTable()
{
	sudoku = new Table();

}
void Game::initWindow()
{
	//given initial values in case we can't open settings

	int vsync,height, width, frame_limit;
	//open settings and read parameters
	std::ifstream read;
	read.open("Resources\\settings.txt");
	std::string x = "Solver";
	if (read.is_open())
	{
		std::cout << "read settings from file\n";
		read >> width >> height;
		read >> frame_limit;
		read >> vsync;
		read >> x;
		read.close();
	}
	else
	{
		 vsync = 0;
		 height = 800,
			width = 600,
			frame_limit = 30;
	}

	window = new sf::RenderWindow(sf::VideoMode(width, height), x);
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
		initTable();
		break;
	case _SETTINGS:
		break;
	}

}
Button* Game::makeButton(std::string str, sf::Font* font, sf::Texture* def, sf::Texture* hover, sf::Texture* active, float x, float y, float width, float height, int id)
{
	if (index[id] == 0)
	{
		//we have an ID. 
		//this ID will be inputed into the index and 
		Button* btn = new Button(str, font, def, hover, active, x, y, width, height, id);
		buttons[gamestate].push_back(*btn);
		index[id] = buttons[gamestate].size() - 1;

		std::cout << "New button, \"" << str << "\" in gamestate " << gamestate << " at index " << index[id] << "\n";// << buttons.size() << " " << index[id] <<

	}
	return &buttons[gamestate][index[id]];
}
void Game::initState()
{

	switch (gamestate)
	{
	case _INTRO:
	{
		if (!wasinit[gamestate])
		{
			wasinit[gamestate] = !wasinit[gamestate];
			active = makeTexture("active_image.jpg");
			def = makeTexture("image.jpg");
			hover = makeTexture("hover_image.jpg");

			box = makeTexture("box.jpg");
			hover_box = makeTexture("hover_box.jpg");
			active_box = makeTexture("active_box.jpg");


			//creez un boton nou
			//ii dau assign la un pointer de buton 
			//incarc un nou array pt gamestate-ul acesta 
			//imping pe array-ul respectiv butonul 

			//stiu numarul atasat butonului 
			//pot folosi numarul ca sa aflu in ce stadiu este
			std::vector<Button> x;
			buttons.push_back(x);
			play = makeButton("play", font, def, hover, active, 200, 350, 150, 50, _play_);
			unknown = makeButton("x", font, box, hover_box, hover_box, 200, 405, 50, 50, _unknown_);
			settings = makeButton("x", font, box, hover_box, hover_box, 250, 405, 50, 50, _settings_);
		}
	}
	break;
	case _MAIN:
	{
		if (!wasinit[gamestate])
		{
			wasinit[gamestate] = !wasinit[gamestate];
			std::vector<Button> y;
			buttons.push_back(y);
			buttons.push_back(y);
			for (int j = 0, yoffset = 0, xoffset = 50; j < 9; j++, yoffset += (j % 3 == 0 && j != 0) ? 55 : 50, xoffset = 50) //col iter
			{
				std::vector<Button> y;
				boxes.push_back(y);

				for (int i = 0; i < 9; i++, xoffset += ((i % 3 == 0 && i != 0) ? 55 : 50)) // row iter
				{
					//						                |we set the number of the string. If it's 0 we set string to ""     
					Button* btn = new Button((std::to_string(sudoku->table[j][i]) == "0") ? "" : std::to_string(sudoku->table[j][i]),
						font, box, hover_box, active_box, xoffset, 105 + yoffset, 50, 50, _box_);

					boxes[j].push_back(*btn);

				}
			}

			generate = makeButton("x", font, def, hover, active, 100, 20, 150, 50, _generate_);
			solve = makeButton("solve", font, def, hover, active, 300, 20, 150, 50, _solve_);
		}


		break;
	}
	break;

	case _SETTINGS:

		break;
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
}


void Game::update()
{
	updateEvents();

	for (int i = 0; i < buttons[gamestate].size(); i++)
		updateEventButton(&buttons[gamestate][i]);

	if (gamestate == _MAIN || gamestate == _GENERATING || gamestate == _SOLVING)
		for (int j = 0; j < 9; j++)
			for (int i = 0; i < 9; i++)
			{
				updateEventButton(&boxes[j][i]);
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
			{
				if (gamestate == _MAIN) gamestate = _INTRO;
				else if (gamestate == _INTRO) window->close();
			}
			else if (event.key.code == sf::Keyboard::Enter)
				if (gamestate == _INTRO)
				{
					gamestate = _MAIN;
					initMisc(); initState();
				}
				else if (gamestate == _MAIN)
				{
					gamestate = _SOLVING;
				}
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

	if (button->bounds->contains(mousePos))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			button->updateButton(2);
			switch (button->id)
			{

			case _solve_:
				gamestate = _SOLVING;
				break;

			case _generate_:
				gamestate = _GENERATING;
				break;

			case _box_:
				break;

			case _play_: //change of menu
				gamestate = _MAIN;
				initMisc(); initState();
				break;

			case _settings_: //change of menu
				gamestate = _SETTINGS;
				initMisc(); initState();
				break;
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
	renderMisc();
	//draws boxes


	window->display();
}

void Game::renderTextures()
{
	//this works like a stack.
	//we add the textures to a vector and we draw them from front to back
	switch (gamestate)
	{

	case _INTRO:
		for (int i = 0; i < sprites.size(); i++)
		{

			window->draw(sprites[i]);
		}
		break;
	default:
		window->draw(sprites[bg]);
		for (int i = 0; i < sprites.size(); i++)
		{
			if (i == 1)continue;
			window->draw(sprites[i]);
		}
	}

}

void Game::renderMisc()
{
	switch (gamestate)
	{
	default:
		for (int i = 0; i < buttons[gamestate].size(); i++)
		{
			drawButton(buttons[gamestate][i]);

		}
		break;
		std::cout << "hey";




	case _SOLVING:
		for (int j = 0; j < 9; j++) //col iter
		{
			for (int i = 0; i < 9; i++)
			{
				drawButton(boxes[j][i]);
			}
		}
		break;
	case _GENERATING:
		for (int j = 0; j < 9; j++) //col iter
		{
			for (int i = 0; i < 9; i++)
			{
				drawButton(boxes[j][i]);
			}
		}
		break;
	case _MAIN:
		for (int j = 0; j < 9; j++) //col iter
		{
			for (int i = 0; i < 9; i++)
			{
				drawButton(boxes[j][i]);
			}
		}
		break;
	}
	if (!((gamestate == _INTRO) || (gamestate == _SETTINGS)))
		for (int i = 0; i < buttons.size() - 1; i++)
		{
			drawButton(buttons[_MAIN][i]);
		}

	//
		//if (gamestate == _SOLVING || gamestate == _GENERATING) 

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