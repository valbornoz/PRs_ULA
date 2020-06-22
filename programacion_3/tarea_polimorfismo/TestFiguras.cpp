#include <iostream>
#include "Figura.h"
#include "Cuadrado.h"
#include "Triangulo.h"
#include "Circulo.h"

using namespace std;

int main(){
	
	Cuadrado c;
	Triangulo t;
	Circulo ci;
	int opcion;

	cout<<"indique la figura de la cual quiere calcular el area:"<<endl<<endl;
	cout<<"triangulo....1"<<endl;
	cout<<"cuadrado.....2"<<endl;
	cout<<"circulo......3"<<endl;
	cout<<"salir........4"<<endl;
	cin>>opcion;

	switch(opcion){

	case 1:

	float b,a;

	cout<<"introduzca base"<<endl;
	cin>>b;
	cout<<"introduzca altura"<<endl;
	cin>>a;

	t.setbase(b);
	t.setaltura(a);

	cout<<endl;

	cout<<"el area del triangulo es: "<<t.calcular_area()<<endl;
	break;

	case 2:

	float l;

	cout<<"introduzca tamaño del lado"<<endl;
	cin>>l;

	c.setlado(l);

	cout<<endl;

	cout<<"el area del cuadrado es: "<<c.calcular_area()<<endl;
	break;

	case 3:

	float r;

	cout<<"introduzca el radio"<<endl;
	cin>>r;

	ci.setradio(r);

	cout<<endl;

	cout<<"el area del circulo es: "<<ci.calcular_area()<<endl;
	break;

	case 4:
	break;

	default:
	cout<<"ERROR: opcion incorrecta"<<endl;
	}


	return 0;
}
