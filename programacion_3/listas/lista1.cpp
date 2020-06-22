#include <iostream>
#include "sNode.h"
#include "sList.h"
#include "Dnode.h"
using namespace std;

int main(){

	sList<int> l1;
	sNode<int>* auxNod, *aux;
	int valor;
	bool find;
	Dnode<int> head, *a, *an;
	cout<<"de el valor a insertar: 0 para salir"<<endl;
	cin>>valor;

	while(valor){
		auxNod=new sNode<int>(valor);
		if(auxNod!=NULL){
			if(l1.isEmpty()){ l1.insertFirt(auxNod);
				cout<<"l1: "<<l1.getFirt()->getData()<<endl;}
			else
				if(l1.getFirt()->getData() > valor){ l1.insertFirt(auxNod); 
					cout<<"hola2"<<endl;cout<<"l1(2): "<<l1.getFirt()->getData()<<endl;}
			else{
				aux=l1.getFirt();
				find=false;

				while(aux->getNext()->getNext() != l1.getFirt()){

					if(aux->getNext()->getData() > valor){
						aux->insertNext(auxNod);
						find=true;
						break;
					}

					else
						aux=aux->getNext();
                         	} 

				 if(!find) 
					aux->insertNext(auxNod);

 
			}
		}//if(auxNod!=NULL)			
		cout<<"de el valor a insertar: 0 para salir"<<endl;
		cin>>valor;
	}  //while


	cout<<endl<<endl<<endl<<"mostrar valores"<<endl;

		int i=0;
	for(sList<int>::Iterator it(l1) ;  it.hascurrent() ; it.Next()   ){
				cout<<"     "<<it.getcurrent()->getData()<<endl;
				i++;
			if(i==10){
				break;
			}
	}


/*	aux=l1.getFirt();
	
	while(aux!=l1.gethead()){

		cout<<aux->getData()<<endl;
		aux=aux->getNext();


	}*/

	return 0;
}


