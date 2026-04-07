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

   
    Nemico nemico1 = Nemico(100, 100, 30, 30, "alieno", Color::Red);  //creo alieni
    Nemico nemico2 = Nemico(160, 100, 30, 30, "alieno", Color::Red);
    Nemico nemico3 = Nemico(220, 100, 30, 30, "alieno", Color::Red);

    int spostamentoX = 10; //di base l'ho messo cosi che poi viene aggiunto alle posizioni attuali da dove partono gli alieni in questo caso 100 o 160 o 220 + 10 poi se lo richiamo ancora +10 eccettera
    int spostamentoY = 20; //di base l'ho messo cosi che poi viene aggiunto alle posizioni attuali da dove partono gli alieni in questo caso 100 + 10 poi se lo richiamo ancora +10 eccettera

    while (true)
    {

        if (nemico1.getX() > limiteDestro || nemico1.getX() < limiteSinistro || nemico2.getX() > limiteDestro || nemico2.getX() < limiteSinistro || nemico3.getX() > limiteDestro || nemico3.getX() < limiteSinistro)  //controllo i bordi se gli alieni stanno uscendo o meno perche se stanno uscendo devo farli scendere di un pochino verso il basso
        {
            spostamentoX = spostamentoX * -1;  //chiesto a gemini per come fare l'inversione dell'andamento dell'alieno essendo che non sapevo come farlo

            nemico1.Spostati(0, spostamentoY);   // faccio scendere tutti di 20 essendo che si arriva al bordo
            nemico2.Spostati(0, spostamentoY);
            nemico3.Spostati(0, spostamentoY);
        }
        else
        {
            
            nemico1.Spostati(spostamentoX, 0);
            nemico2.Spostati(spostamentoX, 0);  // se ce spazio possono continuare a farli andare in laterale
            nemico3.Spostati(spostamentoX, 0);
        }
       
        nemico1.Spara();
        nemico2.Spara();
        nemico3.Spara();  // gestione sparo che poi devo implementare al proiettili di taha

        Sleep(200);
    }

    return 0;
}