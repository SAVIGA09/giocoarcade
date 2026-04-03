#include "asteroidi.h"

Asteroidi::Asteroidi()
{
	this->distrutto = false;
	this->xAsteroide = 0;
	this->yAsteroide = 0;
}

bool Asteroidi::asteroideColpito(int xColpo, int yColpo)
{
	int contatore = 0;
	if (xColpo == this->xAsteroide && yColpo == this->yAsteroide)
	{
		contatore++;
	}
	if (contatore == 2)
	{
		this->distrutto = true;
	}
}

void Asteroidi::setRotto()
{
	if (this->distrutto)
	{
		this->xAsteroide = 0;
		this->yAsteroide = 0;
	}
}

void Asteroidi::setCoordinate(char forma, int colonna, int riga)
{
	this->xAsteroide = riga;
	this->yAsteroide = colonna;
}
