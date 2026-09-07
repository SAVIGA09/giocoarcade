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

float Nemico::getAltezza()
{
	return this->altezzaNemico;
}
float Nemico::getLarghezza()
{
	return this->larghezzaNemico;
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
	float percRid = 0.2f;

	float margineX = this->larghezzaNemico * percRid, margineY = this->altezzaNemico * percRid;

	return sf::FloatRect(this->posX + margineX, this->posY + margineY, this->larghezzaNemico - (margineX * 2.0f), this->altezzaNemico - (margineY * 2.0f));
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