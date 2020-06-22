#include <iostream>
#include "sList.h"
#include "stacklist.h"

//using namespace std;

int main()
{

    Stack<int> prueba;
    Snode<int>* nodPrueba;
    int ent;

    // Test1

    try{
      prueba.pop();
    }
    catch (...){
        cout<<"ERROR  Fuera de rango"<<endl;
    }

    // Test 2
    do{
        cout << "Ingrese el entero a insertar en la pila, 0 para salir" << endl;
        cin>> ent;
        if (ent)
           try{
               prueba.push(ent);
           }
           catch (...){
            cout<<"ERROR  Fuera de rango"<<endl;
           }
    }while(ent!=0);


    while (!prueba.isEmpty()){

        ent= prueba.pop();
        cout<<" valor en la pila  =  "<<ent<<endl;

    }


    return 0;
}
