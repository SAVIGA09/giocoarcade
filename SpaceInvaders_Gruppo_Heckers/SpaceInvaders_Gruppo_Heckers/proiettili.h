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
    float getX();
    float getY();
    bool isAttivo();
    int getDanno();
    // Costruttori
    Proiettile();
    Proiettile(float XdiPartenza, float YdiPartenza, int direzione);
    Proiettile(float XdiPartenza, float YdiPartenza, int direzione, int danno);

    // Aggiorna posizione
    void aggiorna();

    // Getter
    float getX() const;
    float getY() const;
    float getVelocita() const;
    int getDirezione() const;
    int getDanno() const;
    bool isAttivo() const;

    // Azioni
    void distruggi();
};