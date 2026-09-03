#pragma once

class Proiettile
{
private:

	float x, y;
	bool esiste;
	void distruggi();

public:

	Proiettile(float x, float y);

	//colpisce il nemico
	void colpisci();

	//stato proiettile
	float getX();
	float getY();
	bool getStato();
};