#include "Proiettile.h"

Proiettile::Proiettile()
{
	this->x = 0;
	this->y = 0;
	this->larghezzaProiettile = 0;
	this->altezzaProiettile = 0;
	this->esiste = false;
}

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
	float percRid = 0.2f;

	float margineX = this->larghezzaProiettile * percRid, margineY = this->altezzaProiettile * percRid;

	return sf::FloatRect(this->x + margineX, this->y + margineY, this->larghezzaProiettile - (margineX * 2.0f), this->altezzaProiettile - (margineY * 2.0f));
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

float Proiettile::getAltezza()
{
	return this->altezzaProiettile;
}

float Proiettile::getLarghezza()
{
	return this->larghezzaProiettile;
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