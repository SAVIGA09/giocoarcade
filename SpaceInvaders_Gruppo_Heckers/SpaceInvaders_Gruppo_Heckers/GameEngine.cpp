#include "GameEngine.h"
#include <iostream>
#include <windows.h>

using namespace std;


// costruttore chiama semplicemente inizializza()
GameEngine::GameEngine() {
    inizializza();
}

//resetta tutto per una nuova partita o livello
void GameEngine::inizializza() {
    this->arena = Arena(640, 480);
    this->player = Navicella(320, 440, 100, 10);

    // Crea la formazione 5x11 di alieni
    int indice = 0;
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 11; c++) {
            this->alieni[indice] = Nemico(100 + (c * 40), 50 + (r * 30), 30, 30, "Alieno", 10);
            indice++;
        }
    }

    // Posiziona le 4 barriere
    for (int i = 0; i < 4; i++) {
        this->barriere[i].setCoordinate('B', 120 + (i * 130), 380);
    }

    // Colpo del player: spara verso l'alto (direzione -1)
    this->colpoPlayer = Proiettile(0, 0, -1);

    // Tutti e 10 i proiettili nemici: sparano verso il basso (direzione +1)
    for (int i = 0; i < 10; i++) {
        this->colpiNemici[i] = Proiettile(0, 0, 1);
    }

    this->punteggio = 0;
    this->giocoInCorso = true;
    this->direzioneAlieni = 1;
    this->velocitaAlieni = 10.0f; // velocita iniziale degli alieni
}

//restituisce true se la partita e' finita
bool GameEngine::isTerminato() {
    if (!this->player.isAttiva() || !giocoInCorso) {
        return true;
    }
    return false;
}

//è il cuore del gioco, chiamato nel loop del main
// Coordina: input, movimenti, collisioni, grafica
void GameEngine::eseguiCiclo() {
    if (!giocoInCorso) {
        return;
    }

    // Aggiorna lo stato del player (input, posizione, ecc.)
    player.aggiorna();

    // Sposta tutti gli oggetti attivi (alieni e proiettili)
    muoviOggetti();

    // Fa sparare i nemici in modo casuale
    gestisciSparoNemici();

    // Controlla se il blocco alieni ha raggiunto i bordi
    controllaBordi();

    // Applica le regole di collisione
    gestisciCollisioni();

    // Controlla se tutti i nemici sono stati eliminati
    verificaFineLivello();

    // Aggiorna la visualizzazione
    aggiornaGrafica();

    Sleep(100);
}


//sposta alieni e proiettili attivi
void GameEngine::muoviOggetti() {
    // Muovi tutti gli alieni orizzontalmente
    for (int i = 0; i < 55; i++) {
        if (alieni[i].isAttiva()) {
            alieni[i].Spostati((int)(direzioneAlieni * velocitaAlieni), 0);
        }
    }

    // Muovi il proiettile del player se e' attivo
    if (colpoPlayer.isAttivo()) {
        colpoPlayer.aggiorna();
    }

    // Muovi tutti i proiettili nemici attivi
    for (int i = 0; i < 10; i++) {
        if (colpiNemici[i].isAttivo()) {
            colpiNemici[i].aggiorna();
        }
    }
}

// GESTISCISPARONEMICI: un alieno casuale spara
// rand() e' gia' disponibile tramite <windows.h>
void GameEngine::gestisciSparoNemici() {
    // Cerca un slot libero nell'array dei proiettili nemici
    int slotLibero = -1;
    for (int i = 0; i < 10; i++) {
        if (!colpiNemici[i].isAttivo()) {
            slotLibero = i;
            break;
        }
    }

    // Se tutti i 10 proiettili sono gia' in volo, non si spara
    if (slotLibero == -1) return;

    // Con probabilita' ~10% ogni ciclo, un alieno casuale spara
    if (rand() % 10 == 0) {
        int tentativo = rand() % 55;
        if (alieni[tentativo].isAttiva()) {
            colpiNemici[slotLibero] = Proiettile(
                alieni[tentativo].getX() + 15, // centro dell'alieno
                alieni[tentativo].getY() + 30, // appena sotto l'alieno
                1                              // direzione verso il basso
            );
        }
    }
}

// inverte direzione e fa scendere gli alieni
void GameEngine::controllaBordi() {
    bool cambioDirezione = false;

    for (int i = 0; i < 55; i++) {
        if (alieni[i].isAttiva()) {
            if (alieni[i].getX() > arena.getLimiteDestro() - 40 ||
                alieni[i].getX() < arena.getLimiteSinistro() + 10) {
                cambioDirezione = true;
                break;
            }
        }
    }

    if (cambioDirezione) {
        direzioneAlieni *= -1; // inverti la direzione orizzontale

        for (int i = 0; i < 55; i++) {
            alieni[i].Spostati(0, 20); // fai scendere tutti di 20 pixel

            // Se un alieno ha raggiunto il player, il gioco e' perso
            if (alieni[i].isAttiva() && alieni[i].getY() > 400) {
                giocoInCorso = false;
            }
        }

        // Aumenta la velocita' ad ogni discesa (difficolta' crescente)
        velocitaAlieni += 1.0f;
    }
}


// verificaFineLivello: controlla se tutti i nemici sono stati eliminati
void GameEngine::verificaFineLivello() {
    int alieniVivi = 0;
    for (int i = 0; i < 55; i++) {
        if (alieni[i].isAttiva()) {
            alieniVivi++;
        }
    }

    // Nessun alieno rimasto = livello completato
    if (alieniVivi == 0) {
        giocoInCorso = false;
    }
}


//questa funzione rileva e risolve tutti gli scontri
void GameEngine::gestisciCollisioni() {
    // 1) Colpo del player contro alieni
    if (colpoPlayer.isAttivo()) {
        for (int i = 0; i < 55; i++) {
            if (alieni[i].isAttiva()) {
                if (colpoPlayer.getX() >= alieni[i].getX() &&
                    colpoPlayer.getX() <= alieni[i].getX() + 30 &&
                    colpoPlayer.getY() >= alieni[i].getY() &&
                    colpoPlayer.getY() <= alieni[i].getY() + 30) {

                    alieni[i].distruggi();
                    colpoPlayer.distruggi();
                    punteggio += 10;
                    break;
                }
            }
        }
    }

    // 2) Colpi contro le barriere
    for (int i = 0; i < 4; i++) {
        if (colpoPlayer.isAttivo()) {
            if (barriere[i].asteroideColpito((int)colpoPlayer.getX(), (int)colpoPlayer.getY())) {
                colpoPlayer.distruggi();
                barriere[i].setRotto();
            }
        }

        for (int j = 0; j < 10; j++) {
            if (colpiNemici[j].isAttivo()) {
                if (barriere[i].asteroideColpito((int)colpiNemici[j].getX(), (int)colpiNemici[j].getY())) {
                    colpiNemici[j].distruggi();
                    barriere[i].setRotto();
                }
            }
        }
    }

    // 3) Colpi dei nemici contro il player
    int px, py;
    player.getPosizione(px, py);

    for (int j = 0; j < 10; j++) {
        if (colpiNemici[j].isAttivo()) {
            if (colpiNemici[j].getX() >= (px - 10) &&
                colpiNemici[j].getX() <= (px + 10) &&
                colpiNemici[j].getY() >= py &&
                colpiNemici[j].getY() <= py + 10) {

                player.riceviDanno(20);
                colpiNemici[j].distruggi();
            }
        }
    }
}

//qua si invia i dati aggiornati alla visualizzazione
void GameEngine::aggiornaGrafica() {
    system("cls"); // pulisce lo schermo

    cout << "Punteggio: " << punteggio << endl;

    int alieniVivi = 0;
    for (int i = 0; i < 55; i++) {
        if (alieni[i].isAttiva()) alieniVivi++;
    }
    cout << "Alieni rimasti: " << alieniVivi << endl;

    // Qui andrebbero le chiamate alla vera libreria grafica
}


//è un getter per il punteggio finale
int GameEngine::getPunteggio() {
    return punteggio;
}