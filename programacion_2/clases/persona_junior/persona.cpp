#include <iostream>
#include "string.h"
#include "Persona.h"
using namespace std;

int main() {

   persona p1("Pedro","Ortega",3276,"Chorros de Milla, Jaula 7","0426-7612576");

   char *nP;    
   nP = p1.getNombre();

   cout << "El nombre es: " << nP << endl;
   
   p1.mostrarDatos();












  /* persona p1;                               //("Pedro","Ortega");
   p1.setNombre((char *)"Tu");
   p1.mostrarDatos();
   
*/
/*   persona p1("Pedro","Ortega",3276,"Chorros de Milla, Jaula 7","0426-7612576");
   p1.mostrarDatos();
*/
/*
   persona * p1;
   p1=new persona();
   p1->mostrarDatos();

   char nP[20];   
   cout <<  "Introduzca su nombre: ";
   cin >> nP;

   p1->setNombre(nP);
   p1->mostrarDatos();
*/
/*
   int a = p1->getCedula();
   cout << "Nombre: " << p1->getNombre() << ", Cedula : " << a << endl;
   delete p1;
   p1->mostrarDatos();
   cout << "Nombre: " << nP << ", Cedula : " << a << endl;*/
  /*
   persona *p3;
   p3 = new persona("German","Ramirez",1,"Tu casa","5-riente");
   p3->mostrarDatos();*/
/*
   strcpy(p1.nombre, "Manuel");
   strcpy(p1.apellido, "Ortega");   
   p1.cedula = 3276;
   strcpy(p1.direccion, "Chorros de Milla, Jaula 7"); 
   strcpy(p1.telefono, "0426-7612576");
*/
  // p1.mostrarDatos();
  /* persona p1;
   p1.setNombre("Manuel");
   p1.setApellido("Ortega");
   p1.setTelefono("0426-7612576");  */    
   
 //  cout << p1.apellido << " " << p1.telefono << endl;
//   p1.mostrarDatos();
//   p3->mostrarDatos();
//   delete p3;
}
