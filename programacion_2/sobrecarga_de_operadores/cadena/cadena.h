#include <iostream>
using namespace std;

class Cadena {
	private:
		int tam;
                int edo;
		char * valor;
	public:
		Cadena();
		Cadena(const char * c);
		void mostrar();
                void agregar(const char * c);      
                void operator+(const char *c);
                void longitud();
                void upper();
                void operator+();
                void lower();
		~Cadena();
};


