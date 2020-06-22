#include <iostream>
#include "string.h"


using namespace std;

string  invertir(string cad){

    string aux;

    cout<<"invirtiendo "<<cad<<endl;
    if (cad.length()==1) return cad;
    else{

        aux+=(invertir(cad.substr(1,cad.length()-1)));
        aux+=cad.substr(0,1);
        cout<<"invirtiendo 2"<<cad<<endl;
        return aux;
    }

}

int main()
{
    string cad,cadAux;
//   cout << "prueba recursiva" << endl;
    cout << "de la cadena a invertir   " << endl;
    cin>>cad;

    cadAux=invertir(cad);
    cout << "Cadena invertida  final   " <<cadAux<<endl;
    return 0;
}
