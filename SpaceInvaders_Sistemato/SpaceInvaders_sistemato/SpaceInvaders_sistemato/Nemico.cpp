#include "Nemico.h"

Nemico::Nemico()
{
	this->posX = 0;
	this->posY = 0;
	this->larghezzaNemico = 0;
	this->altezzaNemico = 0;
	this->tipo = graf1;
	this->vivo = true;
	this->direzione = destra;
}

Nemico::Nemico(int posX, int posY, int larghezza, int altezza, TIPO_ALIENO tipo, DIREZIONE direzione)
{
	this->posX = posX;
	this->posY = posY;
	this->larghezzaNemico = larghezza;
	this->altezzaNemico = altezza;
	this->tipo = tipo;
	this->vivo = true;
	this->direzione = direzione;
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
DIREZIONE Nemico::getDirezione()
{
	return this->direzione;
}

void Nemico::muovi()
{
	if (this->direzione == destra)
	{
		this->posX += this->velocita;
	}
	else if(this->direzione == sinistra)
	{
		this->posX -= this->velocita;
	}	
}

void Nemico::invertiDirezioneEscendi()
{
	if (this->direzione == destra)
	{
		this->direzione = sinistra;
	}
	else
	{
		this->direzione = destra;
	}	
	this->posY += this->scendiY;
}

sf::FloatRect Nemico::getHitbox() const
{
	float percRid = 0.05f;

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