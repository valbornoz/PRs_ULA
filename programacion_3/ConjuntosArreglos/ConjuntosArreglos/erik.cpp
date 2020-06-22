
#include <iostream>
#include <stdlib.h>
#include "conjuntosArreglos.h"
using namespace std;

struct repartir
{
char letras;
int cantidad;
};

int main()
{
ConjuntosArreglos<repartir> x;
ConjuntosArreglos<char> j1;
for(int i = 0; i < 26; i++)
{
repartir y;
y.letras = i+65;
y.cantidad = 5;
x.insert(y);
}
for(int i = 0; i < x.GetNumEle() ; i++)
{
cout<<x.searchInPos(i)->letras<<" "<<x.searchInPos(i)->cantidad<<endl;
}
for(int i =0 ;i< 7;i++)
{
int l = random()%x.GetNumEle();
char letra = x.searchInPos(l)->letras;
//~ x.searchInPos(i)->cantidad=x.searchInPos(i)->cantidad-1;
x.searchInPos(i)->cantidad--;
j1.insert(letra);
}
for(int i = 0;i<j1.GetNumEle();i++)
{
cout<<*j1.searchInPos(i)<<endl;
}
return 0;
}
