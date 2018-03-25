#include "SFML\Graphics.hpp"
#include "WindowParts.h"
#include "Events.h"
#include "structures.h"
#include "structures.h"
#include "themesGenerator.h"
#include <iostream>

#define ScreenHeight 720


void startFillBoard(man (&pola)[8][8])
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; j++)
		{
			pola[i][j].isthereAman = 0;

		}
	}
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i % 2 == 0 && j % 2 == 1) || (i % 2 == 1 && j % 2 == 0))
			{
				if (i<3)
				{
					pola[j][i].isthereAman = 1;
					pola[j][i].team = 1;
				}

				if (i>4)
				{
					pola[j][i].isthereAman = 1;
					pola[j][i].team = 0;
				}
				
			}
		}
	}
}



int main(int argc, char ** argv)
{
	int themes_counts = 2,themeID=0;
	theme *themes_array;
	themes_array = new theme[themes_counts];
	fillThemesArray(&themes_array, themes_counts);
	man Pola[8][8];
	startFillBoard(Pola);

	int boxsize = ScreenHeight / 10;
	int ScreenWidth = (16 * ScreenHeight) / 9;

	sf::RenderWindow gameWindow(sf::VideoMode(ScreenWidth, ScreenHeight), "SFmL");
	sf::Texture background;
	background.loadFromFile(themes_array[themeID].link_to_background);
	sf::Sprite back;
	back.setTexture(background);
	sf::Event event;
	sf::Keyboard::setVirtualKeyboardVisible;
	while (gameWindow.isOpen())
	{

		sf::Vector2i position = sf::Mouse::getPosition(gameWindow);
		while (gameWindow.pollEvent(event))
		{
			std::cout << "PAPAJ" << std::endl;
			if (event.type == sf::Event::EventType::Closed)
			{
				gameWindow.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				gameWindow.close();
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				std::cout << position.x << " " << position.y << std::endl;
				if (position.y > 100)
				{
					if (themeID< themes_counts-1)
					{
						++themeID;
						background.loadFromFile(themes_array[themeID].link_to_background);
						sf::Sprite back;
						back.setTexture(background);
					}
					else
					{
						--themeID;
						background.loadFromFile(themes_array[themeID].link_to_background);
						sf::Sprite back;
						back.setTexture(background);
					}
				}
			}
			gameWindow.clear();
			gameWindow.draw(back);
			makeBoard(ScreenHeight, gameWindow, Pola,&themes_array,themeID);
			gameWindow.display();
		}
	}
}