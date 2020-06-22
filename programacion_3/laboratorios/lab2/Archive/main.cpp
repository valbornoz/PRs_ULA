#include <iostream>
#include "sNode.h"
using namespace std;

int main(){

    sNode<int> head;
    sNode<int>* aux;
     sNode<int>* auxMove;
    int valor;

    auxMove=&head;
    cout<<"de el valor a ingresar : 0 para salir"<<endl;
    cin>>valor;
    while(valor){
       aux=new sNode<int>(valor);
       if (aux!=0) auxMove->insertNext(aux);
       cout<<"de el valor a ingresar : 0 para salir"<<endl;
       cin>>valor;
       auxMove=auxMove->getNext();
    }

    aux=head.getNext();
    while(aux!=&head){

	cout<<"valor es   "<<aux->getData()<<endl;
        aux=aux->getNext();
    }
//eliminar un valor

    cout<<endl;
    cout<<endl;
    aux=head.getNext();
    if (aux->getData()==8)
       head.removeNext();
    while(aux!=&head){
        if (aux->getNext()->getData()==8)
           aux->removeNext();
        else
          aux=aux->getNext();
    }


       aux=head.getNext();
    while(aux!=&head){

	cout<<"valor es   "<<aux->getData()<<endl;
        aux=aux->getNext();
    }

    return 0;
}
