#include "Tastiera.h"

Tastiera::Tastiera()
{
	this->tastoSpara = sf::Keyboard::Space;
	this->tastoDestra = sf::Keyboard::Right;
	this->tastoSinistra = sf::Keyboard::Left;
}

void Tastiera::GestisciInput(Arena& arena)
{
	if (sf::Keyboard::isKeyPressed(this->tastoDestra))
	{
		arena.spostaNavicella(DESTRA, 8);
	}
	else if (sf::Keyboard::isKeyPressed(this->tastoSinistra))
	{
		arena.spostaNavicella(SINISTRA, 8);
	}
	if (sf::Keyboard::isKeyPressed(this->tastoSpara))
	{
		arena.spara();
	}
}