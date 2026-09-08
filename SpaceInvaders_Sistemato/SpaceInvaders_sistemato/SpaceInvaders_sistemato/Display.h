#pragma once
#include <SFML/Graphics.hpp>
#include "Arena.h"

using namespace std;

class Display
{
private:

	int larghezza, altezza;
	string nome;
	sf::RenderWindow schermo;

	sf::Texture textureNavicella;
	sf::Texture textureNemico1;
	sf::Texture textureNemico2;
	sf::Texture textureNemico3;
	sf::Texture textureProiettile;
	sf::Texture textureUFO;

	sf::Sprite spriteNavicella;
	sf::Sprite spriteNemico1;
	sf::Sprite spriteNemico2;
	sf::Sprite spriteNemico3;
	sf::Sprite spriteProiettile;
	sf::Sprite spriteUFO;

	//font

	sf::Font font;
	sf::Text testoPunteggio;
	sf::Text testoVittoria;

public:

	Display(int larghezzaPX, int altezzaPX, string nomeDisplay);
	~Display();

	void render(Arena& arena);

	//aggiornamento continuo
	void aggiornaDisplay();

	//controllo open
	bool isAperto();
};