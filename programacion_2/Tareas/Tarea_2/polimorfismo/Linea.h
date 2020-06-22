#ifndef LINEA_H
#define LINEA_H
#include "Transporte.h"

using namespace std;

class Linea: public Transporte{

	private:

	string nombre;
	int terminal;
	int numerouni;
	int capacidaduni;
	string ruta;
	float precio;

	public:

	Linea();
	Linea(int, string, int, int, string, int, int, int, string, float);
	~Linea();
	void leer();
	void mostrar();

};

Linea::Linea():Transporte(){
	nombre="";
	terminal=0;
	numerouni=0;
	capacidaduni=0;
	ruta="";
	precio=0.0;
}
	
Linea::Linea(int t, string d, int a, int n, string no, int te, int num, int c, string r, float p):Transporte(t,d,a,n){
	nombre=no;
	terminal=te;
	numerouni=num;
	capacidaduni=c;
	ruta=r;
	precio=p;
}
	
Linea::~Linea(){
}
	
void Linea::leer(){
	Transporte::leer();

	cout<<"introduzca nombre de la linea"<<endl;
	cin.ignore();
	getline(cin, nombre);
	cout<<"introduzca el terminal donde opera"<<endl;
	cin>>terminal;
	cout<<"cuantas unidades posee"<<endl;
	cin>>numerouni;
	cout<<"introduzca la capacidad de las unidades"<<endl;
	cin>>capacidaduni;
	cout<<"introduzca la ruta que realiza"<<endl;
	cin.ignore();
	getline(cin, ruta);
	cout<<"introduzca el precio del pasaje"<<endl;
	cin>>precio;
}
	
void Linea::mostrar(){
	Transporte::mostrar();

	cout<<"nombre de la linea: "<<nombre<<endl;
	cout<<"terminal donde opera: "<<terminal<<endl;
	cout<<"posee "<<numerouni<<" unidades"<<endl;
	cout<<"capacidad de las unidades: "<<capacidaduni<<endl;
	cout<<"ruta que realiza: "<<ruta<<endl;
	cout<<"precio del pasaje: "<<precio<<endl;
	cout<<endl;
}

#endif
