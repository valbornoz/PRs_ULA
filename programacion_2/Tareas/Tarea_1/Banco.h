#ifndef BANCO_H
#define BANCO_H
#include "iostream"
#include "string"

using namespace std;

struct Fecha{
	int d;
	int m;
	int a;
};

class Banco{

	private:
	string nombreb;
	string nombrea;
	Fecha fecha;
	string ciudad;
	string direccion;
	string nombreg;
	string apellidog;
	string cedulag;

	public:

	Banco();

	Banco(string, string, Fecha, string, string, string, string, string);

	Banco(const Banco &);

	void setnombreb(string);
	void setnombrea(string);
	void setfecha(Fecha);
	void setciudad(string);
	void setdireccion(string);
	void setnombreg(string);
	void setapellidog(string);
	void setcedulag(string);

	string getnombreb();
	string getnombrea();
	Fecha getfecha();
	string getciudad();
	string getdireccion();
	string getnombreg();
	string getapellidog();
	string getcedulag();

	void lectura(int);
	void mostrar(int);

	~Banco();

};

#endif


