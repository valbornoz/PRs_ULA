#include "iostream"

using namespace std;

struct Fecha{
	int d;
	int m;
	int a;
};

struct Barco{
	string nombre;
	string tipo;
	int metros;
	Fecha entrada;
	Fecha salida;
	int ntripulantes;
};

main(){
	int n;

	cout<<"cuantos barcos desea registrar?"<<endl;
	cin>>n;

	struct Barco *b= new struct Barco[n];

	for(int i=0; i<n; i++){
		cout<<"introduzca nombre del barco "<<i+1<<endl;
		cin>>b[i].nombre;
		cout<<"introduzca el tipo del barco "<<i+1<<endl;
		cin>>b[i].tipo;
		cout<<"introduzca metros de eslora del barco "<<i+1<<endl;
		cin>>b[i].metros;
		cout<<"intoduzca fecha de entrada del barco "<<i+1<<endl;
		cin>>b[i].entrada.d>>b[i].entrada.m>>b[i].entrada.a;
		cout<<"introduzca fecha de salida del barco "<<i+1<<endl;
		cin>>b[i].salida.d>>b[i].salida.m>>b[i].salida.a;
		cout<<"cuantos tripulantes tiene el barco "<<i+1<<endl;
		cin>>b[i].ntripulantes;
	}

	delete []b;



}
