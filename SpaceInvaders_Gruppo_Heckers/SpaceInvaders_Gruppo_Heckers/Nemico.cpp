#include "Nemico.h"
using namespace std;

Nemico::Nemico() 
{

    this->x = 0;  //inizializzazione oggetti 
    this->y = 0;
    this->width = 35;
    this->height = 40;
    this->phase = 0;
    this->type = " ";
    this->color = Color::White;   
    this->isAlive = true;
}

Nemico::Nemico(int x, int y, int height, int width, string type, Color color) 
{

    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;
    this->phase = 0;  //punto agli oggetti che utilizzero che ho inizializzato prima
    this->type = type;
    this->color = color;
    this->isAlive = true;
}

int Nemico::getX() 
{

    return this->x;   //per posizione alieno
}

int Nemico::getY()
{

    return this->y;  //sempre per la posizione dell'alieno
}

void Nemico::GotHit() 
{

    this->isAlive = false; // controllo se viene colpito se viene colpito muore
}

bool Nemico::VivoOMorto() 
{

    if (this->isAlive == false) 
    {

        return true; // è morto
    }

    else 
    {
        return false; // è ancora vivo
    }
}

void Nemico::ChangePhase() 
{  //per la grafica delle braccia alzate o no

    if (this->phase == 0) 
    {

        this->phase = 1;
    }
    else 
    {
        this->phase = 0;
    }
}

void Nemico::Spostati(int dx, int dy)
{
   
    if (this->isAlive == true) //controllo se e' morto perche se lo e' non deve spostarlo piu se invece e' vivo lo deve spostare
    { 

        this->x += dx;   // aggiungo lo spostamento che gli dico alle coordinate attuali
        this->y += dy;

        this->ChangePhase();  // richiamo il cambio fase per la animazione grafica
    }
}

void Nemico::Spara() 
{

    if (this->isAlive == true) 
    {

        // Qui andrà la logica di taha per il proiettile e il successivo sparo
    }
}