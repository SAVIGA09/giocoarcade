#pragma once

class Navicella
{
public:

	Navicella();
	Navicella(int posX, int posY, int integrita, int munizioni);

	//posizione Navicella
	void muoviSinistra();
	void muoviDestra();
	void getPosizione(int& x, int& y);
	void limitaMovimento(int larghezza);

	//stato Navicella (integrità/danno)
	void riceviDanno(int danno);
	void distruggi();
	bool isAttiva();
	void setIntegrita(int integrita);
	int getIntegrita();

	//munizioni Navicella
	bool puoSparare();
	void spara();
	void ricarica(int quantita);
	void setMunizioni(int munizioni);
	int getMunizioni();

	//potenziamenti
	void attivaPotenziamento(int tipo, int durata);

	//aggiornamento stato Navicella
	void aggiorna();

private:

	int posX, posY;
	int direzione;
	int velocita;
	bool attiva;

	int integrita;
	int munizioni;

	int tempoPotenziamento;
	int tipoPotenziamento;

	int cooldownSparo;
};