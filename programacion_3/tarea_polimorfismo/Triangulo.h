#include <iostream>
#include "Figura.h"

using namespace std;

class Triangulo : public Figura{

	private:

	float base;
	float altura;

	public:

	Triangulo();
	Triangulo(float b, float a);
	Triangulo(const Triangulo &);

	void setbase(float b);
	void setaltura(float a);	
	float getbase();
	float getaltura();
	virtual float calcular_area();

	~Triangulo();

};

Triangulo::Triangulo(){
	base=0;
	altura=0;
}

Triangulo::Triangulo(float b, float a){
	base=b;
	altura=a;
}

Triangulo::Triangulo(const Triangulo &t){
	this->base = t.base;
	this->altura = t.altura;
}

Triangulo::~Triangulo(){
}

void Triangulo::setbase(float b){
	base=b;
}

void Triangulo::setaltura(float a){
	altura=a;
}

float Triangulo::getbase(){
	return base;
}

float Triangulo::getaltura(){
	return altura;
}
float Triangulo::calcular_area(){
	float area;

	area=(base*altura)/2;

	return area;
}

