#include <iostream>
#include "string.h"
using namespace std;

class Prenda {
   protected:
      char genero;
      int anio;
      float precio;
      char color[30];
   public:
      Prenda();
      Prenda(char g, int a, float p, char *c);
      ~Prenda();
      void lectura();
      void desplegar();
      char getGenero();
      void getColor(char *c);
};




