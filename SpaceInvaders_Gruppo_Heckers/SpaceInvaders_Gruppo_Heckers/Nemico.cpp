#include "Nemico.h"

Nemico::Nemico() {  //inizializzo tutti gli oggetti che andro ad utilizzare 
    this->x = 0;
    this->y = 0;
    this->width = 35;  // Dimensione ipotetica
    this->height = 40; //dimensione ipotetica
    this->phase = 0;
    this->type = " ";
    this->color = Color::White;
    this->isAlive = true;
}

Nemico::Nemico(int x, int y, int height, int width, string type, Color color) {  //punto agli oggetti che ho inizializzato
    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;
    this->phase = 0;
    this->type = type;
    this->color = color;
    this->isAlive = true;
}

void Nemico::GotHit() {

    this->isAlive = false; // Se l'alieno viene colpito lo stato isAlive diventa falso
}

bool Nemico::Unalive() {

    if (this->isAlive == false) {  //se isAlive e' falso vuol dire che l'alieno e' stato eliminato e quindi unalive e' vero
        return true;
    }
    else {    //senno l'alieno e' ancora vivo
        return false;
    }
}
void Nemico::ShiftSx(int pixel) {

    this->x -= pixel;   // spostamento verso sinistra e quindi diminuisco la coordinata x di quanti pixel mi ha detto l'utente
}

void Nemico::ShiftDx(int pixel) {

    this->x += pixel; // spostamento verso destra e quindi aggiungo alla coordinata x quanti pixel mi ha detto l'utente
}

void Nemico::ShiftUp(int pixel) {

    this->y -= pixel;  // spostamento verso l'alto e quindi diminuisco la coordinata y di quanti pixel mi ha detto l'utente
}

void Nemico::ShiftDown(int pixel) {

    this->y += pixel;    // spostamento verso il basso e quindi aggiungo alla coordinata y quanti pixel mi ha detto l'utente
}

void Nemico::Shift() {
    // esempio di automatismo tipo l'alieno cambia fase ogni volta che si muove tipo destra-sinistra la fase cambia
    //pero da pensare in altre maniere anche senno si sfruttano gli shift ma sono tante piu righe da scrivere
    this->ChangePhase();
}

void Nemico::ChangePhase() {

    if (this->phase == 0) {     // alternanza tra fase 0 e fase 1 per l'animazione come per esempio gambe aperte o gambe chiuse
        this->phase = 1;
    }
    else {
        this->phase = 0;
    }
}

void Nemico::Shoot() {

    if (this->isAlive) {   // logica per lo sparo e sarebbe da mettere un oggetto proiettile per permettere all'alieno di sparare alla navicella
        // e qui serve la logica per lo sparo che e' solo grafica
    }
}