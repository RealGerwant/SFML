#pragma once
#ifndef themeGenerator_h
#define themeGenerator_h

#include "structures.h"
#include "SFML\Graphics.hpp"

void fillThemesArray(theme *themesArray[], int size_of_array)
{
	(*themesArray)[0].border_color = sf::Color(210,177,130);
	(*themesArray)[0].black_box_color = sf::Color(153,102,51);
	(*themesArray)[0].white_box_color = sf::Color(222, 222, 222);
	(*themesArray)[0].black_men_clolr = sf::Color(0,0,0);
	(*themesArray)[0].white_men_clor = sf::Color(250,250,250);
	(*themesArray)[0].link_to_background = "Backgrounds/wood4.jpg";
	(*themesArray)[1].border_color = sf::Color(218, 213, 109);
	(*themesArray)[1].black_box_color = sf::Color(40, 40, 40);
	(*themesArray)[1].white_box_color = sf::Color(227, 44, 101);
	(*themesArray)[1].black_men_clolr = sf::Color(184, 135, 224);
	(*themesArray)[1].white_men_clor = sf::Color(255, 252, 225);
	(*themesArray)[1].link_to_background = "Backgrounds/code.jpg";



}

#endif // !themeGenerator_h
