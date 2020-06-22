# ifndef FIGURA_H
# define FIGURA_H

#include <iostream>

using namespace std;

class Figura{

	public:

	Figura();

	virtual float calcular_area() = 0;

	~Figura();

};

Figura::Figura(){
}

Figura::~Figura(){
}

//float Figura::calcular_area(){
//}

#endif
