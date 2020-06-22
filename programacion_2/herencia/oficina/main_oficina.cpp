#include <iostream>
#include "string.h"
#include "oficina.h"

int main() {
   Inmueble I1;
   I1.showAll();

  Inmueble *I2;
   I2 = new Inmueble("Distrito Capital","Libertador","Arias","Tabay, #34","V-03276573");
   I2->showAll();
   delete I2;


   char est[20];
   char mun[30];
   char par[30];
   char dir[100];
   char ced[11];

   Inmueble I3;
   cout << "Estado: "; cin >> est;
   cout << "Municipio: "; cin >> mun;
   cout << "Parroquia: "; cin >> par;
   cout << "Direccion: "; cin >> dir; 
   //cin.getline (dir,100);
  
   cout << "Cedula del propietario: "; cin >> ced;

   I3.setEstado(est);
   I3.setMunicipio(mun);
   I3.setParroquia(par);
   I3.setDireccion(dir);
   I3.setCedulaPropietario(ced);            
   I3.showAll();
   
   // QUIERO SABER EL MUNICIPIO DE I3
   char mun3[30];
   I3.getMunicipio(mun3);
   cout << endl << "El municipio es: " << mun3 << endl;
   
   // Declaración de una oficiona
   Oficina Ofic;
   Ofic.setAmoblada(1);
   Ofic.setCondicion(1);
   Ofic.setNroDespachos(6);
   Ofic.setPuestosEstacionamiento(4);
   Ofic.showAll();

}
