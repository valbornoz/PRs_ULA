#include <iostream>
#include "string.h"
#include "Prenda.h"

Prenda::Prenda() {
   genero = 'U';
   anio = 0;
   precio = 0;
   strcpy(color,"-");
}

Prenda::Prenda(char g, int a, float p, char *c) {
   genero = g;
   anio = a;
   precio = p;
   strcpy(color,c);
}

Prenda::~Prenda() {
}

void Prenda::lectura() {
   cout << "Género (H/M/U): ";
   cin >> genero;

   cout << "Año de fabricación: ";
   cin >> anio;

   cout << "Precio: ";
   cin >> precio;

   cout << "Color: ";
   cin >> color;
}

void Prenda::desplegar() {
   cout << "Género: " << genero << endl;
   cout << "Año: " << anio << endl;
   cout << "Precio: " << precio << endl;
   cout << "Color: " << color << endl;
}

char Prenda::getGenero() {
   return genero;
}

void Prenda::getColor(char *c) {
   strcpy(c,color);
}
