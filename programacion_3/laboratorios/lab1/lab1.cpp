#include <iostream>
#include "conjuntosArreglos.h"
#include <stdlib.h>
using namespace std;

struct fichas{
	char letra;
	int cantidad;


bool operator==(const fichas& ele){
	return (this->letra==ele.letra);}

};


int main(){

	char c;
	ConjuntosArreglos<fichas>  conjrepartir;
	fichas a;
	ConjuntosArreglos<char> jugador1,jugador2,jugador3,jugador4;

	for(int i=65; i<=91; i++){
		c=i;
		a.letra=c;
		a.cantidad=2;
		conjrepartir.insert(a);
	}

	cout<<"repartir [s/n]?"<<endl;
	cin>>c;
	if((c=='n') or (c=='N')) return 0;

	srand(time(NULL));

	for(int i=0; i<7; i++){
		c=(rand()%27)+65;
		a.letra=c;

		while((*conjrepartir.search(a)).cantidad==0){

		c=(rand()%27)+65;
		a.letra=c;

		}
		jugador1.insert(c);
		(*conjrepartir.search(a)).cantidad--;

		c=(rand()%27)+65;
		a.letra=c;

		while((*conjrepartir.search(a)).cantidad==0){

		c=(rand()%27)+65;
		a.letra=c;

		}
		jugador2.insert(c);
		(*conjrepartir.search(a)).cantidad--;

		c=(rand()%27)+65;
		a.letra=c;

		while((*conjrepartir.search(a)).cantidad==0){

		c=(rand()%27)+65;
		a.letra=c;

		}
		jugador3.insert(c);
		(*conjrepartir.search(a)).cantidad--;

		c=(rand()%27)+65;
		a.letra=c;

		while((*conjrepartir.search(a)).cantidad==0){

		c=(rand()%27)+65;
		a.letra=c;

		}
		jugador4.insert(c);
		(*conjrepartir.search(a)).cantidad--;
	}


	cout<<"jugador1 == ";	
	for(int i=0; i<jugador1.GetNumEle(); i++){
        cout<<*jugador1.searchInPos(i)<<", ";
    	}
	cout<<endl;

	cout<<"jugador2 == ";
	for(int i=0; i<jugador2.GetNumEle(); i++){
        cout<<*jugador2.searchInPos(i)<<", ";
    	}
	cout<<endl;

	cout<<"jugador3 == ";
	for(int i=0; i<jugador3.GetNumEle(); i++){
        cout<<*jugador3.searchInPos(i)<<", ";
    	}
	cout<<endl;

	cout<<"jugador4 == ";
	for(int i=0; i<jugador4.GetNumEle(); i++){
        cout<<*jugador4.searchInPos(i)<<", ";
    	}
	cout<<endl;

	cout<<endl;
	cout<<"conjrepartir: "<<endl;
	fichas aux;
	for(int i=0; i<conjrepartir.GetNumEle(); i++){
		aux=*conjrepartir.searchInPos(i);
        cout<<aux.letra<<"    "<<aux.cantidad<<endl;
    	}
	cout<<endl;
	return 0;
}
