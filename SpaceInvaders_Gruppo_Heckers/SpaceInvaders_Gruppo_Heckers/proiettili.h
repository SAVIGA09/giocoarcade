#pragma once
class Proiettile {
private:
    int x, y;          // Coordinate a schermo
    int velocita;
    int direzione;       // -1 per salire (Player), 1 per scendere (Alieni)
    bool attivo;         // Indica se il proiettile esiste ancora o va eliminato

public:
    // Costruttore: riceve posizione iniziale e chi ha sparato
    Proiettile();
    Proiettile(int XdiPartenza, int YdiPartenza, int direzione);

    // Muove il proiettile in base alla velocità e direzione
    void aggiorna();

    // Getter per controllare le collisioni nel file main.cpp
    int getX();
    int getY();
    bool isAttivo();

    // Disattiva il proiettile (es. se colpisce un alieno o esce dallo schermo)
    void distruggi();
};