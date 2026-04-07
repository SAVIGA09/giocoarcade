#include "Navicella.h"

Navicella::Navicella()
{
    this->posX = 0;
    this->posY = 0;
    this->integrita = 100;
    this->munizioni = 10;

    this->attiva = true;
    this->velocita = 1;
    this->direzione = 0;
    this->cooldownSparo = 0;

    this->tempoPotenziamento = 0;
    this->tipoPotenziamento = 0;
}

Navicella::Navicella(int posX, int posY, int integrita, int munizioni)
{
    this->posX = posX;
    this->posY = posY;
    this->integrita = integrita;
    this->munizioni = munizioni;

    this->attiva = true;
    this->velocita = 1;
    this->direzione = 0;
    this->cooldownSparo = 0;

    this->tempoPotenziamento = 0;
    this->tipoPotenziamento = 0;
}

void Navicella::muoviSinistra()
{
    this->posX -= velocita;
}

void Navicella::muoviDestra()
{
    this->posX += velocita;
}

void Navicella::getPosizione(int& x, int& y)
{
    x = this->posX;
    y = this->posY;
}

void Navicella::limitaMovimento(int larghezza)
{
    if (this->posX < 0)
    {
        this->posX = 0;
    }
    else if (this->posX > larghezza)
    {
        this->posX = larghezza;
    }
}

// stato Navicella
void Navicella::riceviDanno(int danno)
{
    this->integrita -= danno;

    if (this->integrita <= 0)
    {
        distruggi();
    }
}

void Navicella::distruggi()
{
    this->attiva = false;
}

bool Navicella::isAttiva()
{
    return this->attiva;
}

void Navicella::setIntegrita(int integrita)
{
    if (integrita < 0)
    {
        this->integrita = 0;
    }
    else if(integrita > 100)
    {
        this->integrita = 100;
    }
    else
    {
        this->integrita = integrita;
    }
}

int Navicella::getIntegrita()
{
    return this->integrita;
}

// munizioni
bool Navicella::puoSparare()
{
    if (this->munizioni > 0 && this->cooldownSparo == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Navicella::spara()
{
    if (puoSparare())
    {
        this->munizioni--;
        this->cooldownSparo = 3;
    }
}

void Navicella::ricarica(int quantita)
{
    this->munizioni += quantita;
}

void Navicella::setMunizioni(int munizioni)
{
    this->munizioni = munizioni;
}

int Navicella::getMunizioni()
{
    return this->munizioni;
}

// potenziamenti
void Navicella::attivaPotenziamento(int tipo, int durata)
{
    this->tipoPotenziamento = tipo;
    this->tempoPotenziamento = durata;
}

// aggiornamento
void Navicella::aggiorna()
{
    if (this->cooldownSparo > 0)
    {
        this->cooldownSparo--;
    }
    if (this->tempoPotenziamento > 0)
    {
        this->tempoPotenziamento--;
    }
    else
    {
        this->tipoPotenziamento = 0;
    }
}