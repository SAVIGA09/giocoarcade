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
	this->proiettile = Proiettile(xProiettile, yProiettile, larghezzaProiettile, altezzaProiettile, true);

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

void Arena::aggiornaArena()
{

}
