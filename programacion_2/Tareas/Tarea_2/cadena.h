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
		int comparar(char * txt);
		int operator==(cadena cad1);
		void concatenar(char * txt);
		void operator+(char * txt); 
		int asignar(char * txt);
                int operator=(char * txt);
		void mostrar();
		int longitud();
		void invertir();
		void operator!();
                void mesh(char * txt);
		void operator*=(char *txt);		
		~cadena();

		void capital(char * txt);
		void operator--(char * txt);
};


