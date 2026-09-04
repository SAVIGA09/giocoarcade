#include "Arena.h"

Arena::Arena(int larghezzaPX, int altezzaPX)
	:navicella(larghezzaPX / 2, altezzaPX - 100, 50, 50, 10), nemico(larghezzaPX / 2, 50, 50, 50, graf1), proiettile(larghezzaPX / 2, altezzaPX - 100, 10, 20)
{
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
