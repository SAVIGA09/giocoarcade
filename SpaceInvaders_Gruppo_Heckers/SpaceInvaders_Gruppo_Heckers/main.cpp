#include <string>
#include <windows.h>
#include <gdiplus.h> //sempre per trasformare i dati in qualcosa che si puo vedere a schermo 
#include "Nemico.h"

using namespace std;
using namespace Gdiplus;


int main() 
{
    int limiteDestro = 700; //modificabili in base al limite di "schermo" che voglio
    int limiteSinistro = 0;

   
    Nemico n1 = Nemico(100, 100, 30, 30, "alieno", Color::Red);  //creo alieni
    Nemico n2 = Nemico(160, 100, 30, 30, "alieno", Color::Red);
    Nemico n3 = Nemico(220, 100, 30, 30, "alieno", Color::Red);

    int spostamentoX = 10; //di base l'ho messo cosi che poi viene aggiunto alle posizioni attuali da dove partono gli alieni in questo caso 100 o 160 o 220 + 10 poi se lo richiamo ancora +10 eccettera
    int spostamentoY = 20; //di base l'ho messo cosi che poi viene aggiunto alle posizioni attuali da dove partono gli alieni in questo caso 100 + 10 poi se lo richiamo ancora +10 eccettera

    while (true)
    {

        if (n1.getX() > limiteDestro || n1.getX() < limiteSinistro || n2.getX() > limiteDestro || n2.getX() < limiteSinistro || n3.getX() > limiteDestro || n3.getX() < limiteSinistro)  //controllo i bordi se gli alieni stanno uscendo o meno perche se stanno uscendo devo farli scendere di un pochino verso il basso
        {
            spostamentoX = spostamentoX * -1;  //chiesto a gemini per come fare l'inversione dell'andamento dell'alieno essendo che non sapevo come farlo

            n1.Spostati(0, spostamentoY);   // faccio scendere tutti di 20 essendo che si arriva al bordo
            n2.Spostati(0, spostamentoY);   
            n3.Spostati(0, spostamentoY);
        }
        else
        {
            
            n1.Spostati(spostamentoX, 0);
            n2.Spostati(spostamentoX, 0);  // se ce spazio possono continuare a farli andare in laterale
            n3.Spostati(spostamentoX, 0);
        }
       
        n1.Spara();
        n2.Spara();
        n3.Spara();  // gestione sparo che poi devo implementare al proiettili di taha

        Sleep(200);
    }

    return 0;
}