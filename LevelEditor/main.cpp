#ifdef _DEBUG
#pragma comment(lib,"sfml-graphics-d.lib")
#pragma comment(lib,"sfml-audio-d.lib")
#pragma comment(lib,"sfml-system-d.lib")
#pragma comment(lib,"sfml-window-d.lib")
#pragma comment(lib,"sfml-network-d.lib")
#else
#pragma comment(lib,"sfml-graphics.lib")
#pragma comment(lib,"sfml-audio.lib")
#pragma comment(lib,"sfml-system.lib")
#pragma comment(lib,"sfml-window.lib")
#pragma comment(lib,"sfml-network.lib")
#endif

#include "Tile.h"

int Tile::count = 0;

int const SCREEN_HEIGHT{ 400 };
int const SCREEN_WIDTH{ 1300 };

sf::Vector2f getMousePosition(sf::RenderWindow& t_window);

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "sprites, text , player and collisions");

	srand(time(NULL));

	// set timePerFrame to 1 60th of a second. 60 frames per second
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	// the clock object keeps the time.
	sf::Clock clock;
	clock.restart();

	//Grid variables
	const int ROWS{ 60 };
	const int COLS{ 20 };
	const float GRID_SIZE{ 20 };
	float x = 0;
	float y = 50;

	//Mouse Position
	sf::Vector2f mousePosition;

	//Tiles
	Tile tiles[ROWS][COLS];
	Tile colorTiles[5];

	//Colour pointer
	sf::Color currentColor = sf::Color::Red;
	int colorNumber = 1;

	int posY = 25;
	//Initialize Color Tiles
	for (size_t i = 0; i < 5; i++)
	{
		colorTiles[i].setSize(sf::Vector2f{ 45,45 });
		colorTiles[i].setPosition(0, posY);
		posY += 70;
	}
	colorTiles[0].setColor(sf::Color::Red);
	colorTiles[1].setColor(sf::Color::Blue);
	colorTiles[2].setColor(sf::Color::Yellow);
	colorTiles[3].setColor(sf::Color::Green);
	colorTiles[4].setColor(sf::Color::White);

	//Initialize Level
	for (int i = 0; i < ROWS; i++)
	{
		for (int o = 0; o < COLS; o++)
		{
			tiles[i][o].setPosition(y, x);

			// X coord increment
			x += GRID_SIZE;
		}
		// Y coord increment
		y += GRID_SIZE;
		x = 0;
	}


	while (window.isOpen())
	{
		// check if the close window button is clicked on.
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//add to the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.

		//Gets mouse position
		mousePosition = getMousePosition(window);

		if (timeSinceLastUpdate > timePerFrame)
		{
			//User inputs
			if (true)
			{
				// get keyboard input.
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					for (int i = 0; i < ROWS; i++)
					{
						for (int o = 0; o < COLS; o++)
						{
							tiles[i][o].checkCollision(mousePosition, currentColor);
						}
					}
					for (size_t i = 0; i < 5; i++)
					{
						//int temp = colorNumber;
						colorNumber = colorTiles[i].checkColor(mousePosition);
						if (colorNumber != 0)
						{
							break;
						}
					}
				}
			}

			switch (colorNumber)
			{
			case 1:
				currentColor = sf::Color::Red;
				break;
			case 2:
				currentColor = sf::Color::Blue;
				break;
			case 3:
				currentColor = sf::Color::Yellow;
				break;
			case 4:
				currentColor = sf::Color::Green;
				break;
			case 5:
				currentColor = sf::Color::White;
				break;
			default:
				break;
			}

			window.clear();

			//Draw Tiles
			for (int i = 0; i < ROWS; i++)
			{
				for (int o = 0; o < COLS; o++)
				{
					tiles[i][o].draw(window);
				}
			}
			for (size_t i = 0; i < 5; i++)
			{
				colorTiles[i].draw(window);
			}

			//Display
			window.display();


			// reset the timeSinceLastUpdate to 0 
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}

	return 0;
}


sf::Vector2f getMousePosition(sf::RenderWindow& t_window)
{
	sf::Vector2f mousePosition;
	mousePosition.x = (float)sf::Mouse::getPosition(t_window).x;
	mousePosition.y = (float)sf::Mouse::getPosition(t_window).y;

	return mousePosition;
}