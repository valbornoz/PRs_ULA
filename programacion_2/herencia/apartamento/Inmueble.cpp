#include <iostream>
#include "string.h"
#include "Inmueble.h"

Inmueble::Inmueble() {
   strcpy(nombrePropietario, "");
   strcpy(apellidoPropietario, "");
   strcpy(cedula, "");
   strcpy(estado, "");
   strcpy(municipio, "");
   anyo = 0;
}
Inmueble::Inmueble(char * nP, char * aP, char *c, char *e, char *m, int a) {
   strcpy(nombrePropietario, nP);
   strcpy(apellidoPropietario, aP);
   strcpy(cedula, c);
   strcpy(estado, e);
   strcpy(municipio, m);
   anyo = a;
}

Inmueble::~Inmueble() {
}

void Inmueble::lectura() {
   cout << "Nombre del Propietario: ";
   cin >> nombrePropietario;

   cout << "Apellido del Propietario: ";
   cin >> apellidoPropietario;

   cout << "Cédula: ";
   cin >> cedula;

   cout << "Estado: ";
   cin >> estado;

   cout << "Municipio: ";
   cin >> municipio;

   cout << "Año: ";
   cin >> anyo;
}

void Inmueble::mostrar(){
   cout << endl << "Nombre del Propietario: " << nombrePropietario << endl;
   cout << "Apellido del Propietario: " << apellidoPropietario << endl;
   cout << "Cédula: " << cedula << endl;
   cout << "Estado: " << estado << endl;
   cout << "Municipio: " << municipio << endl;  
   cout << "Año: " << anyo << endl << endl;          
}

