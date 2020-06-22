#ifndef AUTOMOVIL_H
#define AUTOMOVIL_H
#include "iostream"

using namespace std;

class Automovil{

	private:

	int numero;
	float tiempo1;
	float tiempo2;
	float tiempo3;
	float mjrtiempo;

	public:

	Automovil();
	Automovil(int, float, float, float, float);
	Automovil(const Automovil &);

	void asignar_numero(int);
	void asignar_tiempo1(float);
	void asignar_tiempo2(float);
	void asignar_tiempo3(float);
	void asignar_mjrtiempo(float);

	int ver_numero();
	float ver_tiempo1();
	float ver_tiempo2();
	float ver_tiempo3();
	float ver_mjrtiempo();

	void calcular_MT();

	~Automovil();
};

#endif
