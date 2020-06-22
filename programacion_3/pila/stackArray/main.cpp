#include <iostream>
#include "stack.h"

using namespace std;

int main()
{

    StackA<int> prueba;
    //Snode<int* nodPrueba;
    int ent;

    do{
        cout << "Ingrese el entero a insertar en la pila, 0 para salir" << endl;
        cin>> ent;
        if (ent) {
            prueba.push(ent);
        }
    }while(ent!=0);

    while (!prueba.isEmpty()){

        ent= prueba.pop();
        cout<<" valor en la pila  =  "<<ent<<endl;

    }


    return 0;
}
