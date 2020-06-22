#include <iostream>
#include "Guitarra.h"
using namespace std;

int main() { 

    Instrumento *vector[2];
   vector[0] = new Instrumento("Junior","Acustica", "Michael Guitarra", 1940, "Arabia Saudita");
   vector[1] = new Guitarra("Junior","Acustica", "Michael Guitarra", 1940, "Arabia Saudita", 6, "Ebano","Electrica");

   for(int i=0;i<2;i++) {
      vector[i]->showAll();
      cout << endl;
   }                             
   delete vector[0];
   delete vector[1];  
}

