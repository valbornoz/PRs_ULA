#include <iostream>
#include "string.h"
#include "inmueble.h"

class Oficina : public Inmueble {
  private:
   int amoblada;
   int condicion;
   int nroDespachos;
   int puestosEstacionamiento;
  public:
   Oficina();
   Oficina(char *e, char *m, char *p, char *d, char *cP, int am, int co, 
           int nd, int pe);
   int getAmoblada();
   void setAmoblada(int a);   
   int getCondicion();
   void setCondicion(int c);   
   int getNroDespachos();
   void setNroDespachos(int nd);   
   int getPuestosEstacionamiento();
   void setPuestosEstacionamiento(int pe); 
   void showAll();  
};
