#include <iostream>
#include "cadena.h"

int main() {
	char cad1[4];
	
	cadena * p1 = new cadena("hola");
	p1->mostrar();
	cout << endl;
	cadena p2("hola");
	  
	if(*p1 == "hola")
	  cout << "Son iguales" << endl;
   else
	  cout << "Son diferentes" << endl;   	  

   cout << "La cadena tiene " << p1->longitud() << " caracteres." << endl;
   
   cadena p3;
   p3.asignar("Elias\n");
   p3.mostrar();
   p3 = "Ingenieria";
   p3.mostrar();
   cout << endl;
   p3  + " es una facultad";
   p3.mostrar();
   cout << endl;
   
	delete p1;

}
