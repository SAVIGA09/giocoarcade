#pragma once
#include <SFML/Graphics.hpp>
#include "Nemico.h"

class Proiettile
{
private:

	float x, y;
	int larghezzaProiettile;
	int altezzaProiettile;

	bool esiste;
	void distruggi();

public:

	Proiettile(float x, float y, int larghezza, int altezza);

	//colpisce il nemico
	void colpisci(Nemico nemico);

	//stato proiettile
	float getX();
	float getY();

	sf::FloatRect getHitbox() const; //restituisce la hitbox del proiettile(x, y, larghezza, altezza)

	bool getStato();
};