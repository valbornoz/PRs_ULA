#include <iostream>
#include "diccionario.h"
#include "slot.h"

using namespace std;

int main()
{
    int aux;
    int* aux1;
    Diccionario<int>  prueba;
    cout << "probando" << endl;

    aux=150;

    while(aux>0){
        cout<<"Insertando  "<<aux<<endl;
        prueba.insert(aux);
        aux=aux-11;
    }
    
    cout<<"Buscando"<<endl;
    aux=150;
    aux1=prueba.search(aux);

    if (*aux1 == aux)
        cout << "probando aux1  150 =  " <<*aux1<< endl;

    aux=139;
    aux1=prueba.search(aux);

    if (*aux1 == aux)
        cout << "probando aux1 139 = " <<*aux1<< endl;
    else
        cout << "probando NO ENCONTRADO "<< endl;

    aux=128;
    aux1=prueba.search(aux);

    if (*aux1 == aux)
        cout << "probando aux1 128 =   " <<*aux1<< endl;
    
    aux=117;
//    prueba.remove(aux);
    aux1=prueba.search(aux);

    if (*aux1 != 117)
        cout << "Elimino  117 =   " <<aux<< endl;
    else
        cout << "NO Elimino "<< endl;

    return 0;

}
