#include "cadena.h"

int main() {
	
        cadena p2;
	p2 = "Problema";
	p2.mesh("Complicado");
	p2.mostrar();
	cout << endl;

	p2 = "Hola";
	p2 *= "Casa";
	p2.mostrar();
	cout << endl;
        
}
