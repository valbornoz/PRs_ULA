#include <iostream>
using namespace std;

class Pila { 
	private:
		struct Nodo {
			int dato;
   		Nodo* nodoSiguiente;  
		} * nodoTope;
   	int tamano;
	public:
    	Pila();
    	~Pila();
    	void push(int elem);  // Ingresa un nuevo nodo en la pila
		void operator<<(int elem); // 
    	void pop();   // Retira el nodo tope de la pila
     	int tope(); // Retorna el dato del nodo que se encuentra en el tope	
 		bool vacia(); // Retorna 1 si la pila está vacía
 		int altura(); // Retorna la cantidad de nodos de la pila
};
