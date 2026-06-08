#include "Arena.h"

Arena::Arena() {
    this->larghezza = 0;
    this->altezza = 0;
}
Arena::Arena(int larghezza, int altezza) {
    this->larghezza = larghezza;
    this->altezza = altezza;
}

int Arena::getLarghezza() {
    return this->larghezza;
}

int Arena::getAltezza() {
    return this->altezza;
}

int Arena::getLimiteSinistro() {
    return 50; 
}

int Arena::getLimiteDestro() {
    return this->larghezza - 50; // Dinamico in base alla larghezza
}

bool Arena::fuoriBordiOrizzontali(float x) {
    return (x < 0 || x > this->larghezza);
}

bool Arena::fuoriBordiVerticali(float y) {
    return (y < 0 || y > this->altezza);
}