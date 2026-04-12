#pragma once

class Proiettile {
private:
    float x;
    float y;
    float velocita;
    int direzione; // -1 per salire (Player), 1 per scendere (Alieni)
    int danno;
    bool attivo;

public:
    // Costruttori
    Proiettile();
    Proiettile(float XdiPartenza, float YdiPartenza, int direzione);

    // metodi principali
    void aggiorna();
    void distruggi();

    // Getter 
    float getX();
    float getY();
    float getVelocita();
    int getDirezione();
    int getDanno();
    bool isAttivo();
};