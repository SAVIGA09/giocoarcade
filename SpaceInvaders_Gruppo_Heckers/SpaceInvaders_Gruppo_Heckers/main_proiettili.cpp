/*#include <iostream>
#include "proiettili.h"

using namespace std;

int main() {
    Proiettile p(10.0, 10.0, -1);

    cout << "--- TEST PROIETTILE ---" << endl;

    for (int i = 0; i < 10; i++) {
        p.aggiorna();

        if (p.isAttivo() == true) {
            cout << "Turno " << i + 1 << " - Posizione Y: " << p.getY() << endl;
        } else {
            cout << "Proiettile distrutto o fuori schermo!" << endl;
            break; 
        }
    }

    return 0;
}
*/