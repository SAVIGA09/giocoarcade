#include "GameEngine.h"

GameEngine::GameEngine(int larghezzaPX, int altezzaPX)
{
	Display display(larghezzaPX, altezzaPX, "SPACE_INVADERS");
}

void GameEngine::run()
{
	while (display.isAperto())
	{
		display.aggiornaDisplay();

		arena.update();

		display.render(arena);
	}
}