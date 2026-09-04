#include "Proiettile.h"

Proiettile::Proiettile(float x, float y, int larghezza, int altezza, bool esiste)
{
	this->x = x;
	this->y = y;
	this->larghezzaProiettile = larghezza;
	this->altezzaProiettile = altezza;
	this->esiste = esiste;
}

void Proiettile::distruggi()
{
	this->esiste = false;
}

sf::FloatRect Proiettile::getHitbox() const
{
	return sf::FloatRect(this->x, this->y, this->larghezzaProiettile, this->altezzaProiettile);
}

void Proiettile::colpisci(Nemico nemico)
{
	this->distruggi();
	nemico.colpito();
}

float Proiettile::getX()
{
	return this->x;
}
float Proiettile::getY()
{
	return this->y;
}

bool Proiettile::getStato()
{
	return this->esiste;
}