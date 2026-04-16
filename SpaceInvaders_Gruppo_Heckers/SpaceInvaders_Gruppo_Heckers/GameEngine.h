#pragma once
#include "Navicella.h"
#include "Nemico.h"
#include "proiettili.h"
#include "asteroidi.h"
#include "Arena.h"

class GameEngine {
private:
    Arena arena;
    Navicella player;
    Nemico alieno;
    Proiettile colpoPlayer;
    Proiettile colpoNemico;
    Asteroidi asteroide;

    int punteggio;
    bool giocoInCorso;

public:
    GameEngine();
    void inizializza();
    void eseguiCiclo(); // Il cuore del gioco
    void gestisciCollisioni();
    void aggiornaGrafica(); // Qui andrà poi la parte di visualizzazione
    bool isTerminato();
};