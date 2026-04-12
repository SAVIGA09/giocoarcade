#include "proiettili.h"

float Proiettile::getX() {
    return x;
}

float Proiettile::getY() {
    return y;
}

bool Proiettile::isAttivo() {
    return attivo;
}

int Proiettile::getDanno() {
    return danno;
}

Proiettile::Proiettile() {
    this->x = 0;
    this->y = 0;
    this->direzione = 0;
    this->velocita = 5.0;
    this->danno = 1;
    this->attivo = false;
}

Proiettile::Proiettile(float XdiPartenza, float YdiPartenza, int direzione) {
    this->x = XdiPartenza;
    this->y = YdiPartenza;
    this->direzione = direzione;
    this->velocita = 5.0;
    this->danno = 1;
    this->attivo = true;
}

void Proiettile::aggiorna() {
    // invece di uscire subito mettiamo tutto dentro l'if
    if (attivo == true) {

        // calcoliamo il movimento
        y = y + (velocita * direzione);

        // controlliamo se è uscito sopra o sotto
        if (y < 0) {
            attivo = false;
        }
        else {
            if (y > 600) {
                attivo = false;
            }
        }
    }
    // se attivo è false il programma semplicemente non entra nel blocco e non fa nulla
}

void Proiettile::distruggi() {
    this->attivo = false;
}