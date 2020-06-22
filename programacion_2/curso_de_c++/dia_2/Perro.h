#ifndef PERRO_H
#define PERRO_H
#include <iostream>
#include "Animal.h"
using namespace std;

class Perro : public Animal
{
	private:
		int raza;
		int color;
	public:
		Perro();
		~Perro();
		int ver_raza();
		int ver_color();
		void asignar_raza(int r);
		void asignar_color(int c);
		virtual void imprimir_info();


};
Perro::Perro()
{
	raza = -1;
	color = -1;
}
Perro::~Perro()
{
}
int Perro::ver_raza()
{
	return raza;
}
int Perro::ver_color()
{
	return color;
}
void Perro::asignar_raza(int r)
{
	raza = r;
}
void Perro::asignar_color(int c)
{
	color = c;
}
void Perro::imprimir_info()
{
	cout <<"Tipo: "<< ver_tipo() << endl;
	cout <<"Raza: "<< ver_raza() << endl;
	cout <<"Color: "<< ver_color() << endl;
}


#endif
