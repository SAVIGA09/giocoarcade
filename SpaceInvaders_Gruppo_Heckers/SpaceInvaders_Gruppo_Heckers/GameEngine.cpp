#include "GameEngine.h"
#include <iostream>
#include <windows.h>

using namespace std;

GameEngine::GameEngine() {
    inizializza();
}

void GameEngine::inizializza() {
    this->arena = Arena(640, 480);
    this->player = Navicella(320, 440, 100, 10);

    int indice = 0;
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 11; c++) {
            this->alieni[indice] = Nemico(100 + (c * 40), 50 + (r * 30), 30, 30, "Alieno", 10);
            indice++;
        }
    }

    for (int i = 0; i < 4; i++) {
        this->barriere[i].setCoordinate('B', 120 + (i * 130), 380);
    }

    this->colpoPlayer = Proiettile(0, 0, -1);
    this->colpoNemico = Proiettile(0, 0, 1);
    this->punteggio = 0;
    this->giocoInCorso = true;
    this->direzioneAlieni = 1;
}

bool GameEngine::isTerminato() {
    if (!this->player.isAttiva() || !giocoInCorso) {
        return true;
    }
    return false;
}

void GameEngine::eseguiCiclo() {
    if (!giocoInCorso) {
        return;
    }

    player.aggiorna();

    bool cambioDirezione = false;
    for (int i = 0; i < 55; i++) {
        if (alieni[i].isAttiva()) {
            if (alieni[i].getX() > arena.getLimiteDestro() - 40 || alieni[i].getX() < arena.getLimiteSinistro() + 10) {
                cambioDirezione = true;
                break;
            }
        }
    }

    if (cambioDirezione) {
        direzioneAlieni *= -1;
        for (int i = 0; i < 55; i++) {
            alieni[i].Spostati(0, 20);
            if (alieni[i].isAttiva() && alieni[i].getY() > 400) {
                giocoInCorso = false;
            }
        }
    }
    else {
        for (int i = 0; i < 55; i++) {
            alieni[i].Spostati(direzioneAlieni * 10, 0);
        }
    }

    if (colpoPlayer.isAttivo()) {
        colpoPlayer.aggiorna();
    }

    if (colpoNemico.isAttivo()) {
        colpoNemico.aggiorna();
    }

    gestisciCollisioni();
    Sleep(100);
}

void GameEngine::gestisciCollisioni() {
    // Player contro Nemici
    if (colpoPlayer.isAttivo()) {
        for (int i = 0; i < 55; i++) {
            if (alieni[i].isAttiva()) {
                if (colpoPlayer.getX() >= alieni[i].getX() && colpoPlayer.getX() <= alieni[i].getX() + 30 &&
                    colpoPlayer.getY() >= alieni[i].getY() && colpoPlayer.getY() <= alieni[i].getY() + 30) {

                    alieni[i].distruggi();
                    colpoPlayer.distruggi();
                    punteggio += 10;
                    break;
                }
            }
        }
    }

    // Collisioni Barriere
    for (int i = 0; i < 4; i++) {
        if (colpoPlayer.isAttivo()) {
            if (barriere[i].asteroideColpito((int)colpoPlayer.getX(), (int)colpoPlayer.getY())) {
                colpoPlayer.distruggi();
                barriere[i].setRotto();
            }
        }

        if (colpoNemico.isAttivo()) {
            if (barriere[i].asteroideColpito((int)colpoNemico.getX(), (int)colpoNemico.getY())) {
                colpoNemico.distruggi();
                barriere[i].setRotto();
            }
        }
    }

    // Nemico contro Player
    if (colpoNemico.isAttivo()) {
        int px, py;
        player.getPosizione(px, py);
        if (colpoNemico.getX() >= (px - 10) && colpoNemico.getX() <= (px + 10)) {
            if (colpoNemico.getY() >= py && colpoNemico.getY() <= py + 10) {
                player.riceviDanno(20);
                colpoNemico.distruggi();
            }
        }
    }
}

int GameEngine::getPunteggio() {
    return punteggio;
}