#include <iostream>
#include "string.h"
using namespace std;

class Inmueble {
  protected:
   char nombrePropietario[20];
   char apellidoPropietario[20];
   char cedula[11];
   char estado[20];
   char municipio[30];
   int  anyo;
  public:
   Inmueble();
   Inmueble(char * nP, char * aP, char *c, char *e, char *m, int a);
   ~Inmueble();
  void lectura();
   void mostrar();
};


