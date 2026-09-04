#pragma once
#include "Nemico.h"
#include "Navicella.h"
#include "Proiettile.h"

enum MOVIMENTO
{
	DESTRA, SINISTRA
};

class Arena
{
private:

	int larghezza, altezza;
	void setLarghezza(int larghezzaPX);
	void setAltezza(int altezzaPX);

	Navicella navicella;
	Nemico nemico;
	Proiettile proiettile;

public:

	Arena(int larghezzaPX, int altezzaPX);

	//modifica arena
	void modificaArena(int larghezzaPX, int altezzaPX);

	//getter arena
	int getLarghezza();
	int getAltezza();

	Navicella getNavicella();
	Nemico getNemico();
	Proiettile getProiettile();

	//arena navicella
	bool spostaNavicella(MOVIMENTO direzione, int nPX);

	//arena nemico
	bool spostaNemico(MOVIMENTO direzione, int nPX);
	bool controllaNavicellaColpita(Nemico nemico);

	//arena proiettile
	bool spostaProiettile(int nPX);
	bool controllaProiettileNemico(Nemico nemico);

	//aggiorna
	void aggiornaArena();
};