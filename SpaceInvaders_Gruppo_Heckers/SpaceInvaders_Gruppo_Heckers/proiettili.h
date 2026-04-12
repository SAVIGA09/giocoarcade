#pragma once

class Proiettile {
private:
    float x;
    float y;
    float velocita;
    int direzione;
    int danno;          
    bool attivo;

public:
    float getX();
    float getY();
    bool isAttivo();
    int getDanno();
    Proiettile();
    Proiettile(float XdiPartenza, float YdiPartenza, int direzione);
    Proiettile(int XdiPartenza, int YdiPartenza, int direzione);

    // Muove il proiettile in base alla velocità e direzione
    void aggiorna();
    float getX() const;
    float getY() const;
    bool isAttivo() const;

    void distruggi();
};