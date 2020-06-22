//#include <iostream>
#include "termino.h"
#include "polinomio.h"

using namespace std;

int main()
{

    Termino termino1(5,2);
    Termino termino2(3,1);
    Termino termino3(4,0);

    Polinomio  p1;
    Polinomio  p2;
    //   termino1=termino2;
    cout<<"COEFICIENTE:   "<<termino1.getCoeficiente()<<endl;
    cout<<"  EXPONENTE:   "<<termino1.getExponente()<<endl;
        //   termino1+(termino2);
    cout<<"COEFICIENTE:   "<<termino2.getCoeficiente()<<endl;
    cout<<"  EXPONENTE:   "<<termino2.getExponente()<<endl;
   /* termino1*(termino2);
    cout<<"COEFICIENTE:   "<<termino1.getCoeficiente()<<endl;
    cout<<"  EXPONENTE:   "<<termino1.getExponente()<<endl;
    */

    p1+(termino1);
    p1+(termino2);
    p1+(termino3);
    p1.escribe();

    p2+(termino1);
    p2+(termino2);
    p2.escribe();

    p1+p2;

    p1.escribe();

    return 0;
}
