#include <iostream>
#include "string.h"
using namespace std;

class Instrumento {
   protected:
      char nombre[20];
      char tipo[20];
      char inventor[40];
      int anyo;
      char pais[20];
   public:
      Instrumento();
      Instrumento(char *n, char *t, char *i, int a, char *p);
      ~Instrumento();
      void lectura();
      virtual void showAll();
};
