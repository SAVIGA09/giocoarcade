#include "Nemico.h"

Nemico::Nemico(int posX, int posY, int larghezza, int altezza, TIPO_ALIENO tipo)
{
	this->posX = posX;
	this->posY = posY;
	this->larghezzaNemico = larghezza;
	this->altezzaNemico = altezza;
	this->tipo = tipo;
	this->vivo = true;
}

void Nemico::distruggi()
{
	this->vivo = false;
}

int Nemico::getPosX()
{
	return this->posX;
}
int Nemico::getPosY()
{
	return this->posY;
}

void Nemico::muoviSinistra(int nPX)
{
	this->posX -= nPX;
}
void Nemico::muoviDestra(int nPX)
{
	this->posX += nPX;
}

sf::FloatRect Nemico::getHitbox() const
{
	return sf::FloatRect(this->posX, this->posY, this->larghezzaNemico, this->altezzaNemico);
}

bool Nemico::getStato()
{
	return this->vivo;
}
void Nemico::colpito()
{
	this->distruggi();
}

TIPO_ALIENO Nemico::getTipo()
{
	return this->tipo;
}