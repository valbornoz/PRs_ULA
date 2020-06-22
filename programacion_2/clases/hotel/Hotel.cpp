#include "Hotel.h"
#include "iostream"

// constructor vacio
Hotel::Hotel()
{
	
}

// costructor parametrico

Hotel::Hotel(string a,Fecha b,string c,string d,string e,string f,int g)
{
	this->nombreHotel = a;
	this->fecha_creacion = b;
	this->ciudad = c;
	this->direccion = d;
	this->nombreGerente = e;
	this->apellidoGerente = f;
	this->cedula = g;
}


// metodos get y set

string Hotel::getNombreHotel()
{
	cout << "ingrese el Nombre del Hotel" << endl;
       getline(cin,nombreHotel);
  return nombreHotel;
}

int Hotel::getCedula()
{
	
        return cedula;
}

void Hotel::setNombreHotel()
{
        
	this->nombreHotel = nombreHotel;
}

void Hotel::setCedula()
{
	this->cedula = cedula;
}

// metodo de lectura

void Hotel::IngresarDatos()
{	
	Hotel a;
	Fecha b;
	cout << " ***registro de hotel*** " << endl;
        cout << "ingrese nombre del hotel " << endl;
	getline(cin,a.nombreHotel); // funcion para leer frases
	cout << "ingrese dia de creacion" << endl;
	cin >> b.dia;
	cout << "ingrese mes  " << endl;
	cin >> b.mes;
	cout << "ingrese anio " << endl;
	cin >> b.anio;
	cout << "ingrese ciudad " << endl;
        cin.ignore(); // Linea para que no se salte los datos
	getline(cin,a.ciudad);
	cout << "ingrese la direccion " << endl;
	getline(cin,a.direccion);  
	cout << "ingrese nombre del gerente " << endl;
	cin >> a.nombreGerente;
	cout << "apellido  " << endl; 
	cin >> a.apellidoGerente;
	cout << "cedula " << endl;
	cin >> a.cedula;
	
	// paso valores a los atributos
	
	nombreHotel = a.nombreHotel;
	fecha_creacion = b;
	ciudad = a.ciudad;
	direccion = a.direccion;
	nombreGerente = a.nombreGerente;
	apellidoGerente = a.apellidoGerente;
	cedula = a.cedula;
	
}

// metodo mostrar

void Hotel::mostrar()
{	
	cout << "nombre hotel: " << nombreHotel << endl;
	cout << "fecha de creacion : " << "(" << fecha_creacion.dia << "/" << fecha_creacion.mes << "/" << fecha_creacion.anio << ")" << endl;
	cout << "ciudad: " << ciudad << endl;
	cout << "direccion: " << direccion << endl;
	cout << "nombre del gerente: " << nombreGerente << endl;
	cout << "apellido: " << apellidoGerente << endl;
	cout << "cedula: " << cedula << endl;
}
