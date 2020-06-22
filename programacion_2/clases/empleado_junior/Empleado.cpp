#include <iostream>
#include "string.h"
#include "Empleado.h"

empleado::empleado(int c, char *n, char * a, char * d, char *t, float s):persona(c,n,a,d,t) {
   sueldo = s;
};

void empleado::showAll() {
   cout << "Nombre completo: " << nombre << " " << apellido;
   cout << ", sueldo: " << sueldo << endl;
}

void empleado::showNombre() {
   cout << "Empleado: " << nombre << endl;
}
