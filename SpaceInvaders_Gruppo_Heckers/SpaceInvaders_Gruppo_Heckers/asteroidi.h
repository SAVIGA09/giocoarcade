#pragma once

class Asteroidi
{
private:
	bool distrutto;
	int xAsteroide, yAsteroide;
public:
	Asteroidi();
	bool asteroideColpito(int xColpo, int yColpo);
	void setRotto();
	void setCoordinate(char forma, int colonna, int riga);
};
