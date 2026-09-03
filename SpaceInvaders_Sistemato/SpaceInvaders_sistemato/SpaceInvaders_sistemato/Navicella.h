#pragma once

class Navicella
{
private:

	bool viva = false;
	int nMunizioni, posX, posY;
	void distruggi();

public:
	Navicella(int posX, int posY, int integrita, int munizioni);

	//posNavicella
	void muoviSinistra(int nPX);
	void muoviDestra(int nPX);
	
	int getPosX();
	int getPosY();

	//stato navicella
	void riceviDanno();
	void getIntegrita();

	//gestione munizioni
	void spara();
	void ricarica(int quantita);
	int getMunizioni();
};