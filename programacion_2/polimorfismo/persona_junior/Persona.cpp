#include <iostream>
#include "string.h"
#include "Persona.h"

persona::persona() {
   cedula = 0;
}

persona::persona(int c, char *n, char * a, char * d, char *t) {
   cedula = c;
   strcpy(nombre,n);
   strcpy(apellido,a);
   strcpy(direccion,d);
   strcpy(telefono,t);         
}

void persona::setCedula(int c) {
   if ((c>100000000)||(c<1))
      cout << "Numero de cedula invalido!" << endl;
   else 
      cedula = c;
}

void persona::setNombre(char *n) {
   strcpy(nombre,n);
}

void persona::getNombre(char *n) {
   strcpy(n,nombre);
}

void persona::showNombre() {
   cout << "Persona: " << nombre << endl;
}

void persona::showAll() {
   cout << "Nombre completo: " << nombre << " " << apellido << " cedula: " << cedula<<endl;
}

persona::~persona() {
}


