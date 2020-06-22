#include <iostream>
#include "Guitarra.h"
using namespace std;

int main() {

   cout << endl << "Instrumento: " << endl;
   Instrumento I1;
   I1.lectura();
   I1.showAll();

   cout << endl << "Guitarra: " << endl;
   Guitarra g1;
   g1.lectura();
   g1.showAll();

   cout << endl << endl;
   int d;
   cout << "Cuántas Guitarras desea Registrar? ";
   cin >> d;
 
   Guitarra *g = new Guitarra[d];

   for(int i=0; i<d; i++) {
      cout << endl << "Introduzca los datos de las Guitarras: " << i+1 << ": " << endl;
      g[i].lectura();
   }

 for(int i=0; i<d; i++) {
      cout << endl << "La(s) Guitarras Registra(s) son: " << i+1 << ": " << endl;
      g[i].showAll();
   }

   delete []g;


}
