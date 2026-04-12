#include <iostream>
#include <windows.h>

#include "Navicella.h"
#include "Nemico.h"    // Includo i file del gruppo
#include "proiettili.h"
#include "asteroidi.h"

using namespace std;

int main() {

    Navicella player(260, 125, 100, 10); // proserpio   
    Nemico alieno(110, 100, 30, 30, "Alieno", 0); // io
    Proiettile colpo(0, 0, -1);               // proiettile del giocatore che parte disattivato
    Proiettile colpoNemico(0, 0, 1);          // proiettile dell'alieno
    Asteroidi barriera;                       // apuzz

    barriera.setCoordinate('B', 350, 430);  //imposto la barriera di apuzzo con le coordinate

    int spostamentoX = 15;   //spostamento della x che sara di 15 ogni volta
    int limiteDestro = 600;   // limite fino a cui ci si puo spostare
    int limiteSinistro = 50;  // limite fino a cui ci si puo spostare

    cout << "PROTOTIPO GRUPPO HECKERS" << endl;


    for (int i = 0; i < 30; i++) {  // 20 cicli giusto per vedere se va o no
        cout << "ciclo " << i << "" << endl;

        player.aggiorna(); // per far scendere il cooldown

        if (alieno.getX() > limiteDestro || alieno.getX() < limiteSinistro) {  //logica degli alieni

            spostamentoX = spostamentoX * -1; // Inversione rimbalzo chiesto a gemini
            cout << "Il Nemico ha toccato il bordo, scende di 20 " << endl;
            alieno.Spostati(0, 20); //spostamento dell'alieno
        }
        else {
            alieno.Spostati(spostamentoX, 0); //se invece non ha ancora toccato il bordo non scende e continua ad aggiornarsi di 15
        }
        cout << "Posizione Alieno: X = " << alieno.getX() << " Y = " << alieno.getY() << endl; //visualizzo posizione alieno


        if (i == 5 && player.puoSparare()) {  //logica per lo sparo solo una volta per testare
            player.spara();
            colpo = Proiettile(350, 450, -1);   // proiettile alle coordinate del player
            cout << "NAVICELLA GIOCATORE: sparo avvenuto con successo! munizioni: " << player.getMunizioni() << endl; //checko munizioni
        }

        if (colpo.isAttivo()) {    // aggiorno proiettile e colpo che arriva alla barriera

            colpo.aggiorna();
            cout << "PROIETTILE : In volo a Y = " << colpo.getY() << endl; //checko position colpo

            
            if (barriera.asteroideColpito((int)colpo.getX(), (int)colpo.getY())) {   // controllo se il proiettile di taha tocca l'asteroide di apuzz
                // ho messo il cast perche senno non prende le coordinate giuste e non mi va la collisione

                cout << "ASTEROIDE COLPITO" << endl;   // ho messo il cast perche senno non prende le coordinate giuste e non mi va la collisione
                cout << "COLLISIONE: l'asteroide e' stato colpito!" << endl;
                colpo.distruggi(); // il proiettile sparisce
                barriera.setRotto(); // l'asteroide applica la sua logica di rompimento 
            }
        }

        if (i == 9) { //sparo proiettile da parte del nemico al ciclo 10

            colpoNemico = Proiettile(alieno.getX(), alieno.getY(), 1); // li metto in concomitanza da dove sta l'alieno
            cout << "Colpo del Nemico: Attacco alla navicella, Proiettile sparato! " << endl;
        }
        if (colpoNemico.isAttivo()) {

            colpoNemico.aggiorna();
            cout << "PROIETTILE NEMICO: In volo a Y = " << colpoNemico.getY() << endl;  //checko position colpo dell'alieno

            int px, py;
            player.getPosizione(px, py); // prendo posizione della navicella per vedere se il colpo dell'alieno prende il giocatore

            
             if (colpoNemico.getX() >= (px - 5) && colpoNemico.getX() <= (px + 5) && colpoNemico.getY() >= py && colpoNemico.getY() <= py + 5) {  // se le coordinate x e y coincidono il colpo ha beccato la navicella
                 // ho dovuto qua mettere un margine di errore perche senno con il == era difficilissimo beccare la situazione in cui sono uguali 
                cout << "Giocatore Beccato" << endl;
                cout << "NAVICELLA COLPITA DAL NEMICO" << endl;
                player.riceviDanno(20); //diminuisco la vita del player 
                colpoNemico.distruggi();  // e giustamente distruggo il colpo del nemico che e' arrivato contro il giocatore

                cout << "Integrita' della Navicella del giocatore: " << player.getIntegrita() << endl;  //checko vita del giocatore
            }
        }
        Sleep(300); // pausa per vedere i cout e rallentare il ciclo
    }
    cout << "Fine del test" << endl;
    return 0;
}
//ex parte mia
/*#include <string>
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
*/