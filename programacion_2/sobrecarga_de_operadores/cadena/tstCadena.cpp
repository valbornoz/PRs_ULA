#include <iostream>
#include "cadena.h"

int main() {

   Cadena c1("Prueba");
   c1.mostrar();
   cout<<endl;
   c1.longitud();

   c1.agregar(" de concatenacion");
   c1.mostrar();
   cout<<endl;
   c1.longitud();

   c1+" para PR2";
   c1.mostrar();
   cout<<endl;
   c1.longitud();

   c1.upper();
   c1.mostrar();
   cout<<endl;

   c1.lower();
   c1.mostrar();
   cout<<endl;
   
   +c1;
   c1.mostrar();
   cout<<endl;

  // tablaASCII();
}
