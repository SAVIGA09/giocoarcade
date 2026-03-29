#include "proiettili.h"



float Proiettile::getX()
{
    this->x;
}
float Proiettile::getY()
{
    this->y;
}
//serve per controllare se ha toccato l'alieno
bool Proiettile::isAttivo()
{
    return attivo;
}
// Implementazione del Costruttore

Proiettile::Proiettile(float XdiPartenza, float YdiPartenza, int direzione) {
    x = XdiPartenza;
    y = YdiPartenza;
    direzione = direzione;
    velocita = 5.0;    // Puoi regolare questo valore per la difficoltà
    attivo = true;
}

// Implementazione del movimento
void Proiettile::aggiorna() {
    if (!attivo) return;

    // Modifica la Y: se dir è -1 sale, se è 1 scende
    y += velocita * direzione;

    // Controllo bordi (esempio: schermo alto 600 pixel)
    if (y < 0 || y > 600) {
        attivo = false;
    }
}

// Implementazione della distruzione
void Proiettile::distruggi() {
    attivo = false;
}