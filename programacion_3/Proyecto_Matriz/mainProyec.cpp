#include <iostream>
#include "Dnode.h"
#include "conjuntosArreglos.h"
#include <assert.h>
#include "MatrisE.h"



using namespace std;

int main(){

	MatrisE m1, m2, m3;
	int fila, columna, valor;
	char c;

//imprimir la matris que por defecto es 100 X 100

	m1.imprimirMatris();
	cout<<"matris m1 impresa, con el tamaño por defecto (100 X 100)"<<endl;

//insertar un valor en la matris m1
	cout<<"introdusca un valor en la matris m1"<<endl;
		cout<<"fila, columna y valor"<<endl;
		cin>>fila>>columna>>valor;
		m1.asiggn(fila, columna, valor);
		cout<<"m1.search(fila, columna): "<<m1.search(fila, columna)<<endl;

//imprimir matris m1 con el valor insertado
cout<<"imprimir matris m1 con el valor insertado"<<endl;
	m1.imprimirMatris();
cout<<"m1 impresa"<<endl;

// introducir un valor en m2
cout<<"introdusca un valor para la matris m2 la cual tiene tamaño por defecto"<<endl;
		cout<<"fila, columna y valor"<<endl;
		cin>>fila>>columna>>valor;
		m2.asiggn(fila, columna, valor);
		cout<<"m2.search(fila, columna): "<<m2.search(fila, columna)<<endl;

	m3=m1+m2;

//imprimir la suma de m1 con m2
	m3.imprimirMatris();
cout<<"esta matris es la suma de m1 con m2"<<endl;

cout<<endl<<endl;


//crear m4 una matris de cualquier tamaño
cout<<"introdusca el tamaño para la matris m4 (fila X columna)"<<endl;
cout<<"¿cuantas filas desea?"<<endl;
cin>>fila;
cout<<"¿cuantas columnas desea?"<<endl;
cin>>columna;

MatrisE m4(fila, columna);

	m4.imprimirMatris();

// insertar elementos en m4

	cout<<"desea insertar en m4 [s/n]?"<<endl;
	cin>>c;
	while(c!='n' and c!='N'){

		cout<<"fila, columna y valor"<<endl;
		cin>>fila>>columna>>valor;
		m4.asiggn(fila, columna, valor);
		cout<<"m4.search(fila, columna): "<<m4.search(fila, columna)<<endl;		

		cout<<"insertar otro elemento [s/n]?"<<endl;
		cin>>c;

	}

	cout<<"matris m4: "<<endl;
	m4.imprimirMatris();





	return 0;

}
