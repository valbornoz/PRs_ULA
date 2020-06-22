#include <iostream>
#include "Suma.h"
using namespace std;

int main()
{
	Suma<int> s;

	Suma<float> f;

	s.asignar_a(10);
	s.asignar_b(20);
	int suma;
	suma = s.sumar();
	cout <<"Suma: "<< suma <<  endl;
//	if(&& || and )
	return 0;
}
