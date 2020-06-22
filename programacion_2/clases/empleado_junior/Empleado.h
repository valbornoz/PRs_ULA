#include <iostream>
#include "string.h"
#include "Persona.h"

class empleado : public persona {
   private:
    float sueldo;
   public:
    empleado(int c, char *n, char * a, char * d, char *t, float s);  
    void showAll();
    void showNombre();
};
