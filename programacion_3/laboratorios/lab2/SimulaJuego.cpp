#include <iostream>
#include "sNode.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

struct carta{

	int figura;
	int numero;
};

int main(){

	sNode<carta> headMazo, mazoMezcla;
	sNode<carta> *aux, *retval, headSeguidilla1, headSeguidilla2, headSeguidilla3, headSeguidilla4;
	int n, cont,aaa=1, s;
	char c;

// llenar headMazo

	for(int i=0; i<4; i++){
		for(int j=0; j<13; j++){
			aux=new sNode<carta>;
			aux->getData().figura=i+1;
			aux->getData().numero=j+1;
			cout<<"carta: ("<<aux->getData().figura<<" "<<aux->getData().numero<<")"<<endl;

			headMazo.insertNext(aux);

		}
	}

//barajar y llenar mazoMezcla

	srand(time(NULL));

	aux=&headMazo;
	aux= aux-> getNext();

	while(!headMazo.isEmpty()){

	n=rand()%26;
	aux=headMazo.getNext();
	cont=0;
		
		while(cont!=n){
			aux=aux->getNext();

			cont++;
		}

		if(aux->getNext()==&headMazo){ aux=aux->getNext(); }

	retval=aux->removeNext();
	cout<<endl<<aaa++<<"carta: ("<<retval->getData().figura<<" "<<retval->getData().numero<<")"; 
	mazoMezcla.insertNext(retval);

	}

//mostrar headMazo y mazoMezcla

	cout<<endl<<endl<<endl;
	cout<<"headMazo:"<<endl<<endl;

aux=headMazo.getNext();

	 while(aux!=&headMazo){

	cout<<"carta: ("<<aux->getData().figura<<" "<<aux->getData().numero<<")"<<endl;
        aux=aux->getNext();
    	}

	cout<<endl<<endl<<endl;
	cout<<"mazoMezcla:"<<endl<<endl;

	aaa=1;

aux=mazoMezcla.getNext();

	 while(aux!=&mazoMezcla){

	cout<<aaa++<<"carta: ("<<aux->getData().figura<<" "<<aux->getData().numero<<")"<<endl;
        aux=aux->getNext();
    	}

//tomar o no las cartas

	cout<<endl<<endl<<endl;

	aux=&mazoMezcla;

	 while(!mazoMezcla.isEmpty()){

	cout<<"Desea tomar la ";
	cout<<"carta: ("<<aux->getNext()->getData().figura<<" "<<aux->getNext()->getData().numero<<")  [y/n]?"<<endl;
	cin>>c;

		if(c=='y' or c=='Y'){

			cout<<"en cual seguidilla desea insertar la carta: 1, 2, 3 o 4?"<<endl;
			cin>>s;
			retval=mazoMezcla.removeNext();
			if(s==1){ headSeguidilla1.insertNext(retval); }
			if(s==2){ headSeguidilla2.insertNext(retval); }
			if(s==3){ headSeguidilla3.insertNext(retval); }
			if(s==4){ headSeguidilla4.insertNext(retval); }

		}else{
			if(c=='n' or c=='N'){
				retval=mazoMezcla.removeNext();
				headMazo.insertNext(retval);
			}

		}

    	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////

	cout<<"mazoMezcla:"<<endl<<endl;

	aaa=1;

aux=mazoMezcla.getNext();

	 while(aux!=&mazoMezcla){

	cout<<aaa++<<"carta: ("<<aux->getData().figura<<" "<<aux->getData().numero<<")"<<endl;
        aux=aux->getNext();
    	}


// mostrar las seguidillas


	cout<<endl<<"headSeguidilla1:"<<endl;

	aaa=1;

aux=headSeguidilla1.getNext();

	 while(aux!=&headSeguidilla1){

	cout<<aaa++<<"carta: ("<<aux->getData().figura<<" "<<aux->getData().numero<<")"<<endl;
        aux=aux->getNext();
    	}
	cout<<endl<<"headSeguidilla2:"<<endl;

	aaa=1;

aux=headSeguidilla2.getNext();

	 while(aux!=&headSeguidilla2){

	cout<<aaa++<<"carta: ("<<aux->getData().figura<<" "<<aux->getData().numero<<")"<<endl;
        aux=aux->getNext();
    	}
	cout<<endl<<"headSeguidilla3:"<<endl;

	aaa=1;

aux=headSeguidilla3.getNext();

	 while(aux!=&headSeguidilla3){

	cout<<aaa++<<"carta: ("<<aux->getData().figura<<" "<<aux->getData().numero<<")"<<endl;
        aux=aux->getNext();
    	}


	cout<<endl<<"headSeguidilla4:"<<endl;

	aaa=1;

aux=headSeguidilla4.getNext();

	 while(aux!=&headSeguidilla4){

	cout<<aaa++<<"carta: ("<<aux->getData().figura<<" "<<aux->getData().numero<<")"<<endl;
        aux=aux->getNext();
    	}

	cout<<endl;



	return 0;
}


