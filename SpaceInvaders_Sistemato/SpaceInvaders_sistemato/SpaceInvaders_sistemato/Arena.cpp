#include "Arena.h"

Arena::Arena(int larghezzaPX, int altezzaPX)
	:navicella(0,0,0,0,0), nemico(0,0,0,0,graf1), proiettile(0,0,0,0, false)
{
	float centroX = larghezzaPX / 2, centroY = altezzaPX / 2;

	int altezzaNavicella = altezzaPX / 10,
		larghezzaNavicella = larghezzaPX / 10;

	int altezzaNemico = altezzaPX / 10,
		larghezzaNemico = larghezzaPX / 10;

	int altezzaProiettile = altezzaPX / 10,
		larghezzaProiettile = larghezzaPX / 10;

	float metaNavicella = larghezzaNavicella / 2;
	float xNavicella = centroX - metaNavicella, yNavicella = (centroY + (centroY / 2));

	float xNemico = xNavicella, yNemico = (centroY / 4);

	float xProiettile = xNavicella, yProiettile = yNavicella;

	this->navicella = Navicella(xNavicella, yNavicella, larghezzaNavicella, altezzaNavicella, 20);
	this->nemico = Nemico(xNemico, yNemico, larghezzaNemico, altezzaNemico, graf1);
	this->proiettile = Proiettile(xProiettile, yProiettile, larghezzaProiettile, altezzaProiettile, false);

	this->setLarghezza(larghezzaPX);
	this->setAltezza(altezzaPX);
}

Navicella Arena::getNavicella()
{
	return this->navicella;
}
Nemico Arena::getNemico()
{
	return this->nemico;
}
Proiettile Arena::getProiettile()
{
	return this->proiettile;
}

void Arena::setLarghezza(int larghezzaPX)
{
	this->larghezza = larghezzaPX;
}
void Arena::setAltezza(int altezzaPX)
{
	this->altezza = altezzaPX;
}
void Arena::modificaArena(int larghezzaPX, int altezzaPX)
{
	this->setLarghezza(larghezzaPX);
	this->setAltezza(altezzaPX);
}
int Arena::getAltezza()
{
	return this->altezza;
}
int Arena::getLarghezza()
{
	return this->larghezza;
}

bool Arena::spostaNavicella(MOVIMENTO direzione, int nPX)
{
	switch (direzione)
	{
	case DESTRA:
		if ((this->navicella.getPosX() + (this->navicella.getHitbox().width/1.5)) < this->larghezza)
		{
			this->navicella.muoviDestra(nPX);
			return true;
		}
		return false;
		break;
	case SINISTRA:
		if (this->navicella.getPosX() > 0)
		{
			this->navicella.muoviSinistra(nPX);
			return true;
		}
		return false;
		break;
	default:
		break;
	}
}

bool Arena::spostaNemico(MOVIMENTO direzione, int nPX)
{
	switch (direzione)
	{
	case DESTRA:
		if (this->nemico.getPosX() < this->larghezza)
		{
			this->nemico.muoviDestra(nPX);
			return true;
		}
		return false;
		break;
	case SINISTRA:
		if (this->nemico.getPosX() > 0)
		{
			this->nemico.muoviSinistra(nPX);
			return true;
		}
		return false;
		break;
	default:
		break;
	}
}

void Arena::spostaProiettile(int nPX)
{
	if (this->proiettile.getY() > 0)
	{
		this->proiettile.muoviSu(nPX);
	}
}

void Arena::spara()
{
	if (!this->proiettile.getStato())
	{
		this->proiettile.resetY(this->navicella.getPosY());
		this->proiettile.changeStato();
	}
}

bool Arena::controllaNavicellaColpita(Nemico& nemico)
{
	if (this->navicella.getHitbox().intersects(nemico.getHitbox()))
	{
		this->navicella.riceviDanno(35);
		return true;
	}
	return false;
}

bool Arena::controllaProiettileNemico(Nemico& nemico)
{
	if (!nemico.getStato())
	{
		return false;
	}

	if (this->proiettile.getHitbox().intersects(nemico.getHitbox()))
	{
		this->proiettile.colpisci(nemico);
		return true;
	}
	return false;
}

void Arena::aggiornaArena()
{
	if (!this->proiettile.getStato())
	{
		this->proiettile.muoviX(this->navicella.getPosX());
		this->proiettile.resetY(this->navicella.getPosY());
	}

	else
	{
		if (this->controllaProiettileNemico(this->nemico))
		{
			this->proiettile.resetY(this->navicella.getPosY());
		}

		if ((this->proiettile.getY()-10) <= 0)
		{
			this->proiettile.changeStato();
			this->proiettile.resetY(this->navicella.getPosY());			
		}
		else
		{
			this->proiettile.muoviSu(10);
		}

		if (this->controllaNavicellaColpita(this->nemico))
		{
			this->navicella.riceviDanno(35);
		}
	}
}