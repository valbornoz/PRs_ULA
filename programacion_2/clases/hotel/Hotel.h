#include <iostream>
#include <string.h>

using namespace std;

struct Fecha
{
	int dia;
	int mes;
	int anio;
};

class Hotel
{
	private:
		string nombreHotel;
		Fecha fecha_creacion;
		string ciudad;
		string direccion;
		string nombreGerente;
		string apellidoGerente;
		int cedula;
	public:
		Hotel();
		Hotel(string,Fecha,string,string,string,string,int);
		string getNombreHotel();
		int getCedula();
		void setNombreHotel();
		void setCedula();
		void IngresarDatos();
		void mostrar();
};
