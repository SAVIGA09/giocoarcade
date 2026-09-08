#include "Arena.h"

Arena::Arena(int larghezzaPX, int altezzaPX)
{
	float centroX = larghezzaPX / 2.0f, centroY = altezzaPX / 2.0f;

	int altezzaNavicella = altezzaPX / 20,
		larghezzaNavicella = larghezzaPX / 20;

	int altezzaNemico = altezzaPX / 20,
		larghezzaNemico = larghezzaPX / 20;

	int altezzaProiettile = altezzaPX / 25,
		larghezzaProiettile = larghezzaPX / 40;

	float xNavicella = centroX - (larghezzaNavicella / 2.0f), yNavicella = (centroY + (centroY / 2.0f));

	float centroX_Nav = xNavicella + (larghezzaNavicella / 2.0f);

	float xProiettile = centroX_Nav - (larghezzaProiettile / 2.0f), yProiettile = yNavicella - altezzaProiettile;

	this->navicella = Navicella(xNavicella, yNavicella, larghezzaNavicella, altezzaNavicella, 20);
	this->proiettile = Proiettile(xProiettile, yProiettile, larghezzaProiettile, altezzaProiettile, false);

	this->setLarghezza(larghezzaPX);
	this->setAltezza(altezzaPX);

	//nemici
	float spaziaturaX = larghezzaNemico * 1.3f;
	float spaziaturaY = altezzaNemico * 1.2f;	

	float larghezzaTotaleGriglia = 7 * spaziaturaX;
	float startX = centroX - (larghezzaTotaleGriglia / 2.0f);
	float startY = centroY / 4.0f;

	//ciclo alieni

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 10; c++)
		{
			float posX = startX + (c * spaziaturaX);
			float posY = startY + (r * spaziaturaY);

			TIPO_ALIENO tipo;

			if (r == 2)
			{
				tipo = graf1;
			}
			if (r == 1)
			{
				tipo = graf2;
			}
			if (r == 0)
			{
				tipo = graf3;
			}
			this->alieni[r][c] = Nemico(posX, posY, larghezzaNemico, altezzaNemico, tipo, destra);
		}
	}
}

Navicella Arena::getNavicella()
{
	return this->navicella;
}
Nemico Arena::getNemico(int riga, int col)
{
	return this->alieni[riga][col];
}
Proiettile Arena::getProiettile()
{
	return this->proiettile;
}

void Arena::setLarghezza(int larghezzaPX)
{
	this->larghezza = larghezzaPX;
}
void Arena::setAltezza(int altezzaPX)
{
	this->altezza = altezzaPX;
}
void Arena::modificaArena(int larghezzaPX, int altezzaPX)
{
	this->setLarghezza(larghezzaPX);
	this->setAltezza(altezzaPX);
}
int Arena::getAltezza()
{
	return this->altezza;
}
int Arena::getLarghezza()
{
	return this->larghezza;
}

void Arena::spostaNavicella(MOVIMENTO direzione, int nPX)
{
	switch (direzione)
	{
	case DESTRA:
		if ((this->navicella.getPosX() + (this->navicella.getHitbox().width/1.5)) < this->larghezza)
		{
			this->navicella.muoviDestra(nPX);
		}
		break;
	case SINISTRA:
		if (this->navicella.getPosX() > 0)
		{
			this->navicella.muoviSinistra(nPX);
		}
		break;
	default:
		break;
	}
}

void Arena::spostaNemico()
{
	bool cambiaDir = false;

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 10; c++)
		{
			if (!this->alieni[r][c].getStato())
			{
				continue;
			}

			int spostamento = 0;

			DIREZIONE dir = this->alieni[r][c].getDirezione();

			switch (dir)
			{
			case destra:
				spostamento = 3;
				break;
			case sinistra:
				spostamento = -3;
				break;
			default:
				break;
			}

			int prossX = this->alieni[r][c].getPosX() + spostamento;

			if ((prossX + this->alieni[r][c].getLarghezza() >= this->larghezza && this->alieni[r][c].getDirezione() == destra) || (prossX <= 0 && this->alieni[r][c].getDirezione() == sinistra))
			{
				cambiaDir = true;
				break;
			}
		}
		if (cambiaDir)
		{
			break;
		}
	}
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 10; c++)
		{
			if (!this->alieni[r][c].getStato())
			{
				continue;
			}
			if (cambiaDir)
			{
				this->alieni[r][c].invertiDirezioneEscendi();
			}
			else
			{
				this->alieni[r][c].muovi();
			}
		}
	}
}

void Arena::spostaProiettile(int nPX)
{
	if (this->proiettile.getY() > 0)
	{
		this->proiettile.muoviSu(nPX);
	}
}

void Arena::spara()
{
	if (!this->proiettile.getStato())
	{
		float centroXNavicella = this->navicella.getPosX() + (this->navicella.getLarghezza() / 2.0f);
		float xSpawProiettile = centroXNavicella - (this->proiettile.getLarghezza() / 2.0f);

		this->proiettile.muoviX(xSpawProiettile);
		this->proiettile.resetY(this->navicella.getPosY() - this->proiettile.getAltezza());
		this->proiettile.changeStato();
	}
}

bool Arena::controllaNemicoNavicella(Nemico& nemico)
{
	if (!nemico.getStato())
	{
		return false;
	}
	if (nemico.getHitbox().intersects(this->navicella.getHitbox()))
	{
		return true;
	}
	return false;
}

bool Arena::controllaProiettileNemico(Nemico& nemico)
{
	if (!nemico.getStato() || !this->proiettile.getStato())
	{
		return false;
	}

	if (this->proiettile.getHitbox().intersects(nemico.getHitbox()))
	{
		this->proiettile.colpisci(nemico);
		return true;
	}
	return false;
}

int Arena::getPunteggio()
{
	return this->punteggio;
}

void Arena::aggiornaArena()
{
	this->spostaNemico();

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 10; c++)
		{
			if (this->controllaNemicoNavicella(this->alieni[r][c]))
			{
				this->navicella.riceviDanno(35);
				this->alieni[r][c].colpito();
			}
		}
	}

	if (this->proiettile.getStato())
	{
		this->proiettile.muoviSu(10);

		bool colpito = false;

		for (int r = 0; r < 3 && !colpito; r++)
		{
			for (int c = 0; c < 10; c++)
			{
				if (this->controllaProiettileNemico(this->alieni[r][c]))
				{
					TIPO_ALIENO tipo = this->alieni[r][c].getTipo();

					switch (tipo)
					{
					case graf1:
						this->punteggio += 20;
						break;
					case graf2:
						this->punteggio += 35;
						break;
					case graf3:
						this->punteggio += 50;
						break;
					default:
						break;
					}

					colpito = true;
					break;
				}
			}
		}
		if (!colpito && this->proiettile.getY() <= 0)
		{
			this->proiettile.changeStato();
		}
	}
}

bool Arena::controllaVittoria()
{
	if (this->punteggio >= 1015)
	{
		return true;
	}
	return false;
}