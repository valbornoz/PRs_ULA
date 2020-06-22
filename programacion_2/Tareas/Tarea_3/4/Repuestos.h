#ifndef REPUESTOS_H
#define REPUESTOS_H
#include "iostream"
#include "fstream"
#include<stdlib.h>
class Repuestos{

	private:

	int codigo;

	public:

	Repuestos();
	Repuestos(int);
	~Repuestos();

	int ver_codigo();

	void asignar_codigo(int);
	void Depurar(int);

};

#endif
