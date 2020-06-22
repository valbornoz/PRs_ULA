#include <iostream>
#include "sNode.h"
#include "conjuntosArreglos.h"

using namespace std;

struct Eleconj{

	int valor;
	int contador;

bool operator==(const Eleconj& ele){
	return (this->valor==ele.valor);}

};

int main(){

	sNode<int> *nod, *aux, head;
	Eleconj elemento, auxiliar, *auxiliar2;
	ConjuntosArreglos<Eleconj> conjunto;
	int ele, i=0;

	cout<<"de el elemento a ingresar: 0 para salir"<<endl;
	cin>>ele;

	while(ele){
            nod=new sNode<int>(ele);
	      if(nod!=NULL) head.insertNext(nod);
		cout<<"de el elemento a ingresar: 0 para salir"<<endl;
		cin>>ele;
	}

	aux=head.getNext();
	while(aux!=&head){
	    cout<<"   "<<aux->getData()<<endl;
	    aux=aux->getNext();
      }

//////////////////////////////////////////////////////////////////
	aux=head.getNext();
	auxiliar.contador=0;
	while(aux!=&head){
	   auxiliar.valor=aux->getData();
	   auxiliar.contador=1;
         auxiliar2=conjunto.search(auxiliar);

	if(auxiliar2==NULL)
		conjunto.insert(auxiliar);
	else
		auxiliar2->contador=auxiliar2->contador+1;

	

		aux=aux->getNext();
	}



	return 0;

}
