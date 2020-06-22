#include "iostream"
#include "Punto.h"

main(){

//	Punto<int> *p1 = new Punto<int>(5, 7);

	Punto<float> p2, p3, p4;
	Punto<int> p5, p6, p1;

	p3.setX(32.7);
	p3.setY(3.00004);
	p4.setX(12.6);
	p4.setY(8.9);

	p5.setX(56);
	p5.setY(2);
	p6.setX(5);
	p6.setY(7);

	cout<<"la suma del punto float es: "<<endl;
	p2.sumaPunto(4.5, 6.7);
	cout<<"la suma del punto entero es: "<<endl;
	p1.sumaPunto(5, 7);

	p2.suma(p3, p4);
	p1.suma(p5, p6);

	cout<<endl<<"la suma de los 2 puntos enteros es ";
	p1.mostrarPunto();
	cout<<endl<<"la suma de los 2 puntos float es ";
	p2.mostrarPunto();

//delete p1;
}
