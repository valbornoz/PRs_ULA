#include <iostream>
#include "string.h"
#include "Instrumento.h"

Instrumento::Instrumento(){
	strcpy(nombre,"");
	strcpy(tipo,"");
	strcpy(inventor,"");
	anyo = 0;
	strcpy(pais,"");
}

Instrumento::Instrumento(char *n, char *t, char *i, int a, char *p){
	strcpy(nombre,n);
	strcpy(tipo,t);
	strcpy(inventor,i);
	anyo = a;
	strcpy(pais,p);
}
Instrumento::~Instrumento() {
}

void Instrumento::lectura() {
   cout << "Nombre: ";
   //cin >> nombre;
  cin.ignore();
  cin.getline (nombre,100);

   cout << "Tipo Instrumento: ";
   cin >> tipo;

   cout << "Creado el año de: ";
   cin >> anyo;

   cout << "Por: ";
   //cin >> inventor;
   cin.ignore();
   cin.getline (inventor,100);
}
void Instrumento::showAll() {
	cout << "Nombre: " << nombre << endl;
	cout << "Tipo de Instrumento: " << tipo << endl;
	cout << "Creado el año de " << anyo << ", en " << pais;
	cout << " por " << inventor << endl;

}

