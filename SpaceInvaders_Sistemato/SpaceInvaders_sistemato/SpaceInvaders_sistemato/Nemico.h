#pragma once

enum TIPO_ALIENO
{
	graf1, graf2, graf3
};

class Nemico
{
private:

	bool vivo = false;
	
	TIPO_ALIENO tipo;

	void distruggi();

public:

	Nemico(int posX, int posY, TIPO_ALIENO tipo);

	//movimento
	void muoviDestra(int nPX);
	void muoviSinistra(int nPX);

	int getPosX();
	int getPosY();

	//salute nemico
	bool getStato();
	void colpito();

};