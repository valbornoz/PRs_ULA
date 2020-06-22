#ifndef MATRISE_H
#define MATRISE_H

#include <iostream>
#include "Dnode.h"
#include "conjuntosArreglos.h"
#include <assert.h>

struct cuadros{
	int valor;	// T
	int columna;
};

class MatrisE {

	private:

	ConjuntosArreglos< Dnode<cuadros> > *matris;
	int size_f, size_c;
	int numEle;

	public:

	MatrisE():size_f(100), size_c(100), numEle(0){
		matris = new ConjuntosArreglos< Dnode<cuadros> >[size_f];
	}

	MatrisE(int tam_f, int tam_c): numEle(0){
		assert(tam_f>0 and tam_c>0);

		size_f=tam_f;
		size_c=tam_c;
		matris = new ConjuntosArreglos< Dnode<cuadros> >[size_f];
	}

	MatrisE(MatrisE &other){
		size_f=other.size_f;
		size_c=other.size_c;
		numEle=other.numEle;
		matris = new ConjuntosArreglos< Dnode<cuadros> >[size_f];
		for(int i=0; i<size_f; i++){
			matris[i]=other.matris[i];
		}
	}

	~MatrisE(){
		delete [] matris;
	}

	int getsize_f(){
		return size_f;
	}

	int getsize_c(){
		return size_c;
	}

	int getNumEle(){
		return numEle;
	}

	int search(int fila, int columna) const {
		if(fila<0 or columna<0 or fila>size_f or columna>size_c){
			std::cout<<"ERROR: posicion no valida"<<std::endl;
			return 0;
		}

		Dnode<cuadros>* retval, *aux;

		retval=matris->searchInPos(fila);
		if(retval->getNext()->getPrev()->getData().valor == 0) return 0; //la fila esta vacia


		aux=retval->getNext();

		while(aux != retval->getNext()->getPrev()){
			if(aux->getData().columna==columna) 		//encontro la columna
				return aux->getData().valor;		//retorna el valor
			else
				aux=aux->getNext();
		}

		return 0;				//el cuadro vacio(nodo no existe)

	}

	void asiggn(int fila, int columna, int/*T*/ valor){
		if(fila<0 or columna<0 or fila>size_f or columna>size_c){
			std::cout<<"ERROR: posicion no valida"<<std::endl;
			return;
		}
			
		Dnode<cuadros>* auxNod, *retval, *aux;
		cuadros Vr;

		Vr.valor=valor;
		Vr.columna=columna;

		retval=matris->searchInPos(fila);

		auxNod = new Dnode<cuadros>(Vr);

		if(retval->getNext()->getPrev()->getData().valor == 0){	//no hay fila
			Dnode<cuadros> head;

			head.insert(auxNod);
			matris->insertInPos(fila, head);
			numEle++;
			return;
		}//if

		aux=retval->getNext();

		while(aux != retval->getNext()->getPrev()){
			if(aux->getData().columna==columna){	//sobrescribir
				aux-> getData().valor = valor;
				numEle++;
				return;
			}else
			if(aux->getData().columna > columna){
				aux->getPrev();
				aux->insert(auxNod);
				numEle++;
				return;
			}else
				aux=aux->getNext();
		}//while

		aux=retval->getPrev();
		aux->insert(auxNod);
		numEle++;
		return;
	}

	void imprimirMatris(){
		for(int i=0; i<this->getsize_f(); i++){
			std::cout<<std::endl;
			for(int j=0; j<this->getsize_c(); j++){
				std::cout<<this->search(i,j)<<" ";
			}
		}
		std::cout<<std::endl;
	}

	MatrisE& operator=(const MatrisE& other){

		if(size_f>=other.size_f and size_c>=other.size_c){
			numEle=other.numEle;
			for(int i=0; i<size_f; i++)
				matris[i]=other.matris[i];
		}
            return *this;
        }

	MatrisE operator+(const MatrisE& m2){
		assert(size_f==m2.size_f and size_c==m2.size_c);

		MatrisE m3(size_f, size_c);
		int valor;

		for(int i=0; i<this->getsize_f(); i++){
			for(int j=0; j<this->getsize_c(); j++){

				valor=this->search(i,j) + m2.search(i,j);
				m3.asiggn(i,j,valor);
			}
		}

		return m3;
	}


};

#endif
