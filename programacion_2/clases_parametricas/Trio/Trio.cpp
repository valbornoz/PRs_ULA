#include <iostream>
#include "Trio.h"
using namespace std;



int main() {

    Trio <char> t1;
    t1.setPrimero('U');
    t1.setSegundo('L');
    t1.setTercero('A');
    t1.mostrarTrio();

	Trio<int> *t2 = new Trio<int>(3,4,7);
	t2->mostrarTrio();
	delete t2;
 	
}
