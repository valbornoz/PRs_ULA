#include <iostream>
#include "Dnode.h"
#include "conjuntosArreglos.h"
#include <assert.h>

using namespace std;				// tamaño de una matriz f X c  ó nXm

struct cuadros{
	int valor;
	int columna;
};

void asiggn(int f, int c, ConjuntosArreglos< Dnode<int> > matris){


}


int main(){

	ConjuntosArreglos< Dnode<int> > matris;
	Dnode<int> head, *auxNod, *retval, *aux, *aux2;
	int fila, columna, valor, tam;

	cout<<"introdusca fila y valor"<<endl;
	cin>>fila>>valor;

	if(valor)
	auxNod = new Dnode<int>(valor);

	head.insert(auxNod);

	matris.insertInPos(fila-1, head);
	head.reset();
	retval=matris.searchInPos(fila-1);

//	aux=retval->getNext()->getPrev();
	aux=retval->getNext();

//	cout<<"el valor insertado fue: "<<aux->getNext()->getData()<<"  aux: "<<aux<<"  aux->getPrev(): "<<aux->getPrev()<<endl;
	cout<<"el valor insertado fue: "<<aux->getData()<<endl;


	return 0;
}
