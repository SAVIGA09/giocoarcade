#include "asteroidi.h"

Asteroidi::Asteroidi()
{
	this->distrutto = false;
	this->xAsteroide = 0;
	this->yAsteroide = 0;
}

bool Asteroidi::asteroideColpito(int xColpo, int yColpo)
{

	if (xColpo == this->xAsteroide && yColpo == this->yAsteroide)
	{
		this->distrutto = true; // Segna come distrutto
		return true;            // Comunica al main che è stato colpito
	}

	return false; // Altrimenti ritorna falso
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
		this->xAsteroide = colonna; // La colonna è la X
		this->yAsteroide = riga;    // La riga è la Y
}
