#include <iostream>
#include "string.h"
using namespace std;

class persona {
  protected:
   int cedula;   
   char nombre[20];
   char apellido[20];   
   char direccion[100];
   char telefono[12];
  public:
   persona();
   persona(int c, char *n, char * a, char * d, char *t);
   void setCedula(int c); 
   void setNombre(char *n);
   void getNombre(char *n);
   virtual void showNombre();   
   virtual void showAll();
   ~persona();   
};
