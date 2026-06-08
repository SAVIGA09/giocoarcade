#pragma once
#include "InterfacciaUtente.h"

// ============================================================
//  OGGETTO MOBILE — versione pixel
//
//  Posizione e velocità sono in pixel float.
//  Il rimbalzo usa i limiti in pixel del Campo.
//  Il disegno chiama campo.disegnaSprite() oppure
//  campo.disegnaCerchio() (nessun accesso a celle).
// ============================================================

class OggettoMobile {
public:

    // ── Costruttori ──────────────────────────────────────────

    // Default: fermo in (0,0), raggio 16, simbolo 'O'.
    OggettoMobile();

    // Completo.
    // startX, startY : centro in pixel
    // vel            : modulo velocità (pixel/frame)
    // angoloDeg      : direzione (0°=destra, 90°=giù, 180°=sinistra, 270°=su)
    // raggio         : usato per rimbalzo, disegno e collisioni
    OggettoMobile(float centroX, float centroY,
        float vel, float angoloDeg,
        float raggio,
        string imgFile = "");

    // ── Getter ────────────────────────────────────────────────

    float getX();
    float getY();
    float getVelocita();
    float getRaggio();

    // Angolo corrente in gradi (ricavato da spostX/spostY).
    float getAngolo();

    // ── Setter ────────────────────────────────────────────────

    // Sposta il centro a (nuovaX, nuovaY) — riportato all'interno dei ai bordi.
    void impostaPosizione(float nuovaX, float nuovaY, int largCampo, int altCampo);

    // Trasla la posizione di (dx, dy) — riportato all'interno dei bordi.
    void sposta(float dx, float dy, int largCampo, int altCampo);

    // Imposta il modulo della velocità mantenendo la direzione.
    void impostaVelocita(float vel);

    // Imposta la direzione in gradi ricalcolando spostX/spostY.
    void impostaAngolo(float angoloDeg);

    // Aumenta la velocità di 'delta' pixel/frame.
    void accelera(float delta);

    // ── Movimento ─────────────────────────────────────────────

    // Aggiunge spostX/spostY alla posizione e gestisce il rimbalzo
    // sui quattro bordi del campo (usa il raggio per uscire parzialmente).
    void muoviConRimbalzoBordi(int largCampo, int altezza);
    void muoviZigZag(int largCampo, int altezza);
    void tornaInAlto(int largCampo);

    // ── Disegno ───────────────────────────────────────────────

    // Chiama campo.disegnaSprite() o campo.disegnaCerchio()
    // alla posizione corrente.
    // Il chiamante è responsabile di chiamare campo.pulisci()
    // prima e campo.presenta() dopo — nessuna cancellazione
    // della posizione precedente è necessaria.
    void aggiungiOggettoMobile(InterfacciaUtente& ui);

private:

    float centroX, centroY;          // centro in pixel
    float spostX, spostY;
    float velocita;
    float raggio;

    // versione grafica con nome file di immagine
    string imgFile;

    void rimbalzaX();
    void rimbalzaY();

    // controllo della posizione entro i bordi del campo.
    bool controllaPosizione(int largCampo, int altCampo);
};