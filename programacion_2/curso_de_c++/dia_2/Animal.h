#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>

using namespace std;

class Animal
{
	private:
		int tipo;
	public:
		Animal();
		~Animal();
		int ver_tipo();
		void asignar_tipo(int t);
		virtual void imprimir_info() = 0;
};
Animal::Animal()
{
	tipo = -1;
}
Animal::~Animal()
{
}
int Animal::ver_tipo()
{
	return tipo;
}
void Animal::asignar_tipo(int t)
{
	tipo = t;
}



#endif
