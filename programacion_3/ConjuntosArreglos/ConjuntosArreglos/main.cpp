#include <iostream>
#include "conjuntosArreglos.h"


using namespace std;

int main()
{
    ConjuntosArreglos<int> pruebaConjunto;
    ConjuntosArreglos<int> particion1;
    ConjuntosArreglos<int> particion2;
    int ele,i;


    cout << "Prueba de Conjuntos Arreglos" << endl;
    ele = 3;

    for(i=0; i<20; i++){
        cout<<"elemento es "<<ele<<endl;
        pruebaConjunto.insert(ele);
        ele=(i+2)*2+1;
    }

    for(i=0;i<pruebaConjunto.GetNumEle(); i++){
        cout<<"elemento en posicion i = "<<i<<" Es:  "<<*pruebaConjunto.searchInPos(i)<<endl;
    }

    cout<<endl;
    i=9;
    cout<<"elemento a buscar 9   Es:  "<<*pruebaConjunto.search(9)<<endl;

    cout<<endl;
    i=8;
    cout<<"elemento a buscar 8   Es:  "<<endl;
    if (pruebaConjunto.search(8)==NULL)
        cout<<"Valor 8 NO EXISTE"<<endl;
    else
        cout<<"Valor 8 ERROR EN BUSCAR"<<endl;

    cout<<endl;
    i=9;
    cout<<"elemento a eliminar es 9   Es:  "<<*pruebaConjunto.remove(9)<<endl;

    cout<<endl;
    for(i=0; i<pruebaConjunto.GetNumEle(); i++){
        cout<<"elemento en posicion i = "<<i<<" Es:  "<<*pruebaConjunto.searchInPos(i)<<endl;
    }

    cout<<endl;
    i=8;
    cout<<"elemento a eliminar es 8   Es:  "<<endl;
    if (pruebaConjunto.search(8)==NULL)
        cout<<"Valor 8 NO ELIMINADO"<<endl;
    else
        cout<<"Valor 8 ERROR EN ELIMINAR"<<endl;

    cout<<endl;
    for(i=0; i<pruebaConjunto.GetNumEle(); i++){
        cout<<"elemento en posicion i = "<<i<<" Es:  "<<*pruebaConjunto.searchInPos(i)<<endl;
    }

    pruebaConjunto.split(9,particion1,particion2);
    cout<<endl;
    cout<<"PARTCION1"<<endl;
    cout<<endl;
    for(i=0; i<particion1.GetNumEle(); i++){
        cout<<"elemento en posicion i = "<<i<<" Es:  "<<*particion1.searchInPos(i)<<endl;
    }

    cout<<endl;
    cout<<"PARTCION2"<<endl;
    cout<<endl;
    for(i=0; i<particion2.GetNumEle(); i++){
        cout<<"elemento en posicion i = "<<i<<" Es:  "<<*particion2.searchInPos(i)<<endl;
    }

    cout<<endl;
    cout<<"MERGE "<<endl;
    cout<<endl;
    particion1.merge(particion2);
    for(i=0; i<particion1.GetNumEle(); i++){
        cout<<"elemento en posicion i = "<<i<<" Es:  "<<*particion1.searchInPos(i)<<endl;
    }
    return 0;
}
