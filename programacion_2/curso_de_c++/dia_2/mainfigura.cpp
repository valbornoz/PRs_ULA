#include <iostream>
#include "circulo.h"

using namespace std;

int main(){

	circulo c1;
	string apellido;

	c1.establecer_r(24);
	c1.establecer_x(5);

	cout<<"c1.obtener_x(): "<<c1.obtener_x()<<endl<<endl;
	c1.establecer_nombre("pikachu");
	cout<<"c1.obtener_nombre(): "<<c1.obtener_nombre()<<endl<<endl;
	c1.imprimir();

	return 0;
}
