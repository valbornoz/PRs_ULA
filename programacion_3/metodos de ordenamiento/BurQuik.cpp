#include <iostream>
#include "Dnode.h"

using namespace std;

void burbuja(int A[], int li, int ls){
	int aux,n;
	n=ls-li;

	for(int i=1; i<=n; i++)
		for(int j=0; j<=n-1; j++)
			if(A[j]>A[j+1]){
				aux=A[j];
				A[j]=A[j+1];
				A[j+1]=aux;
			}
}

void Swap(Dnode<int>* A, Dnode<int>* B){
	int temp;

	temp=A->getData();
	A->getData()=B->getData();
	B->getData()=temp;
}

void swap(int A[], int j, int i){
	int aux;

	aux=A[i];
	A[i]=A[j];
	A[j]=aux;
}

int divide(int *array, int start, int end) {
    int left, right;
    int pivot;
 
    pivot = array[start];
    left = start;
    right = end;
 
    // Mientras no se cruzen los índices
    while (left < right) {
        while (array[right] > pivot) right--;
        while ((left < right) && (array[left] <= pivot)) left++;
        // Si todavía no se cruzan los indices seguimos intercambiando
        if (left < right)
		swap(array, left, right);
    }
    // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
 swap(array, start, right);
    // La nueva posición del pivot

    return right;
}

void quicksort(int *array, int start, int end)
{
    int pivot;
    if (start >= end) return;
        pivot = divide(array, start, end);
        quicksort(array, start, pivot - 1);
        quicksort(array, pivot + 1, end);
}

void Burbuja(Dnode<int> &B){

	for(Dnode<int>* auxI=B.getNext()->getNext(); auxI!=&B; auxI=auxI->getNext())
		for(Dnode<int>* auxJ=B.getNext(); auxJ!=B.getPrev(); auxJ=auxJ->getNext())
			if(auxJ->getData() > auxJ->getNext()->getData())
					Swap(auxJ, auxJ->getNext());
}

Dnode<int>* Divide(Dnode<int> array, Dnode<int>* start, Dnode<int>* end) {
    Dnode<int>* left, *right;
    int pivot;
 
    pivot = start->getData();
    left = start;
    right = end;
 
    while (left != right and left->getNext()!=right) {
        while (right->getData() > pivot) right=right->getPrev();
        while ((left != right and left->getNext()!=right) and (left->getData() <= pivot)) left=left->getNext();
        if (left != right and left->getNext()!=right)
		Swap(left, right);
    }
 Swap(start, right);

    return right;
}

void Quicksort(Dnode<int> array, Dnode<int>* start, Dnode<int>* end)
{
    Dnode<int> *pivot;
    if (start == end or end->getNext()==start) return;
        pivot = Divide(array, start, end);
        Quicksort(array, start, pivot->getPrev());
        Quicksort(array, pivot->getNext(), end);
}

int main(){

	int B[30]={141, 151, 171, 121, 405, 41, 40, 80, 50, 70, 33, 20, 10, 11, 14, 77, 9, 6, 181, 77, 6, 4, 12, 4, 8, 5, 7, 2, 0, 1};
	int Q[30]={141, 151, 171, 121, 405, 41, 40, 80, 50, 70, 33, 20, 10, 11, 14, 77, 9, 6, 181, 77, 6, 4, 12, 4, 8, 5, 7, 2, 0, 1};

	for(int i=0; i<30; i++)
		cout<<B[i]<<" ";
	cout<<endl;

	burbuja(B,0,29);

	for(int i=0; i<30; i++)
		cout<<B[i]<<" ";
	cout<<endl<<endl;



	for(int i=0; i<30; i++)
		cout<<Q[i]<<" ";
	cout<<endl;

	quicksort(Q,0,29);

	for(int i=0; i<30; i++)
		cout<<Q[i]<<" ";
	cout<<endl<<endl;

/////////////////////////////////////////////////////////////////////////////////////

	Dnode<int> B2;
	Dnode<int> Q2;
	Dnode<int>* auxNod, *aux;


		auxNod= new Dnode<int>(141);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(151);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(171);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(121);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(405);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(41);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(40);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(80);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(50);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(70);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(33);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(20);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(10);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(11);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(14);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(77);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(9);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(6);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(181);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(77);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(6);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(4);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(12);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(4);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(8);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(5);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(7);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(2);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(0);
		B2.insert(auxNod);
		auxNod= new Dnode<int>(1);
		B2.insert(auxNod);

	aux=B2.getNext();
	cout<<"B2 sin ordenar"<<endl;
	while(aux!=&B2){
		cout<<aux->getData()<<" ";
		aux=aux->getNext();
	}
	cout<<endl;

		Burbuja(B2);

	aux=B2.getNext();
	cout<<"B2 ordenado"<<endl;
	while(aux!=&B2){
		cout<<aux->getData()<<" ";
		aux=aux->getNext();
	}
	cout<<endl<<endl;


		auxNod= new Dnode<int>(141);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(151);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(171);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(121);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(405);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(41);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(40);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(80);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(50);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(70);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(33);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(20);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(10);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(11);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(14);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(77);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(9);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(6);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(181);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(77);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(6);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(4);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(12);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(4);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(8);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(5);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(7);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(2);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(0);
		Q2.insert(auxNod);
		auxNod= new Dnode<int>(1);
		Q2.insert(auxNod);

	aux=Q2.getNext();
	cout<<"Q2 sin ordenar"<<endl;
	while(aux!=&Q2){
		cout<<aux->getData()<<" ";
		aux=aux->getNext();
	}
	cout<<endl;

		Quicksort(Q2, Q2.getNext(), Q2.getPrev());

	aux=Q2.getNext();
	cout<<"Q2 ordenado"<<endl;
	while(aux!=&Q2){
		cout<<aux->getData()<<" ";
		aux=aux->getNext();
	}
	cout<<endl<<endl;

	return 0;
}
