#include<iostream>
#include<stdlib.h>
#include "DNode.H"

using namespace std;


int hash(int x)
{

	return ((x)%10);

}

DNode<int>* buscar(DNode<int> &lista, int buscar)
{
	bool encontrado =false;
	DNode<int> * respuesta =NULL;
	DNode<int> * aux;
	aux = lista.getNext();
	while((aux != &lista) and !encontrado)
	{
		if(aux->getData()==buscar)
		{
			encontrado=true;
			respuesta =aux;
		}
		aux = aux->getNext();
	}

	return respuesta;
}

int main()
{

	DNode<int> x[10];


	//insertar
	for(int i=0;i<20;i++)
	{
		int ele = rand()%100;
		int pos = hash(ele);

		DNode<int> * aux = new DNode<int>(ele);
		
		//inserto
		x[pos].insertNext(aux);

	}
	
	//imprimimos todos los valores de la hash
	for(int i = 0;i<10;i++)
	{
		cout<<endl<<"Posicion :"<<i<<endl;
		DNode<int> * aux;
		aux = x[i].getNext();
		while(aux != &x[i])
		{
			cout<<aux->getData()<<" ";
			aux = aux->getNext();
		}
	}

	cout<<endl;

	int eleB;
	cin>>eleB;
	int posB = hash(eleB);
	
	if(buscar(x[posB],eleB)!= NULL)
	{
		cout<<"Si esta"<<endl;
	}
	else
	{
		cout<<"NO esta"<<endl;
	}

	cin>>eleB;
	int posE = hash(eleB);
	//eliminando un valor
	DNode<int> * eli = buscar(x[posE],eleB);
	if(eli!= NULL)
	{
		eli->deleteNode();
		cout<<"Si elimino de la lista"<<endl;
	}
	else
	{
		cout<<"NO se elimino de la lista"<<endl;
	}

	//imprimimos todos los valores de la hash
	for(int i = 0;i<10;i++)
	{
		cout<<endl<<"Posicion :"<<i<<endl;
		DNode<int> * aux;
		aux = x[i].getNext();
		while(aux != &x[i])
		{
			cout<<aux->getData()<<" ";
			aux = aux->getNext();
		}
	}

	cout<<endl;

return 0;
}


