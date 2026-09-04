#pragma once
#include <SFML/Graphics.hpp>

class Navicella
{
private:

	bool viva = false;
	int nMunizioni;
	int posX, posY;
	int integrita;

	float larghezzaNavicella;
	float altezzaNavicella;
	
	void distruggi();

public:
	Navicella(int posX, int posY, float larghezzaNavicella, float altezzaNavicella, int munizioni);
	~Navicella();

	//posNavicella
	void muoviSinistra(int nPX);
	void muoviDestra(int nPX);
	
	int getPosX();
	int getPosY();

	//hitbox
	sf::FloatRect getHitbox() const; //restituisce la hitbox della navicella(x, y, larghezza, altezza)

	//stato navicella
	void riceviDanno(int nDanni);
	int getIntegrita();

	//gestione munizioni
	void spara();
	void ricarica(int quantita);
	int getMunizioni();
};