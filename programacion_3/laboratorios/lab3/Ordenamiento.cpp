#include <iostream>
#include "Dnode.h"
#include <stdlib.h>
using namespace std;

void merge(Dnode<int> &A, Dnode<int>* li, Dnode<int>* ls, Dnode<int>* med){

	Dnode<int> B;
	Dnode<int>* I, *J, *K, *auxNod, *auxMove; 
 
	auxMove=&B;
	for (I=li; I!=med->getNext(); I=I->getNext()){
		auxNod=new Dnode<int>(I->getData());
		auxMove->insert(auxNod);
		auxMove=auxMove->getNext();
	}

	for (I=ls; I!=med; I=I->getPrev()){
		auxNod=new Dnode<int>(I->getData());
		auxMove->insert(auxNod);
		auxMove=auxMove->getNext();
	}

    for(I=B.getNext(), J=B.getPrev(), K=li ; K!=ls->getNext(); K=K->getNext()){
        if (I->getData() < J->getData()){
            K->getData() = I->getData();
            I=I->getNext();
        }
        else{
            K->getData() = J->getData();
            J=J->getPrev();
        }
     }
    return;
};

void mergeSort(Dnode<int> &head, Dnode<int>* li, Dnode<int>* ls){

	if (li==ls) return;

	Dnode<int>* medio, *auxi, *auxS;
	auxi=li;
	auxS=ls;

	while(auxi != auxS){
		if((auxi->getPrev()==auxS) or (auxS->getNext()==auxi)){ medio=auxS; break;}
		auxi=auxi->getNext();
		auxS=auxS->getPrev();
	}

	if(medio != auxS)
	medio=auxS;

	mergeSort(head, li, medio);
	mergeSort(head, medio->getNext(), ls);
	merge(head, li, ls, medio);

	return;
};

void SelectSort(Dnode<int>& head){
	Dnode<int>* min, *auxI, *auxJ, *aux;
	int temp,i;

	for(auxI=head.getNext(); auxI != head.getPrev(); auxI=auxI->getNext()){
		min=auxI;

		for(auxJ=auxI->getNext(); auxJ != &head; auxJ=auxJ->getNext()){
			if(auxJ->getData() < min->getData())
				min=auxJ;
		}

		if(min != auxI){
		auxI->swap(min);
		auxI = min;

		}
	}
}

void insertSort(Dnode<int>& head){
	Dnode<int>* aux;
	int key;

	for(Dnode<int>* auxI=head.getNext()->getNext(); auxI!=&head; auxI=auxI->getNext()){
		key=auxI->getData();
		Dnode<int>* auxJ;

		for(auxJ=auxI->getPrev(); (auxJ!=&head) and (key < auxJ->getData()) ;auxJ=auxJ->getPrev())
				auxJ->getNext()->getData() = auxJ->getData();

		auxJ->getNext()->getData() = key;
	}
}


int main(){

	Dnode<int> head, head1, head2, *auxNod, *aux;
	int r;

	srand(time(NULL));

//prueba para merge sort
	for(int i=0; i<200; i++){
		r=rand()%500;
		auxNod= new Dnode<int>(r);
		head.insert(auxNod);
	}

	aux=head.getNext();
	cout<<"head sin ordenar"<<endl;
	while(aux!=&head){
		cout<<aux->getData()<<" ";
		aux=aux->getNext();
	}
	cout<<endl<<endl;

	mergeSort(head, head.getNext(), head.getPrev());

	aux=head.getNext();
	cout<<"head ordenado con merge Sort"<<endl;
	while(aux!=&head){
		cout<<aux->getData()<<" ";
		aux=aux->getNext();
	}
	cout<<endl<<endl<<endl;

//prueba para insert sort
	for(int i=0; i<200; i++){
		r=rand()%200;
		auxNod= new Dnode<int>(r);
		head1.insert(auxNod);
	}

	aux=head1.getNext();
	cout<<"head1 sin ordenar"<<endl;
	while(aux!=&head1){
		cout<<aux->getData()<<" ";
		aux=aux->getNext();
	}
	cout<<endl<<endl;


	insertSort(head1);

	aux=head1.getNext();
	cout<<"head1 ordenado con insert Sort"<<endl;
	while(aux!=&head1){
		cout<<aux->getData()<<" ";
		aux=aux->getNext();
	}
	cout<<endl<<endl<<endl;

//prueba para Select Sort
	for(int i=0; i<200; i++){
		r=rand()%300;
		auxNod= new Dnode<int>(r);
		head2.insert(auxNod);
	}

	aux=head2.getNext();
	cout<<"head2 sin ordenar "<<endl;
	while(aux!=&head2){
		cout<<aux->getData()<<" ";
		aux=aux->getNext();
	}
	cout<<endl<<endl;

	SelectSort(head2);

	aux=head2.getNext();
	cout<<"head2 ordenado con Select Sort"<<endl;
	while(aux!=&head2){
		cout<<aux->getData()<<" ";
		aux=aux->getNext();
	}
	cout<<endl<<endl;

	return 0;
}
