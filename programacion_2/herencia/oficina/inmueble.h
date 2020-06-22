#include <iostream>
#include "string.h"
using namespace std;

class Inmueble {
  protected:
   char estado[20];
   char municipio[30];
   char parroquia[30];
   char direccion[100];
   char cedulaPropietario[11];
  public:
   Inmueble();
   Inmueble(char * e, char * m, char * p, char *d, char *cP);
   
   void getEstado(char * e);
   void setEstado(char * e);
   
   void getMunicipio(char * m);
   void setMunicipio(char * m);
   
   void getParroquia(char * p);
   void setParroquia(char * p);   
   
   void getDireccion(char * d);
   void setDireccion(char * d);   
   
   void getCedulaPropietario(char *cP);
   void setCedulaPropietario(char *cP);  
   
   void showAll(); 
};


