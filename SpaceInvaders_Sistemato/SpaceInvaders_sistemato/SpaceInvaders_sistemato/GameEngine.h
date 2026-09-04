#pragma once
#include "Display.h"

class GameEngine
{
private:

	Display display;
	Arena arena;

public:

	GameEngine(int larghezzaPX, int altezzaPX);

	void run();

};