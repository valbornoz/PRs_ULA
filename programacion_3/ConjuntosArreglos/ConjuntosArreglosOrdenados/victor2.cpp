#include <iostream>
#include <stdlib.h>
#include "arregloOrd.h"


using namespace std;

struct aRepartir{

	char letra;
	int cantidad;

};

int main(){

	ArregloOrd<aRepartir> x;
	aRepartir y;
	ArregloOrd<char> j1[4];

	srand(time(NULL));

	for(int i=0; i<26; i++){

	y.letra=i+65;
	y.cantidad=(rand()%5)+2;

	cout<<y.letra<<"=="<<y.cantidad<<"     ";

	x.insert2(y);

	}

	cout<<endl<<endl<<endl;

	for(int i=0; i<7; i++){

	char l=(rand()%26)+65, l1=(rand()%26)+65, l2=(rand()%26)+65, l3=(rand()%26)+65;
	j1[0].insert2(l);
	j1[1].insert2(l1);
	j1[2].insert2(l2);
	j1[3].insert2(l3);

	}

	for(int i=0; i<7; i++){

	cout<<j1[0].

	}



/*
	char a=65, b=66, c=69, d=81;

	ArregloOrd<repartir> x;

	for(int i = 0; i < 26; i++){

	repartir y;
	y.letras = i+65;
	y.cantidad = 5;
	x.insert(y);

	}
*/





	return 0;
}
