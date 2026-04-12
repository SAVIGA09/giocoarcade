#include "proiettili.h"

float Proiettile::getX() {
    return this->x;
}

float Proiettile::getY() {
    return this->y;
}

bool Proiettile::isAttivo() {
    return this->attivo;
}

int Proiettile::getDanno() {
    return this->danno;
}

float Proiettile::getVelocita() {
    return this->velocita;
}

int Proiettile::getDirezione() {
    return this->direzione;
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
    if (this->attivo == true) {

        // calcoliamo il movimento
        this->y = this->y + (this->velocita * this->direzione);

        // controlliamo se è uscito sopra o sotto
        if (this->y < 0) {
            this->attivo = false;
        }
        else {
            if (this->y > 600) {
                this->attivo = false;
            }
        }
    }
    // se attivo è false il programma semplicemente non entra nel blocco e non fa nulla
}

void Proiettile::distruggi() {
    this->attivo = false;
}