#include <iostream>
#include "Figura.h"

using namespace std;

class Cuadrado : public Figura{

	private:

	float lado;

	public:

	Cuadrado();
	Cuadrado(float l);
	Cuadrado(const Cuadrado &);

	void setlado(float l);
	float getlado();
	virtual float calcular_area();

	~Cuadrado();

};

Cuadrado::Cuadrado(){
	lado=0;
}

Cuadrado::Cuadrado(float l){
	lado=l;
}

Cuadrado::Cuadrado(const Cuadrado &c){
	this->lado=c.lado;
}

Cuadrado::~Cuadrado(){
}

void Cuadrado::setlado(float l){
	lado=l;
}

float Cuadrado::getlado(){
	return lado;
}

float Cuadrado::calcular_area(){
	float area;

	area=lado*lado;

	return area;

}
