#include "Navicella.h"

Navicella::Navicella()
{
	this->posX = 0;
	this->posY = 0;
	this->integrita = 100;
	this->nMunizioni = 0;
	this->larghezzaNavicella = 0;
	this->altezzaNavicella = 0;
	this->viva = true;
}

Navicella::Navicella(int posX, int posY, float larghezzaNavicella, float altezzaNavicella, int munizioni)
{
	this->posX = posX;
	this->posY = posY;
	this->integrita = 100;
	this->nMunizioni = munizioni;
	this->larghezzaNavicella = larghezzaNavicella;
	this->altezzaNavicella = altezzaNavicella;
	this->viva = true;
}
Navicella::~Navicella()
{
	this->distruggi();
}

void Navicella::distruggi()
{
	this->viva = false;
	this->integrita = 0;
	this->nMunizioni = 0;
}

sf::FloatRect Navicella::getHitbox() const
{
	float percRid = 0.05f;

	float margineX = this->larghezzaNavicella * percRid, margineY = this->altezzaNavicella * percRid;

	return sf::FloatRect(this->posX + margineX, this->posY + margineY, this->larghezzaNavicella - (margineX * 2.0f), this->altezzaNavicella - (margineY * 2.0f));
}

void Navicella::muoviSinistra(int nPX)
{
	this->posX -= nPX;
}
void Navicella::muoviDestra(int nPX)
{
	this->posX += nPX;
}

int Navicella::getPosX()
{
	return this->posX;
}
int Navicella::getPosY()
{
	return this->posY;
}

float Navicella::getLarghezza()
{
	return this->larghezzaNavicella;
}
float Navicella::getAltezza()
{
	return this->altezzaNavicella;
}

void Navicella::riceviDanno(int nDanni)
{
	if (nDanni > this->getIntegrita())
	{
		this->distruggi();
	}
	if (nDanni <= 0)
	{
		return;
	}

	this->integrita -= nDanni;
}
int Navicella::getIntegrita()
{
	return this->integrita;
}

void Navicella::spara()
{
	if (this->nMunizioni > 0)
	{
		this->nMunizioni--;
	}
}
void Navicella::ricarica(int quantita)
{
	this->nMunizioni += quantita;
}
int Navicella::getMunizioni()
{
	return this->nMunizioni;
}