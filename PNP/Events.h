#pragma once
#ifndef Events_h
#define Events_h

#include "SFML\Graphics.hpp"

void eventProcesing(sf::Event &event, sf::RenderWindow &gameWindow)
{
	while (gameWindow.pollEvent(event))
	{
		if (event.type == sf::Event::EventType::Closed)
		{
			gameWindow.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			gameWindow.close();
		}
	}
}
#endif // !Events_h
