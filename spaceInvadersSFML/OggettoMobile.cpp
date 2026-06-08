#include "OggettoMobile.h"
#include <cmath>   // cos, sin, atan2, sqrt


// ============================================================
//  Costruttori
// ============================================================

OggettoMobile::OggettoMobile()
{
    this->centroX = 0.0f;
    this->centroY = 0.0f;
    this->spostX = 0.0f;
    this->spostY = 0.0f;
    this->velocita = 0.0f;
    this->raggio = 16.0f;
    this->imgFile = "";
}

OggettoMobile::OggettoMobile(float startX, float startY,
    float vel, float angoloDeg,
    float raggio,
    string imgFile)
{
    this->centroX = startX;
    this->centroY = startY;
    this->velocita = vel;
    this->raggio = raggio;
    this->spostX = 0.0f;
    this->spostY = 0.0f;
    this->imgFile = imgFile;

    impostaAngolo(angoloDeg);
}


// ============================================================
//  Getter
// ============================================================

float OggettoMobile::getX()        { return this->centroX; }
float OggettoMobile::getY()        { return this->centroY; }
float OggettoMobile::getVelocita() { return this->velocita; }
float OggettoMobile::getRaggio()   { return this->raggio; }

float OggettoMobile::getAngolo()
{
    // atan2 restituisce radianti nell'intervallo (-π, π]
    float rad = std::atan2(this->spostY, this->spostX);
    float deg = rad * 180.0f / static_cast<float>(PIGRECO);
    if (deg < 0.0f)
        deg += 360.0f;
    return deg;
}


// ============================================================
//  Setter
// ============================================================

bool OggettoMobile::controllaPosizione(int largCampo, int altCampo)
{
    // il centro della pallina deve essere a distanza 
    // di almeno raggio dai bordi del campo
    if (this->centroX - this->raggio < 0.0f)
        return false;
    if (this->centroX + this->raggio > largCampo)
        return false;

    if (this->centroY - this->raggio < 0.0f)
        return false;
    if (this->centroY + this->raggio > altCampo)
        return false;
    return true;
}

void OggettoMobile::impostaPosizione(float nuovaX, float nuovaY,
    int largCampo, int altCampo)
{
    int oldCentroX = this->centroX;
    int oldCentroY = this->centroY;
    this->centroX = nuovaX;
    this->centroY = nuovaY;
    if (!controllaPosizione(largCampo, altCampo)) {
        this->centroX = oldCentroX;
        this->centroY = oldCentroY;
    }
}

void OggettoMobile::sposta(float dx, float dy, int largCampo, int altCampo)
{
    int oldCentroX = this->centroX;
    int oldCentroY = this->centroY;
    this->centroX += dx;
    this->centroY += dy;
    if (!controllaPosizione(largCampo, altCampo)) {
        this->centroX = oldCentroX;
        this->centroY = oldCentroY;
    }
}

void OggettoMobile::impostaVelocita(float vel)
{
    if (vel < 0.0f) vel = 0.0f;
    float angolo = std::atan2(this->spostY, this->spostX);
    this->velocita = vel;
    this->spostX = std::cos(angolo) * this->velocita;
    this->spostY = std::sin(angolo) * this->velocita;
}

void OggettoMobile::impostaAngolo(float angoloDeg)
{
    float rad = angoloDeg * static_cast<float>(PIGRECO) / 180.0f;
    this->spostX = std::cos(rad) * this->velocita;
    this->spostY = std::sin(rad) * this->velocita;
}

void OggettoMobile::accelera(float delta)
{
    float angolo = std::atan2(this->spostY, this->spostX);
    this->velocita += delta;
    if (this->velocita < 0.0f) this->velocita = 0.0f;
    this->spostX = std::cos(angolo) * this->velocita;
    this->spostY = std::sin(angolo) * this->velocita;
}


// ============================================================
//  Rimbalzo e torna in alto
// ============================================================

void OggettoMobile::rimbalzaX()
{
    this->spostX = -this->spostX;
}

void OggettoMobile::rimbalzaY()
{
    this->spostY = -this->spostY;
}


// ============================================================
//  Movimento
// ============================================================

void OggettoMobile::muoviConRimbalzoBordi(int larghezza, int altezza)
{
    float larg = static_cast<float>(larghezza);
    float alt = static_cast<float>(altezza);

    this->centroX += this->spostX;
    this->centroY += this->spostY;

    // ── Rimbalzo bordo sinistro / destro ──────────────────────
    if (this->centroX - this->raggio < 0.0f)
    {
        this->centroX = this->raggio;
        rimbalzaX();
    }
    if (this->centroX + this->raggio > larg)
    {
        this->centroX = larg - this->raggio;
        rimbalzaX();
    }

    // ── Rimbalzo bordo superiore / inferiore ──────────────────
    if (this->centroY - this->raggio < 0.0f)
    {
        this->centroY = this->raggio;
        rimbalzaY();
    }
    if (this->centroY + this->raggio > alt)
    {
        this->centroY = alt - this->raggio;
        rimbalzaY();
    }
}

void OggettoMobile::muoviZigZag(int largCampo, int altCampo)
{
    this->centroX += this->spostX;
    this->centroY += this->spostY;

    // ── Rimbalzo bordo sinistro / destro ──────────────────────
    if (this->centroX - this->raggio < 0.0f)
    {
        this->centroX = this->raggio + 10;
        this->centroY += this->raggio + 10;
        rimbalzaX();
    }
    if (this->centroX + this->raggio > largCampo)
    {
        this->centroX = largCampo - this->raggio - 10;
        this->centroY += this->raggio + 10;
        rimbalzaX();
    }
    if (this->centroY + this->raggio > altCampo)
    {
        tornaInAlto(largCampo);
    }
}

void OggettoMobile::tornaInAlto(int largCampo) {
    this->centroX = 30 + ((rand() % largCampo) - 60);
    this->centroY = 30;
}


// ============================================================
//  Disegno
// ============================================================


void OggettoMobile::aggiungiOggettoMobile(InterfacciaUtente& ui)
{
    if (!this->imgFile.empty())
    {
        // Scala il PNG affinché il diametro coincida con raggio*2
        float scala = 0;

        sf::Texture texture;
        if (texture.loadFromFile(this->imgFile))
        {
            sf::Vector2u dimTex = texture.getSize();
            float diametro = this->raggio * 2.0f;
            if (dimTex.x > 0)
                scala = diametro / static_cast<float>(dimTex.x);
            else
                scala = 1.0f;
        }
        // nemico e navicella morizzano posizione del centro
        int pX = this->centroX;
        int pY = this->centroY;
        ui.aggiungiImmagine(Punto(pX, pY), this->imgFile, scala, scala);
    }
}