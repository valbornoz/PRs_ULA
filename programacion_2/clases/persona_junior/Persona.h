#include <iostream>
#include "string.h"
using namespace std;

class persona {
  private:
   char nombre[20];
   char apellido[20];
   int cedula;
   char direccion[100];
   char telefono[13];

  public:
   persona();
   persona(char * n, char * a, int c, char * d, char * t);
      void setNombre(char * n) {
      strcpy(nombre,n);
   }
   void setApellido(char * a) {
      strcpy(apellido,a);
   }
   void setTelefono(char * t) {
      strcpy(telefono,t);
   }
   void mostrarDatos();
   int getCedula();
   
   void getNombre(char * n) {
      strcpy(n,nombre);
   }
   char * getNombre() {
      return nombre;
   }   

};


