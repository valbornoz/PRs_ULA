#include <iostream>
#include "sList.h"
#include "stacklist.h"
#include <string.h>

using namespace std;

string invertir(string cad){

    if (cad.length()==1) return cad;
    return invertir(cad.substr(1,cad.length()-1)) + cad.substr(0,1);

}

int main()
{
    string cad;
    string aux="";

    cout<<"De la cadena a invertir  ";
    cin>>cad;

    aux=invertir(cad);
    cout<<"Cadena =  "<<aux<<endl;

    return 0;
}
