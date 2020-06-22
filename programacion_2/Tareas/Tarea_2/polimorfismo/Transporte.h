#ifndef TRANSPORTE_H
#define TRANSPORTE_H
#include "iostream"
#include "string"

using namespace std;

class Transporte{

	private:

	int tipo;
	string direccion;
	int anio;
	int numaccion;

	public:

	Transporte();
	Transporte(int, string, int, int);
	~Transporte();
	virtual void leer();
	virtual void mostrar();
};

Transporte::Transporte(){
	tipo=0;
	direccion="";
	anio=0;
	numaccion=0;
}

Transporte::Transporte(int t, string d, int a, int n){
	tipo=t;
	direccion=d;
	anio=a;
	numaccion=n;
}

Transporte::~Transporte(){
}
	
void Transporte::leer(){
	cout<<"introduzca el tipo {1 para Aereo, 2 para Terrestre, 3 para Maritimo}"<<endl;
	cin>>tipo;
	cin.ignore();
	cout<<"introduzca la direccion de la sede"<<endl;
	getline(cin, direccion);
	cout<<"introduzca el año de fundacion"<<endl;
	cin>>anio;
	cout<<"introduzca el numero de accionistas"<<endl;
	cin>>numaccion;
}

void Transporte::mostrar(){
	cout<<endl;
	cout<<"tipo: "<<tipo<<endl;
	cout<<"direccion de la sede: "<<direccion<<endl;
	cout<<"año de fundacion: "<<anio<<endl;
	cout<<"numero de accionistas: "<<numaccion<<endl;
}


#endif

