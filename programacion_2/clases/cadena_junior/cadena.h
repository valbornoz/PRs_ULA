#include <iostream>
using namespace std;

class cadena {
	private:
		int tamano;
		char * c;
	public:
		cadena();
		cadena(int t);
		cadena(char * txt);
                int operator==(char * txt);
		void mostrar();
		int longitud();
                void asignar(char *txt);
		void operator=(char * txt);
                void operator+(char * txt);
		~cadena();
};


