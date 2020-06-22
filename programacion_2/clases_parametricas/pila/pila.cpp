#include "pila.h"

Pila::Pila() {
	nodoTope = NULL;
	tamano = 0;
}

void Pila::push(int a) {
   Nodo* nodoNuevo = new Nodo;
   nodoNuevo->dato = a;
   nodoNuevo->nodoSiguiente = nodoTope;
   nodoTope = nodoNuevo;
   tamano = tamano + 1;
}

void Pila::pop() {
	if (tamano>0) {
	   Nodo* aux = nodoTope;
	   nodoTope = nodoTope->nodoSiguiente;
   	delete aux;
	   tamano = tamano - 1;
	}
}

Pila::~Pila() {
	while (tamano != 0) 
		pop();
}
 
 
void Pila::operator<<(int a) {
	push(a);
}

 
int Pila::tope() {
	return nodoTope->dato;
}
 
bool Pila::vacia() {
	if (tamano==0)
		return 1;
	else
		return 0;
}
 
int Pila::altura() {
	return tamano;
}

