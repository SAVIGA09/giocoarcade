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
	sf::Texture textureNemico;
	sf::Texture textureProiettile;

	sf::Sprite spriteNavicella;
	sf::Sprite spriteNemico;
	sf::Sprite spriteProiettile;

public:

	Display(int larghezzaPX, int altezzaPX, string nomeDisplay);
	~Display();

	void render(Arena& arena);

	//aggiornamento continuo
	void aggiornaDisplay();

	//controllo open
	bool isAperto();
};