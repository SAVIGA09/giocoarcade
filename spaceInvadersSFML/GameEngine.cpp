#include "GameEngine.h"

// ============================================================
//  Costanti schermata
// ============================================================

const float RAGGIO_NEMICO = 20.0f;
const float RAGGIO_NAVICELLA = 50.0f;
const float PASSO_TASTO = 20.0f;   // pixel per pressione freccia
const float PASSO_ANGOLO = 5.0f;   // gradi per pressione rotazione o/a (orario/antiorario)
const int   RITARDO_MS = 100;      // ~60 fps

const int RIGA_TITOLO = 1;
const int COL_TITOLO = 4;

GameEngine::GameEngine(InterfacciaUtente& ui, wstring nomeGiocatore)
    : ui(ui)    // qui GameEngine usa un riferimento a InterfacciaUtente, 
                // quindi nel costruttore è necessario usare la lista di inizializzazione : ui(ui)
{
    this->nomeGiocatore = nomeGiocatore;

    // ── Creazione navicella ─────────────────────────────────────
    // Centrato al centro del campo, diretta a sinistra (180°),
    // velocità iniziale 0.
    float navicellaX = ui.getLarghezza() / 2.0f;
    float navicellaY = ui.getAltezza() - 50.0f;
	float navicellaVel = 0.0f;
	float navicellaAngolo  = 180.0f;

    this->navicella = OggettoMobile(navicellaX, navicellaY,
        navicellaVel, navicellaAngolo,
        RAGGIO_NAVICELLA, // spazio per collisioni a forma di cerchio
		"./images/navicella.png"); // immagine della navicella

    // ── Creazione Nemico ─────────────────────────────────────
    // Centrato al sinistra del campo, diretta in verticale verso destra (0°),
    // velocità iniziale 10.
    float nemicoX = ui.getLarghezza() / 1.5f;
    float nemicoY = ui.getAltezza() / 1.5f;
    float nemicoVel = 10.0f;
    float nemicoAngolo = 0.0f;

    this->nemico = OggettoMobile(nemicoX, nemicoY,
        nemicoVel, nemicoAngolo,
        RAGGIO_NEMICO, // spazio per collisioni a forma di cerchio
        "./images/nemico.png"); // immagine del nemico
}

void GameEngine::run() {
	// inizializza random per movimento nemico
	srand(static_cast<unsigned int>(time(nullptr)));

    bool finito = false;

	int larghezzaCampo = ui.getLarghezza();
	int altezzaCampo = ui.getAltezza();
    // ── Game loop ─────────────────────────────────────────────
    while (!finito)
    {
        int tasto = ui.leggiTasto();

        // ── Uscita ────────────────────────────────────────────
        if (tasto == TASTO_ESC)
            finito = true;

        // ── Spostamento con frecce (10 px) ────────────────────
        if (tasto == TASTO_SU)
            navicella.sposta(0.0f, -PASSO_TASTO, larghezzaCampo, altezzaCampo);
        if (tasto == TASTO_GIU)
            navicella.sposta(0.0f, PASSO_TASTO, larghezzaCampo, altezzaCampo);
        if (tasto == TASTO_SINISTRA)
            navicella.sposta(-PASSO_TASTO, 0.0f, larghezzaCampo, altezzaCampo);
        if (tasto == TASTO_DESTRA)
            navicella.sposta(PASSO_TASTO, 0.0f, larghezzaCampo, altezzaCampo);

        // ── Spostamento legato alla velocità ────────────────
        nemico.muoviZigZag(larghezzaCampo, altezzaCampo);

        // ── Rendering ─────────────────────────────────────────
        ui.pulisci();

        aggiungiSfondo();

        // Navicella
        navicella.aggiungiOggettoMobile(ui);
        // Nemico
        nemico.aggiungiOggettoMobile(ui);

        ui.disegna();

        ui.sleep(RITARDO_MS);
    }
}

void GameEngine::aggiungiSfondo() {
    // Bordo decorativo
    ui.aggiungiRettangoloVuoto(Punto(2, 2),
        ui.getLarghezza() - 4, ui.getAltezza() - 4,
        FG_ROSSO_I, 2.0f);

    // Titolo
    ui.aggiungiTestoAlCentro(RIGA_TITOLO, L"SPACE INVADERS");

    // info: nome, posizione e direzione
    wchar_t info[128];
    swprintf(info, 128,
        L"%ls  |  pos (%.0f, %.0f)  |  dir %.0f\u00B0  |  vel %.1f px/f",
        nomeGiocatore.c_str(),
        navicella.getX(), navicella.getY(),
        navicella.getAngolo(), navicella.getVelocita());
    ui.aggiungiTestoRigCol(Posizione(2, 2), info);
}
