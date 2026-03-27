#include <string>
#include <windows.h>
#include <gdiplus.h> //sempre per trasformare i dati in qualcosa che si puo vedere a schermo
#include "Nemico.h"
using namespace std;
using namespace Gdiplus;

int main() {
	Nemico n1 = Nemico(100, 100, 20, 20, "alieno", Color::Red);
	Nemico n2 = Nemico(100, 200, 20, 20, "alieno", Color::Blue); //dichiarazione ipotetica degli alieni nemici

	// inizia lo shift automatico degli alieni 
	//il countspara parte da 0 perche non si sta iniziando a sparare e poi si aggiorna nel while
	int countSpara = 0;

	while (true) {

		n1.SpostatiESpara();
		n2.SpostatiESpara();

		Sleep(100);//si rallenta il ciclo 

		//si continua lo shift delle posizione degli alieni in concomitanza al fatto che sparano colpi

		countSpara++;

	}
	//serve sfruttare il gothit e poi il successivo unalive per valutare se l'alieno viene eliminato o meno 

	return 0;
}