#include "GameEngine.h"

GameEngine::GameEngine(int larghezzaPX, int altezzaPX)
	: display(larghezzaPX, altezzaPX, "SPACE_INVADERS"), arena(larghezzaPX, altezzaPX)
{

}

void GameEngine::run()
{
	while (this->display.isAperto())
	{
		this->display.aggiornaDisplay();
		this->arena.aggiornaArena();
		this->display.render(this->arena);
	}
}