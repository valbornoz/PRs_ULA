#include <iostream>
#include "string.h"
#include "Camisa.h"
using namespace std;

void CamisaMACE(Camisa *v, int n) {
   char genero;
   char color[30];
   char manga;
   char dibE;

   cout << endl << "Listado de Camisas de mujer, azules, manga corta y con dibujo en la espalda: " << endl;

   for(int i=0; i<n; i++) {
      genero = v[i].getGenero();
      v[i].getColor(color);
      manga = v[i].getManga();
      dibE = v[i].getDibE();

      if((genero=='M')&&(strcmp(color,"Azul")==0)&&(manga=='C')&&(dibE='S')) {
         v[i].desplegar();
         cout << endl;
      }
   }
}


int main() {

   cout << endl << "Prenda: " << endl;
   Prenda p1;
   p1.lectura();
   p1.desplegar();

   cout << endl << "Camisa: " << endl;
   Camisa c1;
   c1.lectura();
   c1.desplegar();

   cout << endl << endl;
   int n;
   cout << "Cuántas tipos de camisa desea registrar? ";
   cin >> n;
 
   Camisa *v = new Camisa[n];

   for(int i=0; i<n; i++) {
      cout << endl << "Introduzca los datos del tipo de camisa " << i+1 << ": " << endl;
      v[i].lectura();
   }

   CamisaMACE(v,n);

   delete []v;
}


