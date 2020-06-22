#include <iostream>
#include "string.h"
#include "Empleado.h"

int main() { 
   persona *vector[2];
   vector[0] = new persona(10386328,"Mateo","Parra","Debajo del puente","04143286824");
   vector[1] = new empleado(2347868,"Manuel","Clemente","Con los padres","04168473674",800.0);

   for(int i=0;i<2;i++) {
      vector[i]->showAll();
   }                             
   delete vector[0];
   delete vector[1];  
}

