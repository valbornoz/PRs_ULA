#include "cadena.h"

int main() {
	cadena p1;
	p1 = "hola";
        p1.longitud();
        p1.mostrar();
	p1.invertir();
	p1.mostrar();
	cout << endl;
	
	p1 = "cosa";
        p1.mostrar();
	!p1;
	p1.mostrar();
	cout << endl;
}
