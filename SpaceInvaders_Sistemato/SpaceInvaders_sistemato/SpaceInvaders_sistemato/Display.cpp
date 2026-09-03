#include "Display.h"

Display::Display(int larghezzaPX, int altezzaPX, string nomeDisplay)
{
	this->larghezza = larghezzaPX;
	this->altezza = altezzaPX;
	this->nome = nomeDisplay;
	this->schermo.create(sf::VideoMode(this->larghezza, this->altezza), nomeDisplay);
	this->schermo.setFramerateLimit(60);

	this->textureNavicella.loadFromFile("assets/navicella.png");
	this->textureNemico.loadFromFile("assets/nemico.png");
	this->textureProiettile.loadFromFile("assets/navicella.png");

	this->spriteNavicella.setTexture(this->textureNavicella);
	this->spriteNemico.setTexture(this->textureNemico);
	this->spriteProiettile.setTexture(this->textureProiettile);
}

Display::~Display()
{
	while (this->schermo.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			schermo.close();
		}
	}
	this->schermo.close();
}

void Display::render(Arena& arena)
{
	this->schermo.clear(sf::Color::Blue);

	this->schermo.display();
}

void Display::aggiornaDisplay()
{
	if(this->schermo.isOpen())
	{
		this->schermo.display();
	}
}

bool Display::isAperto()
{
	return this->schermo.isOpen();
}