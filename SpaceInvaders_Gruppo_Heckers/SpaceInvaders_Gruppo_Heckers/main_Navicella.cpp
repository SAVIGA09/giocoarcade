#include <iostream>
#include "Navicella.h"

using namespace std;

int main()
{
	Navicella n;

	n.muoviDestra();
	n.muoviDestra();

	int x, y;
	n.getPosizione(x, y);
	cout << "Posizione: " << x << ", " << y << endl;

	n.spara();
	cout << "Munizioni: " << n.getMunizioni() << endl;

	n.riceviDanno(50);
	cout << "Integrita: " << n.getIntegrita() << endl;

	return 0;
}