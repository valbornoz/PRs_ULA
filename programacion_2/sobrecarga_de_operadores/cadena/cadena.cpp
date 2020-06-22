#include <iostream>
#include "cadena.h"

Cadena::Cadena() {
   tam = 0; 
   edo = 0;
   valor = NULL;
}

Cadena::Cadena(const char * c) {
   int i=0;
   while(c[i]!='\0') {
      i++;
   }
   tam = i; 
   edo = 0;
   valor = new char[tam+1];

   for(i=0; i<tam; i++) {
      valor[i] = c[i];
   }   
   valor[tam] = '\0';
}

void Cadena::mostrar() {
   cout << valor;
}

Cadena::~Cadena() {
   if (tam>0)
      delete [] valor;
}

void Cadena::agregar(const char * c){
   int i=0, tamC=0, j=0;
   char * cadAux;

   while(c[tamC]!='\0')
      tamC++;

   cadAux = new char[tam+tamC+1]; 

   for(i=0; i<tam; i++)
      cadAux[i] = valor[i];
   for(j=0; j<tamC; i++,j++)
      cadAux[i] = c[j];
   cadAux[i] = '\0';

   if(tam>0)
      delete [] valor;

   valor = cadAux;
   tam = tam + tamC;
}
   
void Cadena::operator+(const char *c) {
   agregar(c);
}

void Cadena::longitud() {
   cout << "Longitud = " << tam << " caracteres.\n";   
}

void Cadena::upper() {
   for(int i=0; i<tam; i++) {
      if(valor[i]>=97 && valor[i]<=122)
         valor[i] = valor[i]-32;
   }
}

void Cadena::operator+() {
   upper();
}

void Cadena::lower() {
   for(int i=0; i<tam; i++) {
      if(valor[i]>=65 && valor[i]<=90)
         valor[i] = valor[i]+32;
   }   
}


void tablaASCII() {
   cout << "\nTABLA ASCII:\n";
   for(int i=32; i<127; i++)
      cout << i << ".- " << (char)i << endl;
   cout << endl;
}
