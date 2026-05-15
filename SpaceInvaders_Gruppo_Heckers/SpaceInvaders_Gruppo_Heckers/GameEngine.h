#pragma once

#include "Arena.h"
#include "Navicella.h"
#include "Nemico.h"
#include "Proiettile.h"
#include "Asteroidi.h"

class GameEngine {
private:

    Arena arena;                //definisce i confini del campo di gioco
    Navicella player;           //la navicella controllata dall'utente

    //gli array che servono per gestire la pluralità degli oggetti
    Nemico alieni[55];          //la formazione (55 nemici)
    Asteroidi barriere[4];      //le 4 zone di protezione
  
    //la gestione dei colpi
    Proiettile colpoPlayer;     //un solo colpo alla volta per il giocatore
    Proiettile colpiNemici[10]; //array per gestire più proiettili nemici a schermo
    
    //identificano lo stato del gioco
    int punteggio;
    bool giocoInCorso;
    int direzioneAlieni;        //1 per destra, -1 per sinistra5
    float velocitaAlieni;       //aumenta man mano che ne uccidi
    //metodi privati (incapsulamento)
    void muoviOggetti();        //sposta tutti gli elementi attivi
    void gestisciSparoNemici(); //logica per far sparare i nemici in modo casuale
    void controllaBordi();      //verifica se il blocco alieni deve scendere e invertire
    void verificaFineLivello(); //controlla se tutti i nemici sono morti

public:
    GameEngine();
    void inizializza();  //inizializza o Resetta una nuova partita o un nuovo livello

    //questo è il cuore del gioco e viene chiamato nel loop principale (main)
    
    void eseguiCiclo();           //coordina gli Input, i Movimento, le Collisioni e la Grafica
    void gestisciCollisioni();    //applica le regole della fisica
    void aggiornaGrafica();       //si occupa di inviare i dati alla parte di visualizzazione
    bool isTerminato();           //restituisce lo stato della partita
    int getPunteggio();           //un getter per il punteggio per visualizzarlo a fine partita
};