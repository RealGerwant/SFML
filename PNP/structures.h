#pragma once
#ifndef structures_h
#define structures_h

#include "SFML\Graphics.hpp"

struct theme
{
	sf::Color border_color;
	sf::Color white_box_color;
	sf::Color black_box_color;
	sf::Color white_men_clor;
	sf::Color black_men_clolr;
	std::string link_to_background;
};


struct borders
{
	int left_border;
	int down_border;
	int right_border;
	int up_border;
};

struct man  //place
{
	bool isitaplace = 1;
	bool isthereAman;
	bool team; //white = 0
	bool king; //no king = 0
	borders borders;
	bool from = 0;
	bool to = 0;

};

#endif // !structures_h
