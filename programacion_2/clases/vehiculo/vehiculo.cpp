#include "vehiculo.h"

using namespace std;

Vehiculo::Vehiculo(){
	tipo=" ";
	marca=" ";
	modelo=" ";
	nejes=0;
	anio=0;
}

Vehiculo::Vehiculo(string t, string ma, string mo, int n, int a){
	tipo=t;
	marca=ma;
	modelo=mo;
	nejes=n;
	anio=a;
}

Vehiculo::Vehiculo(const Vehiculo &v){
	tipo=v.tipo;
	marca=v.marca;
	modelo=v.modelo;
	nejes=v.nejes;
	anio=v.anio;
}
	
void Vehiculo::asignar_tipo(string t){
	tipo=t;
}	

void Vehiculo::asignar_marca(string ma){
	marca=ma;
}	

void Vehiculo::asignar_modelo(string mo){
	modelo=mo;
}

void Vehiculo::asignar_nejes(int n){
	nejes=n;
}

void Vehiculo::asignar_anio(int a){
	anio=a;
}

string Vehiculo::ver_tipo(){
	return tipo;
}
	
string Vehiculo::ver_marca(){
	return marca;
}
	
string Vehiculo::ver_modelo(){
	return modelo;
}
	
int Vehiculo::ver_nejes(){
	return nejes;
}
	
int Vehiculo::ver_anio(){
	return anio;
}

void Vehiculo::imprime(){
	cout<<"tipo: "<<tipo<<endl;
	cout<<"marca: "<<marca<<endl;
	cout<<"modelo: "<<modelo<<endl;
	cout<<"cant. de ejes: "<<nejes<<endl;
	cout<<"año: "<<anio<<endl;
}

Vehiculo::~Vehiculo(){
}


