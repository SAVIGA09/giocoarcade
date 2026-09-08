#pragma once
#include <SFML/Graphics.hpp>

enum TIPO_ALIENO
{
	graf1, graf2, graf3
};

enum DIREZIONE
{
	destra, sinistra
};

class Nemico
{
private:

	bool vivo = false;

	int posX, posY;
	int larghezzaNemico;
	int altezzaNemico;

	int velocita = 5;
	int scendiY = 40;

	TIPO_ALIENO tipo;

	DIREZIONE direzione;

	void distruggi();

public:

	Nemico();
	Nemico(int posX, int posY, int larghezza, int altezza, TIPO_ALIENO tipo, DIREZIONE direzione);

	//movimento
	void muovi();
	void invertiDirezioneEscendi();

	int getPosX();
	int getPosY();

	float getAltezza();
	float getLarghezza();
	DIREZIONE getDirezione();

	//hitbox
	sf::FloatRect getHitbox() const; //restituisce la hitbox del nemico(x, y, larghezza, altezza)

	//salute nemico
	bool getStato();
	void colpito();

	//tipo
	TIPO_ALIENO getTipo();
};