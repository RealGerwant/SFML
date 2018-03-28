#include "SFML\Graphics.hpp"
#include "WindowParts.h"
#include "Events.h"
#include "structures.h"
#include "structures.h"
#include "themesGenerator.h"
#include <iostream>

#define ScreenHeight 720

void choseMan (man (&pola)[8][8],sf::Vector2i mouse_position)
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; j++)
		{
			if ( pola[j][i].isthereAman)
			{
				std::cout << pola[j][i].borders.left_border << " " << pola[j][i].borders.down_border << " " << pola[j][i].borders.right_border << " " << pola[j][i].borders.up_border << std::endl;
				if (mouse_position.y < pola[j][i].borders.up_border && mouse_position.y > pola[j][i].borders.down_border && mouse_position.x >pola[j][i].borders.left_border && mouse_position.x <pola[j][i].borders.right_border)
				{
					pola[j][i].from = 1;
				}
			}
		}
	}


}
void startFillBoard(man (&pola)[8][8])
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; j++)
		{
			pola[i][j].isthereAman = 0;
			pola[i][j].isitaplace = 0;

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
	background.loadFromFile(themes_array[themeID].link_to_background,sf::IntRect(0,0,ScreenWidth,ScreenHeight));
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
				choseMan(Pola, position);
			/*	std::cout << position.x << " " << position.y << std::endl;
				if (position.y > 100)
				{
					if (themeID< themes_counts-1)
					{
						++themeID;
					}
					else
					{
						--themeID;
					}
						background.loadFromFile(themes_array[themeID].link_to_background, sf::IntRect(0, 0, ScreenWidth, ScreenHeight));
						sf::Sprite back;
						back.setTexture(background);
			*/		

			}
			}
			gameWindow.clear();
			gameWindow.draw(back);
			makeBoard(ScreenHeight, gameWindow, Pola,&themes_array,themeID);
			gameWindow.display();
		}
	}
