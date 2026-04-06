#pragma once
#include <string>
#include <windows.h>
#include <gdiplus.h>//per trasformare i dati in qualcosa che si puo vedere a schermo 

using namespace std;
using namespace Gdiplus; 

class Nemico {
private:
    
    int x, y;
    int width, height;   // dati su cui si basa la creazione dell'alieno
    int phase;
    string type;
    Color color;
    bool isAlive;

public:
    
    Nemico();  // costruttori e metodi che ho dichiarato
    Nemico(int x, int y, int height, int width, string type, Color color);

    void GotHit();   // stato
    bool VivoOMorto(); 

    void Spostati(int dx, int dy); //qua gli do di quanti "pixel" mi devo spostare e poi in base a quanti gliene do li aggiungera o togliera a x e y
    void ChangePhase();    // azioni spiegate nel file che il programma deve fare e non chiedere all'utente
    void Spara();  //che poi mi servira a me per l'alieno combinandolo anche con i proiettili

    int getX();  // per valutare in che posizione sta l'alieno e anche per valutare se e' dentro il range dei bordi per il disegno
    int getY(); // per valutare in che posizione sta l'alieno e anche per valutare se e' dentro il range dei bordi per il disegno
};