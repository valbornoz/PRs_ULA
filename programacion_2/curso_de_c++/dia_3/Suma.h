#ifndef SUMA_H
#define SUMA_H

#include <iostream>
using namespace std;

template<class Dato> class Suma
{
	private:
		/*int a,b;
		float c,d;*/
		Dato a;
		Dato b;
	public:
		Suma();
		~Suma();
		Dato sumar();
		void asignar_a(Dato a1);
		void asignar_b(Dato b1);

};

template<class Dato> Suma<Dato>::Suma()
{
}

template<class Dato> Suma<Dato>::~Suma()
{
}

template<class Dato> void Suma<Dato>::asignar_a(Dato a1)
{
	a = a1;
} 

template<class Dato> void Suma<Dato>::asignar_b(Dato b1)
{
	b = b1;
}

template<class Dato> Dato Suma<Dato>::sumar()
{
	//creamos una variable auxiliar
	Dato aux;
	aux = a + b;
	return aux;
}



#endif
