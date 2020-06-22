#include <iostream>
#include "sNode.h"
using namespace std;

int main(){

    sNode<int> head;
    sNode<int>* aux;
     sNode<int>* auxMove;
    int valor;
	int numEle=0, *cont, max, pos, masrepetido;

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

if(head.getNext() != &head){

    aux=head.getNext();
    while(aux!=&head){

	cout<<"valor es   "<<aux->getData()<<endl;
        aux=aux->getNext();
		numEle++;
    }

	cout<<numEle<<" valores ingresados"<<endl;

// contar los valores

	cont=new int[numEle];

	aux=head.getNext();
	auxMove=aux;	

  while(aux!=&head){
	
	numEle=0;

	while(auxMove!=&head){
	
		if((auxMove->getData()) == (aux->getData())){

			cont[numEle]++;
		}

	auxMove=auxMove->getNext();
		
		//cout<<cont[numEle]<<endl;

			numEle++;

	}

		auxMove=head.getNext();
		aux=aux->getNext();
    }


	/*cout<<endl<<"contadores:"<<endl;
	for(int i=0; i<numEle; i++){

	cout<<cont[i]<<endl;

	}*/

// valor que mas se repite

	max=cont[0];

	for(int i=1; i<numEle ;i++){
		if(max<cont[i]){
		max=cont[i];
		}
		
	}

	//cout<<"max: "<<max<<endl;

if(max>1){
	for(int i=1; i<=numEle ;i++){
		if(max==cont[i]){
			pos=i;
		}
	}

	//cout<<"pos: "<<pos+1<<endl;


	aux=head.getNext();
	for(int i=0; i<pos-1; i++){
		aux=aux->getNext();
	}

	masrepetido=aux->getData();

		cout<<endl<<endl<<" EL VALOR Q MAS SE REPITE ES: "<<masrepetido<<endl<<endl;
	
   //eliminar un valor

    cout<<endl;
    cout<<endl;
    aux=head.getNext();
    if (aux->getData()==masrepetido)
       head.removeNext();
    while(aux!=&head){
        if (aux->getNext()->getData()==masrepetido)
           aux->removeNext();
        else
          aux=aux->getNext();
    }


       aux=head.getNext();
    while(aux!=&head){

	cout<<"valor es   "<<aux->getData()<<endl;
        aux=aux->getNext();
    }

}

delete []cont;
}

    return 0;
}
