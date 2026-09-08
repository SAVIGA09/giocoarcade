#include "Display.h"

Display::Display(int larghezzaPX, int altezzaPX, string nomeDisplay)
{
	this->larghezza = larghezzaPX;
	this->altezza = altezzaPX;
	this->nome = nomeDisplay;
	this->schermo.create(sf::VideoMode(this->larghezza, this->altezza), nomeDisplay);
	this->schermo.setFramerateLimit(60);

	this->textureNavicella.loadFromFile("assets/navicella.png");
	this->textureNemico1.loadFromFile("assets/nemico1.png");
	this->textureNemico2.loadFromFile("assets/nemico2.png");
	this->textureNemico3.loadFromFile("assets/nemico3.png");
	this->textureProiettile.loadFromFile("assets/proiettile.png");
	this->textureUFO.loadFromFile("assets/UFO.png");

	this->spriteNavicella.setTexture(this->textureNavicella);
	this->spriteNemico1.setTexture(this->textureNemico1);
	this->spriteNemico2.setTexture(this->textureNemico2);
	this->spriteNemico3.setTexture(this->textureNemico3);
	this->spriteProiettile.setTexture(this->textureProiettile);
	this->spriteUFO.setTexture(this->textureUFO);

	//font
	if (this->font.loadFromFile("assets/PressStart2P-Regular.ttf"))
	{
		this->testoPunteggio.setFont(this->font);
		this->testoPunteggio.setCharacterSize(24);
		this->testoPunteggio.setFillColor(sf::Color::White);
		this->testoPunteggio.setPosition(20.0f, 10.0f);
	}
	if (this->font.loadFromFile("assets/PressStart2P-Regular.ttf"))
	{
		this->testoVittoria.setFont(this->font);
		this->testoVittoria.setString("HAI VINTO");
		this->testoVittoria.setCharacterSize(40);
		this->testoVittoria.setFillColor(sf::Color::Green);

		sf::FloatRect textRect = this->testoVittoria.getLocalBounds();
		this->testoVittoria.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
		this->testoVittoria.setPosition(sf::Vector2f(this->larghezza / 2.0f, this->altezza / 2.0f));
	}
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

	if (arena.controllaVittoria())
	{
		this->schermo.draw(this->testoVittoria);

		this->testoPunteggio.setString("SCORE: " + to_string(arena.getPunteggio()));
		this->schermo.draw(this->testoPunteggio);
		this->schermo.display();
		return;
	}

	Proiettile proiettile = arena.getProiettile();

	if (proiettile.getStato())
	{
		sf::Vector2u sizeProiettile = this->textureProiettile.getSize();
		sf::FloatRect hitboxProiettile = proiettile.getHitbox();

		if (sizeProiettile.x > 0 && sizeProiettile.y > 0)
		{
			float scalaX = (float)proiettile.getLarghezza() / sizeProiettile.x;
			//float scalaY = (float)proiettile.getAltezza() / sizeProiettile.y;

			this->spriteProiettile.setScale(scalaX, scalaX);
		}

		this->spriteProiettile.setPosition(proiettile.getX(), proiettile.getY());
		this->schermo.draw(this->spriteProiettile);
	}

	Navicella navicella = arena.getNavicella();

	sf::Vector2u sizeNavicella = this->textureNavicella.getSize();
	sf::FloatRect hitboxNavicella = navicella.getHitbox();

	if (sizeNavicella.x > 0 && sizeNavicella.y > 0)
	{
		float scalaX = (float)navicella.getLarghezza() / sizeNavicella.x;
		//float scalaY = (float)navicella.getAltezza() / sizeNavicella.y;

		this->spriteNavicella.setScale(scalaX, scalaX);
	}

	this->spriteNavicella.setPosition(navicella.getPosX(), navicella.getPosY());
	this->schermo.draw(this->spriteNavicella);

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 10; c++)
		{
			Nemico nemico = arena.getNemico(r, c);

			if (nemico.getStato())
			{
				sf::Vector2u sizeNemico;

				switch (nemico.getTipo())
				{
				case graf1:
					sizeNemico = this->textureNemico1.getSize();
					break;
				case graf2:
					sizeNemico = this->textureNemico2.getSize();
					break;
				case graf3:
					sizeNemico = this->textureNemico3.getSize();
					break;
				default:
					break;
				}

				sf::FloatRect hitboxNemico = nemico.getHitbox();

				if (sizeNemico.x > 0 && sizeNemico.y > 0)
				{
					float scalaX = (float)nemico.getLarghezza() / sizeNemico.x;
					//float scalaY = (float)nemico.getAltezza() / sizeNemico.y;

					switch (nemico.getTipo())
					{
					case graf1:
						this->spriteNemico1.setScale(scalaX, scalaX);
						this->spriteNemico1.setPosition(nemico.getPosX(), nemico.getPosY());
						this->schermo.draw(this->spriteNemico1);
						break;
					case graf2:
						this->spriteNemico2.setScale(scalaX, scalaX);
						this->spriteNemico2.setPosition(nemico.getPosX(), nemico.getPosY());
						this->schermo.draw(this->spriteNemico2);
						break;
					case graf3:
						this->spriteNemico3.setScale(scalaX, scalaX);
						this->spriteNemico3.setPosition(nemico.getPosX(), nemico.getPosY());
						this->schermo.draw(this->spriteNemico3);
						break;
					default:
						break;
					}
				}
			}
		}
	}

	//punteggio
	this->testoPunteggio.setString("SCORE: " + to_string(arena.getPunteggio()));
	this->schermo.draw(this->testoPunteggio);

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