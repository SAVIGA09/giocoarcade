#pragma once
#include <SFML/Graphics.hpp>

enum TIPO_ALIENO
{
	graf1, graf2, graf3
};

class Nemico
{
private:

	bool vivo = false;

	int posX, posY;
	int larghezzaNemico;
	int altezzaNemico;
	
	TIPO_ALIENO tipo;

	void distruggi();

public:

	Nemico(int posX, int posY, int larghezza, int altezza, TIPO_ALIENO tipo);

	//movimento
	void muoviDestra(int nPX);
	void muoviSinistra(int nPX);

	int getPosX();
	int getPosY();

	//hitbox
	sf::FloatRect getHitbox() const; //restituisce la hitbox del nemico(x, y, larghezza, altezza)

	//salute nemico
	bool getStato();
	void colpito();

	//tipo
	TIPO_ALIENO getTipo();
};