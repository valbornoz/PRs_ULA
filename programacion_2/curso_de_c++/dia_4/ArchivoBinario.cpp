#include <iostream>
#include <fstream>
//#include "Hora.h"
using namespace std;


struct Hora
{
	int h,m,s;
};


int main()
{

	/*fstream manejador;
	
	manejador.open("binario.dat", ios::out | ios::binary | ios::app);
	
	int x = 10;
	
	manejador.write(reinterpret_cast<char*>(&x),sizeof(x));
	
	manejador.close();
	
	fstream ver;
	ver.open("binario.dat",ios::in | ios::binary);
	if(!ver)
	{
		cout << "NO abrio el archivo" << endl;
	}	
	else
	{
		int data;
		ver.read(reinterpret_cast<char*>(&data),sizeof(data));
		while(!ver.eof())
		{
			cout << data << endl;
			ver.read(reinterpret_cast<char*>(&data),sizeof(data));
		}


		ver.close();
	}*/
	
	//Guardar bloques de datos
	/*fstream datos;
	Hora h;
	h.asignar_hora(10);
	h.asignar_minutos(10);
	h.asignar_segundos(10);
	h.h=10;
	h.m=10;
	h.s=10;

	datos.open("binarioHora.dat", ios::out | ios::binary | ios::app);

	datos.write(reinterpret_cast<char*>(&h),sizeof(h));
	
	datos.close();
	
	
	fstream ver;
	ver.open("binarioHora.dat",ios::in | ios::binary);
	if(!ver)
	{
		cout << "NO abrio el archivo" << endl;
	}	
	else
	{
		Hora data;
		ver.read(reinterpret_cast<char*>(&data),sizeof(data));
		while(!ver.eof())
		{
			cout << data.h << ":" << data.m << ":" << data.s << endl;
			ver.read(reinterpret_cast<char*>(&data),sizeof(data));
		}


		ver.close();
	}*/


	//guardar cadenas de caracteres
	
	/*fstream cadena;
	cadena.open("binarioCadena.dat",ios::out | ios::binary | ios::app);
	
	char cade[100];
	cin>>cade;
	
	cadena.write(reinterpret_cast<char*>(&cade),sizeof(cade));
	
	cadena.close();

	fstream ver;
	ver.open("binarioCadena.dat",ios::in | ios::binary);
	if(!ver)
	{
		cout << "NO abrio el archivo" << endl;
	}	
	else
	{
		char data[100];
		ver.read(reinterpret_cast<char*>(&data),sizeof(data));
		while(!ver.eof())
		{
			cout << data << endl;
			ver.read(reinterpret_cast<char*>(&data),sizeof(data));
		}


		ver.close();
	}*/


	return 0;
}
