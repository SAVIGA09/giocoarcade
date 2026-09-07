#pragma once
#include "Display.h"
#include "Arena.h"
#include "Tastiera.h"

class GameEngine
{
private:

	Display display;
	Arena arena;
	Tastiera tastiera;

public:

	GameEngine(int larghezzaPX, int altezzaPX);

	void run();

};