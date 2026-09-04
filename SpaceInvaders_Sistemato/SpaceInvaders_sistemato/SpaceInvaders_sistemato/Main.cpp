#include <iostream>
#include "GameEngine.h"
#include "Display.h"

using namespace std;

int main()
{
    // Inizializza il gioco creando una finestra di 800x600 pixel
    GameEngine gioco(1920, 1080);

    // Avvia il ciclo di gioco principale
    gioco.run();

    return 0;
}