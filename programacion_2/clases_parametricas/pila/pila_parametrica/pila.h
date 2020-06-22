#include <iostream>
using namespace std;

template <class tipo1>
class Pila { 
	private:
		struct Nodo {
		tipo1 dato;
   		Nodo* nodoSiguiente;  
		} * nodoTope;
   	tipo1 tamano;
	public:
    	Pila();
    	~Pila();
    	void push(tipo1 elem);  // Ingresa un nuevo nodo en la pila
    	void pop();   // Retira el nodo tope de la pila
     	tipo1 tope(); // Retorna el dato del nodo que se encuentra en el tope	
};

template <class tipo1> Pila<tipo1>::Pila() {
	nodoTope = NULL;
	tamano = 0;
}

template <class tipo1> void Pila<tipo1>::push(tipo1 a) {
	Nodo* nodoNuevo = new Nodo;
   nodoNuevo->dato = a;
   nodoNuevo->nodoSiguiente = nodoTope;
   nodoTope = nodoNuevo;
   tamano = tamano + 1;
}

template <class tipo1> void Pila<tipo1>::pop() {
	if (tamano>0) {
		Nodo* aux = nodoTope;
	   nodoTope = nodoTope->nodoSiguiente;
   	delete aux;
	   tamano = tamano - 1;
	}
}

template <class tipo1> Pila<tipo1>::~Pila() {
	while (tamano != 0) 
		pop();
}
 
template <class tipo1> tipo1 Pila<tipo1>::tope() {
	return nodoTope->dato;
}
