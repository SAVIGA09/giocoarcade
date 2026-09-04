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
	this->textureProiettile.loadFromFile("assets/proiettile.png");

	this->spriteNavicella.setTexture(this->textureNavicella);
	this->spriteNemico.setTexture(this->textureNemico);
	this->spriteProiettile.setTexture(this->textureProiettile);
}

Display::~Display()
{
	sf::Event event;

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
	this->schermo.clear(sf::Color::Black);

	Navicella navicella = arena.getNavicella();

	sf::Vector2u sizeNavicella = this->textureNavicella.getSize();
	sf::FloatRect hitboxNavicella = navicella.getHitbox();

	if (sizeNavicella.x > 0 && sizeNavicella.y > 0)
	{
		this->spriteNavicella.setScale(hitboxNavicella.width / sizeNavicella.x, hitboxNavicella.height / sizeNavicella.y);
	}

	this->spriteNavicella.setPosition(navicella.getPosX(), navicella.getPosY());
	this->schermo.draw(this->spriteNavicella);

	Nemico nemico = arena.getNemico();

	if (nemico.getStato())
	{
		sf::Vector2u sizeNemico = this->textureNemico.getSize();
		sf::FloatRect hitboxNemico = nemico.getHitbox();

		if (sizeNemico.x > 0 && sizeNemico.y > 0)
		{
			this->spriteNemico.setScale(hitboxNemico.width / sizeNemico.x, hitboxNemico.height / sizeNemico.y);
		}

		this->spriteNemico.setPosition(nemico.getPosX(), nemico.getPosY());
		this->schermo.draw(this->spriteNemico);
	}

	Proiettile proiettile = arena.getProiettile();

	sf::Vector2u sizeProiettile = this->textureProiettile.getSize();
	sf::FloatRect hitboxProiettile = proiettile.getHitbox();

	if (sizeProiettile.x > 0 && sizeProiettile.y > 0)
	{
		this->spriteProiettile.setScale(hitboxProiettile.width / sizeProiettile.x, hitboxProiettile.height / sizeProiettile.y);
	}

	this->spriteProiettile.setPosition(proiettile.getX(), proiettile.getY());
	this->schermo.draw(this->spriteProiettile);

	this->schermo.display();
}

void Display::aggiornaDisplay()
{
	sf::Event evento;

	while (this->schermo.pollEvent(evento))
	{
		if (evento.type == sf::Event::Closed)
		{
			this->schermo.close();
		}
	}
}

bool Display::isAperto()
{
	return this->schermo.isOpen();
}