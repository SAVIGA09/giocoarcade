#include "GameEngine.h"

GameEngine::GameEngine(int larghezzaPX, int altezzaPX)
	: display(larghezzaPX, altezzaPX, "SPACE_INVADERS"), arena(larghezzaPX, altezzaPX)
{

}

void GameEngine::run()
{
	while (this->display.isAperto())
	{
		this->tastiera.GestisciInput(this->arena);
		this->arena.aggiornaArena();
		this->display.aggiornaDisplay();
		this->display.render(this->arena);
		
	}
}