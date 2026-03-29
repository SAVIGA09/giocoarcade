#pragma once
#include <string>
#include <windows.h>
#include <gdiplus.h> //per trasformare i dati in qualcosa che si puo vedere a schermo
using namespace std;
using namespace Gdiplus;

class Nemico
{
private: //dichiarazione variabili private
	int x;
	int y;
	int width;
	int height;
	int phase;
	string type;
	Color color;
	bool isAlive;

public:
	//dichiarazione costruttore nemico e metodi da utilizzare e definire
	Nemico();
	Nemico(int x, int y, int height, int width, string type, Color color);
	void GotHit();
	bool Unalive();
	void ShiftSx(int pixel);
	void ShiftDx(int pixel);
	void ShiftUp(int pixel);
	void ShiftDown(int pixel);
	void Shift();
	void ChangePhase();
	void Shoot();
};