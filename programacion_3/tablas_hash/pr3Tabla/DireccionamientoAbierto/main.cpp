#include <iostream>
#include "diccionarioAbierto.h"
using namespace std;

int main()
{
    Diccionario<int>  prueba(50);
    int i;

    for(i=10;i<100;i=i+11){
        prueba.insert(i);
        cout<<"  insertando   " <<i<<endl;
    }

    cout<<endl;
    for(i=10;i<100;i=i+11){
        cout<<"  buscando   " <<prueba.search(i)<<endl;
    }

    cout<<endl;
    cout<<"  Eliminando   21"<<endl;
    prueba.remove(21);
    cout<<"  Eliminando   43"<<endl;
    prueba.remove(43);
    cout<<"  Eliminando   65"<<endl;
    prueba.remove(65);


    for(i=10;i<100;i=i+11){
        cout<<"  \nbuscando" << i<<"   Encontrando  " <<prueba.search(i)<<endl;
    }

    return 0;
}
