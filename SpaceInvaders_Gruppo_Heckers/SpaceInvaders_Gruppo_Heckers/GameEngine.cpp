#include "GameEngine.h"
#include <iostream>
#include <windows.h>
using namespace std;

GameEngine::GameEngine() {
    // Inizializziamo l'arena
    this->arena = Arena(640, 480);

    // Inizializziamo gli oggetti
    this->player = Navicella(260, 125, 100, 10);
    this->alieno = Nemico(110, 100, 30, 30, "Alieno", 0);

    // Inizializziamo la barriera (Apuzz)
    this->asteroide.setCoordinate('B', 350, 430);

    this->colpoPlayer = Proiettile(0, 0, -1);
    this->colpoNemico = Proiettile(0, 0, 1);

    this->punteggio = 0;
    this->giocoInCorso = true;
}

bool GameEngine::isTerminato() {

    return !this->player.isAttiva();
}

void GameEngine::eseguiCiclo() {

    player.aggiorna();

    static int spostamentoX = 15;
    if (alieno.getX() > arena.getLimiteDestro() || alieno.getX() < arena.getLimiteSinistro()) {
        spostamentoX *= -1;
        alieno.Spostati(0, 20);
    }
    else {
        alieno.Spostati(spostamentoX, 0);
    }

    if (colpoPlayer.isAttivo())
        colpoPlayer.aggiorna();
    if (colpoNemico.isAttivo())
        colpoNemico.aggiorna();

    gestisciCollisioni();

    Sleep(100);
}

void GameEngine::gestisciCollisioni() {
 
    if (colpoPlayer.isAttivo()) {
        if (asteroide.asteroideColpito((int)colpoPlayer.getX(), (int)colpoPlayer.getY())) {
            colpoPlayer.distruggi();
            asteroide.setRotto();
            this->punteggio += 10;
        }
    }

    if (colpoNemico.isAttivo()) {
        int px, py;
        player.getPosizione(px, py);
        if (colpoNemico.getX() >= (px - 5) && colpoNemico.getX() <= (px + 5)) {
            if (colpoNemico.getY() >= py && colpoNemico.getY() <= py + 5) {
                player.riceviDanno(20);
                colpoNemico.distruggi();
            }
        }
    }
}