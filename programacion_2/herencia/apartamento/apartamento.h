#include <iostream>
#include "string.h"
#include"Inmueble.h"
using namespace std;


	class apartamento: public Inmueble{ // CLASE APARTAMENTO HEREDA DE INMUEBLE


	private:

	string nombreR;
	string nombreE;
	int identificador;
	int metroC;

	public:

	apartamento();
	apartamento(char *, char * , char *, char *, char *, int , string, string, int, int);
	~apartamento();
	void lectura();
	void mostrar();

};


	
