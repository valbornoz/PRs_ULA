#include <iostream>
#include <stdlib.h>
#include "Dnode.h"
#include "Dlist.h"

using namespace std;

int main(){

    int i;
    long int j;
    Dlist<long int> cadena;
    Dnode<long int>* sal,*nod,*auxRota;


    srandom(1000);
    for (i=0;i<20;i++){
        nod=new Dnode<long int>(random()/10000);
        cout<<nod->getData()<<endl;
        cadena.insert(nod);
    }
    while (!cadena.hasOne()){
        j=random()/100000;
        auxRota=cadena.getFirst();
        while(j){
            auxRota=auxRota->getNext();
            if (auxRota->getNext()==cadena.getFirst())
                auxRota=cadena.getFirst();
            j--;
        }
        auxRota=auxRota->getPrev();
        auxRota=auxRota->removeNext();
        delete auxRota;
    }
    cout<<endl;
    cout<<endl;
    cout<<"Lleva el mensaje    "<<cadena.getFirst()->getData()<<endl; /**/
    return 0;
}



