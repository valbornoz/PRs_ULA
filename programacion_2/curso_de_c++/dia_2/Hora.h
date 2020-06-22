#ifndef HORA_H
#define HORA_H

#include <iostream>
using namespace std;

class Hora 
{
	private:
		int hora;
		int minutos;
		int segundos;

	public:
		//constructor
		Hora();
		//destructor
		~Hora();
		//metodos de acceso
		int ver_hora();
		int ver_minutos();
		int ver_segundos();
		//metodos de modificacion
		void asignar_hora(int h);
		void asignar_minutos(int m);
		void asignar_segundos(int s);
		//otros
		void imprimir_hora();
		int obtener_segundos_hora();
		//operador << imprimir por pantalla
		friend ostream & operator << (ostream &salida, const Hora &h);
		friend Hora  operator + (const Hora &h1,const Hora &h2);
		friend bool operator == (const Hora &h1,const Hora &h2);
		Hora &  operator = (const Hora &h1);
		friend void operator >> (istream &entrada, const Hora &h);
		

};

//constructor
Hora::Hora()
{
	hora = 0;
	minutos = 0;
	segundos = 0;
}
//destructor
Hora::~Hora()
{
}

//metodos de acceso
int Hora::ver_hora()
{
	return hora;
}
int Hora::ver_minutos()
{
	return minutos;
}
int Hora::ver_segundos()
{
	return segundos;
}

//metodos de modificacion

void Hora::asignar_hora(int h)
{
	if(h>23 || h<0)
	{
		hora = 0;
	}
	else
	{
		hora = h;
	}
}

void Hora::asignar_minutos(int m)
{
	if(m>59 || m<0)
	{
		minutos = 0;
	}
	else
	{
		minutos = m;
	}
}

void Hora::asignar_segundos(int s)
{
	if(s>60 || s<0)
	{
		segundos = 0;
	}
	else
	{
		segundos = s;
	}
}
void Hora::imprimir_hora()
{
	cout << hora <<":"<<minutos<<":"<<segundos <<endl;
}

int Hora::obtener_segundos_hora()
{
	return (hora*3600 + minutos*60 + segundos);
}

//operador <<
ostream & operator << (ostream &salida, const Hora &h)
{
	salida<<h.hora<<":"<<h.minutos<<":"<<h.segundos;
	return salida;
}
Hora operator + (const Hora &h1,const Hora &h2)
{

	//variable auxiliar
	Hora aux;

	//segundos
	aux.segundos = h1.segundos + h2.segundos;
	
	if(aux.segundos>59)
	{
		int resto = aux.segundos - 60;;
		aux.segundos = resto;
		
		aux.minutos = h1.minutos + h2.minutos +1;
		
		if(aux.minutos>59)
		{
			int r = aux.minutos - 60;
			aux.minutos = r;
			aux.hora = h1.hora +h2.hora + 1;	
			
			if(aux.hora >23)
			{
				aux.hora = 0;
			}
		}
		else
		{
			aux.hora = h1.hora +h2.hora;	
			
			if(aux.hora >23)
			{
				aux.hora = 0;
			}
		}
	}
	else
	{
		aux.minutos = h1.minutos + h2.minutos;
		
		if(aux.minutos>59)
		{
			int r = aux.minutos - 60;
			aux.minutos = r;
			aux.hora = h1.hora +h2.hora + 1;	
			
			if(aux.hora >23)
			{
				int re = aux.hora -24;
				aux.hora = re;
			}
		}
		else
		{
			aux.hora = h1.hora +h2.hora;	
			
			if(aux.hora >23)
			{
				int re = aux.hora -24;
				aux.hora = re;
			}
		}
	}

	return aux;

}
bool operator == (const Hora &h1,const Hora &h2)
{
	if(h1.hora == h2.hora && h1.minutos == h2.minutos && h1.segundos == h2.segundos)
	{
		return true;
	}
	else
	{
		return false;
	}
}
Hora &  Hora::operator = (const Hora &h1)
{
	hora = h1.hora;
	minutos = h1.minutos;
	segundos = h1.segundos;
	return *this;
}
void operator >> (istream &entrada, Hora &h)
{

	int ho,min,seg;
	cout << "Hora: ";
	cin>>ho;
	cout << "Minutos: ";
	cin>>min;
	cout << "Segundos: ";
	cin>>seg;
	
	h.asignar_hora(ho);
	h.asignar_minutos(min);
	h.asignar_segundos(seg);

}

#endif




