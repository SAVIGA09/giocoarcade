#pragma once
#include <SFML/Graphics.hpp>
#include "Arena.h"

class Tastiera
{
private:

	sf::Keyboard::Key tastoSpara;
	sf::Keyboard::Key tastoDestra;
	sf::Keyboard::Key tastoSinistra;

public:

	Tastiera();

	void GestisciInput(Arena& arena);
};