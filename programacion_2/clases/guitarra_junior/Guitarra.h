#include <iostream>
#include "Instrumento.h"
#include "string.h"
using namespace std;

class Guitarra : public Instrumento {
   private:
      int nCuerdas;
      char material[30];
      char subtipo[20];
   public:
      Guitarra();
      Guitarra(char *n, char *t, char *i, int a, char *p, int b,char * m, char *s);  
      ~Guitarra();
      void lectura();    
      void showAll();
};
