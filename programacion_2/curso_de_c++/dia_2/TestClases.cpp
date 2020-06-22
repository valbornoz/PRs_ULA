#include <iostream>
#include "Hora.h"
using namespace std;

int main()
{
	Hora x;
	/*
	cout << x.ver_hora() <<endl;
	cout << x.ver_minutos() <<endl;
	cout << x.ver_segundos() <<endl;*/
	x.imprimir_hora();
	cout << x <<endl;
	cin>>x;
	
	/*x.asignar_hora(10);
	x.asignar_minutos(30);
	x.asignar_segundos(28);*/
	
	//cout << x.ver_hora() <<":"<<x.ver_minutos()<<":"<<x.ver_segundos() <<endl;
	x.imprimir_hora();
	cout <<"Segundos: "<<x.obtener_segundos_hora()<<endl;
	cout << x << endl;
	//z = x+y;
	
	Hora z;
	z = x;
	cout << z << endl;
	
	if(x == z)
	{
		cout << "Son Iguales" << endl;
	}

	Hora h;
	h = x+z;
	cout << h <<endl;


	return 0;
}

