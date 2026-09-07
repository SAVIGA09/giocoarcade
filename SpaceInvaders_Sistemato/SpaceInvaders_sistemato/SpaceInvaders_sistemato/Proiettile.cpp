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

void Proiettile::colpisci(Nemico& nemico)
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

void Proiettile::muoviSu(int nPX)
{
	this->y -= nPX;
}

void Proiettile::changeStato()
{
	this->esiste = !this->esiste;
}

void Proiettile::muoviX(float x)
{
	this->x = x;
}

void Proiettile::resetY(float y)
{
	this->y = y;
}

bool Proiettile::getStato()
{
	return this->esiste;
}