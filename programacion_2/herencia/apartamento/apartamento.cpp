#include <iostream>
#include "string.h"
#include "apartamento.h"


apartamento::apartamento(){

	nombreR =" ";
	nombreE = " ";
	identificador = 0;
	metroC = 0;
}


	apartamento::apartamento(char * nP, char * aP, char *c, char *e, char *m, int a, string nr, string ne, int id, int mc):Inmueble(nP, aP, c, e, m, a){// CONSTRUCTOR PARAMETRICO

	nombreR =nr;
	nombreE = ne;
	identificador = id;
	metroC = mc;
}


	apartamento::~apartamento(){// DESTRUCTOR
}


	void apartamento::lectura(){ //LECTURA

	Inmueble::lectura();// FUNCION HEREDADE DE INMUEBLE

	cout<<" Nombre de la Residencia" << endl;
	cin>> nombreR;
	
	cout<<" Nombre del Edificio" << endl;
	cin>> nombreE;

	cout<<" identificador(solo numeros)" << endl;
	cin>> identificador;

	cout<<" metros cuadrados" << endl;
	cin>> metroC;

}

	void apartamento:: mostrar(){// FUNCION HEREDADA DE INMUEBLE

	Inmueble::mostrar();
	
	cout<< "Nombre de la residencia " << nombreR << endl;
	cout<< "Nombre del edificio " << nombreE << endl;
	cout<< "identificador " << identificador << endl;
	cout << "cantidad de metros cuadrados" << metroC<< endl;
	
}




