#pragma once
#ifndef WindowParts_h
#define WindowParts_h
#include "SFML\Graphics.hpp"
#include "structures.h"

void makeBoard(int ScreenHeight, sf::RenderWindow &renderWindow, man (&pola)[8][8], theme *Themes[], int themeID)
{
	int boxsize = ScreenHeight / 10;
	int border = boxsize / 10;

	sf::CircleShape men;
	int przes = boxsize / 3;
	men.setRadius(przes);
	sf::RectangleShape bigbox;
	bigbox.setSize(sf::Vector2f(8 * boxsize + (boxsize / border) * 2, 8 * boxsize + (boxsize / border) * 2));
	bigbox.setPosition(boxsize - boxsize / border, boxsize - boxsize / border);
	bigbox.setFillColor((*Themes)[themeID].border_color);
	renderWindow.draw(bigbox);
	for (int i = boxsize; i < 9 * boxsize; i += boxsize)
	{
		for (int j = boxsize; j < 9 * boxsize; j += boxsize)
		{
			sf::RectangleShape box;
			box.setSize(sf::Vector2f(boxsize, boxsize));
			box.setPosition(j, i);

			if ((j / boxsize % 2 == 1 && i / boxsize % 2 == 0) || (j / boxsize % 2 == 0 && i / boxsize % 2 == 1))
			{
				box.setFillColor((*Themes)[themeID].black_box_color);
			}
			else
			{
				box.setFillColor((*Themes)[themeID].white_box_color);
			}
			renderWindow.draw(box);
			if (pola[(j / boxsize) -1][(i / boxsize) - 1].isthereAman)
			{
				if (pola[(j / boxsize) - 1][(i / boxsize) - 1].team)
				{
					men.setFillColor((*Themes)[themeID].black_men_clolr);
				}
				else
				{
					men.setFillColor((*Themes)[themeID].white_men_clor);
				}
				men.setPosition(j + przes/2, i + przes/2);
				renderWindow.draw(men);
			}
		}
	}
	sf::RectangleShape buttom;
	buttom.setSize(sf::Vector2f(6 * boxsize, boxsize));
	buttom.setFillColor((*Themes)[themeID].border_color);
	buttom.setPosition(107 * boxsize / 10, boxsize);
	renderWindow.draw(buttom);

}


#endif // WindowParts_h
