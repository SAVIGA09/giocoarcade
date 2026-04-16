#pragma once

class Arena {
private:
    int larghezza;
    int altezza;

public:
    Arena();
    Arena(int larghezza, int altezza);
    int getLarghezza();
    int getAltezza();
    int getLimiteSinistro();
    int getLimiteDestro();   
    bool fuoriBordiOrizzontali(float x);
    bool fuoriBordiVerticali(float y);
};