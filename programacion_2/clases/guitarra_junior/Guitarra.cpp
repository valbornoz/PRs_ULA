#include <iostream>
#include "Guitarra.h"
#include "string.h"

Guitarra::Guitarra():Instrumento() {
   nCuerdas = 0;
   strcpy(material,"");
   strcpy(subtipo,"");   
}

Guitarra::Guitarra(char *n, char *t, char *i, int a, char *p, int b,char * m, char *s) :
   Instrumento(n,t,i,a,p) {
   nCuerdas = b;
   strcpy(material,m);
   strcpy(subtipo,s);   
}

Guitarra::~Guitarra(){
}

void Guitarra::lectura() {
   Instrumento::lectura();

   cout << "Tipo de Guitarra: ";
   cin >> subtipo;
 
   cout << "Material: ";
   cin >> material;
 
   cout << "Nro. de Cuerdas: ";
   cin >> nCuerdas;
 
}

void Guitarra::showAll() {
   Instrumento::showAll();
   cout << "Tipo de guitarra: " << subtipo << endl;
   cout << "Material: " << material << endl;
   cout << "Nro. de cuerdas: " << nCuerdas << endl << endl;
}
