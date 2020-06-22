#ifndef VEHICULO_H
#define VEHICULO_H
#include "iostream"
#include "string"

using namespace std;

class Vehiculo{

	private:
	
	string tipo;
	string marca;
	string modelo;
	int nejes;
	int anio;

	public:

	Vehiculo();
	Vehiculo(string, string, string, int, int);
	Vehiculo(const Vehiculo &);

	void asignar_tipo(string);
	void asignar_marca(string);
	void asignar_modelo(string);
	void asignar_nejes(int);
	void asignar_anio(int);

	string ver_tipo();
	string ver_marca();
	string ver_modelo();
	int ver_nejes();
	int ver_anio();

	void imprime();

	~Vehiculo();
};

#endif
