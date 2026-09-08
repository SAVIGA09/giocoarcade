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
	bool haVinto;

	Navicella navicella;
	Nemico alieni[3][10];
	Proiettile proiettile;

	int punteggio = 0;

public:

	Arena(int larghezzaPX, int altezzaPX);

	//modifica arena
	void modificaArena(int larghezzaPX, int altezzaPX);

	//getter arena
	int getLarghezza();
	int getAltezza();

	Navicella getNavicella();
	Nemico getNemico(int riga, int col);
	Proiettile getProiettile();

	//arena navicella
	void spostaNavicella(MOVIMENTO direzione, int nPX);

	//arena nemico
	void spostaNemico();
	bool controllaNemicoNavicella(Nemico& nemico);

	//arena proiettile
	void spara();
	void spostaProiettile(int nPX);
	bool controllaProiettileNemico(Nemico& nemico);

	//punteggio
	int getPunteggio();
	bool controllaVittoria();

	//aggiorna
	void aggiornaArena();
};