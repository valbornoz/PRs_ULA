#include "cadena.h"

int main() {
	
    char Cadena[100];
    
    cadena p2;
	p2 = "Problema";
	p2.mesh("Complicado");
	p2.mostrar();
	cout << endl;

	p2 = "Hola";
	p2 *= "Casa";
	p2.mostrar();
	cout << endl;

        cadena p1;
	p1 = "hola";
	p1.invertir();
	p1.mostrar();
	cout << endl;
	
	p1 = "cosa";
	!p1;
	p1.mostrar();
	cout << endl;
	
		cadena p3;
	
	p3="aeiou";
        p3.mostrar();
	cout << endl;
	p3.Consonante();
	
	p3="casa";
        p3.mostrar();
        cout << endl;
	
	p3.Consonante();
        
	p3="Carro";
        p3.mostrar();
        cout << endl;
	++p3;
	
	
}
