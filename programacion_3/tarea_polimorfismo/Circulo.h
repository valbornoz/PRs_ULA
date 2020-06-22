
#include <iostream>
#include "Figura.h"

using namespace std;

class Circulo : public Figura{

	private:

	float radio;

	public:

	Circulo();
	Circulo(float r);
	Circulo(const Circulo &);

	void setradio(float r);	
	float getradio();
	virtual float calcular_area();

	~Circulo();

};

Circulo::Circulo(){
	radio=0;
}

Circulo::Circulo(float r){
	radio=r;
}

Circulo::Circulo(const Circulo &c){
	this->radio=c.radio;
}

Circulo::~Circulo(){
}

void Circulo::setradio(float r){
	radio=r;
}

float Circulo::getradio(){
	return radio;
}

float Circulo::calcular_area(){
	float area;

	area=radio*radio*3.141592654;

	return area;
}


