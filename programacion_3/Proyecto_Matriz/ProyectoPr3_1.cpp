#include <iostream>
#include "Dnode.h"
#include "conjuntosArreglos.h"
#include <assert.h>

using namespace std;

struct cuadros{
	int valor;
	int columna;
};

void asiggn(int f, int c, ConjuntosArreglos< Dnode<int> > matris){


}


int main(){

	ConjuntosArreglos< Dnode<int> > matris;
	Dnode<int> head, *auxNod, *retval, *aux;
	int fila, columna, valor;

	cout<<"introdusca fila"<<endl;
	cin>>fila;
	cout<<"introdusca valor"<<endl;
	cin>>valor;
	cout<<"fila= "<<fila<<"  valor= "<<valor<<endl;

	if(valor)
	auxNod = new Dnode<int>(valor);
	cout<<"auxNod->getData(): "<<auxNod->getData()<<endl;
	cout<<"auxNod: "<<auxNod<<endl;
	aux=&head;

	head.insert(auxNod);
	aux=aux->getNext();
	cout<<"&head: "<<&head<<endl;
	cout<<"head.getData(): "<<head.getData()<<endl;
	cout<<"aux->getData(): "<<aux->getData()<<endl;
	cout<<"head.getNext()->getData()<<endl; "<<head.getNext()->getData()<<endl;
	cout<<"head->getNext()->getNext(): "<<head.getNext()->getNext()<<endl;
	cout<<"head.getNext(): "<<head.getNext()<<endl;

	matris.insertInPos(fila-1, head);
	retval=matris.searchInPos(fila-1);

	cout<<"retval "<<retval<<endl;
	cout<<"retval->getData() "<<retval->getData()<<endl;
	cout<<"retval->getNext() "<<retval->getNext()<<endl;
	cout<<"retval->getNext()->getNext() "<<retval->getNext()->getNext()<<endl;
	cout<<"(head)retval->getNext()->getPrev() "<<retval->getNext()->getPrev()<<endl;
	cout<<"(head)retval->getNext()->getPrev()->getData() "<<retval->getNext()->getPrev()->getData()<<endl;
	aux=retval->getNext();//aux=retval->getNext()->getPrev();

	cout<<"el valor insertado fue: aux->getData()= "<<aux->getData()<<"  aux: "<<aux<<"  aux->getPrev(): "<<aux->getPrev()<<"  "<<endl;
	cout<<endl<<endl;
	
	retval=matris.searchInPos(fila);
	cout<<"retval "<<retval<<endl;
	cout<<"retval->getData() "<<retval->getData()<<endl;
	cout<<"retval->getNext() "<<retval->getNext()<<endl;
	cout<<"retval->getNext()->getNext() "<<retval->getNext()->getNext()<<endl;
	cout<<"(head)retval->getNext()->getPrev() "<<retval->getNext()->getPrev()<<endl;
	cout<<"(head)retval->getNext()->getPrev()->getData() "<<retval->getNext()->getPrev()->getData()<<endl;

	aux=retval->getNext()->getPrev();	

	cout<<"el valor insertado fue(fila): "<<aux->getNext()->getData()<<"  aux: "<<aux<<"  aux->getPrev(): "<<aux->getPrev()<<endl;


	return 0;
}
