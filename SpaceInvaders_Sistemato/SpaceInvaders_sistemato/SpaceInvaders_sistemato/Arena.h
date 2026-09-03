#pragma once
#include "Nemico.h"
#include "Navicella.h"
#include "Proiettile.h"

class Arena
{
private:

	int larghezza, altezza;
	void setLarghezza(int larghezzaPX);
	void setAltezza(int altezzaPX);

public:

	Arena(int larghezzaPX, int altezzaPX);

	//modifica arena
	void modificaArena(int larghezzaPX, int altezzaPX);

	//getter arena
	int getLarghezza();
	int getAltezza();

	//arena navicella
	void trovaNavicellaX();
	void trovaNavicellaY();

	bool spostaNavicella(int x, int y);

	//arena nemico
	void trovaNemicoX();
	void trovaNemicoY();

	bool spostaNemico(int x, int y);
	bool controllaNavicellaColpita(Nemico nemico);

	//arena proiettile
	void trovaProiettileX();
	void trovaProiettileY();

	bool spostaProiettile();
	bool controllaProiettileNemico(Nemico nemico);
};