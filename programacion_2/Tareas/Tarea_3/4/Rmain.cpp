#include "Repuestos.h"
#include "fstream"
#include "iostream"
#include<stdlib.h>
using namespace std;

main(){

	Repuestos c;
	string nombre, marca, modelo;
	int anio, n;

	ofstream escri;
	ifstream leer;

	cout<<"cuantos clientes desea ingresar?"<<endl;
	cin>>n;

	int *codigo = new int [n];

	escri.open("aux.txt");

	if(!escri){
		cout<<"ERROR al abrir el archibo !"<<endl;
	}
	else{

		for(int i=0; i<n; i++){
			cout<<"cliente "<<i+1<<endl;
			cout<<"ingrese el codigo del cliente "<<i+1<<endl;
			cin>>codigo[i];
			c.asignar_codigo(codigo[i]);
			cout<<"ingrese nombre del cliente "<<i+1<<endl;
			cin.ignore();
			getline(cin,nombre);
			cout<<"ingrese marca del vehiculo del cliente "<<i+1<<endl;
			getline(cin,marca);
			cout<<"ingrese modelo del vehiculo del cliente "<<i+1<<endl;
			cin.ignore();
			getline(cin,modelo);
			cout<<"ingrese año del vehiculo del cliente "<<i+1<<endl;
			cin>>anio;
			
			cout<<endl;

			cout<<endl<<c.ver_codigo()<<endl;
			c.Depurar(codigo[i]);
			escri<<nombre<<"~"<<marca<<"~"<<modelo<<"~"<<codigo[i]<<"~"<<anio<<endl;
			
		}

	}
	escri.close();

delete []codigo;
}

