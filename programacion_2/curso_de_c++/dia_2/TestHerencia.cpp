#include <iostream>
#include "Perro.h"
#include "Animal.h"
using namespace std;

int main()
{
	Perro p;
	p.asignar_tipo(4);
	//cout << p.ver_tipo() <<endl;
	p.imprimir_info();

	return 0;
}
