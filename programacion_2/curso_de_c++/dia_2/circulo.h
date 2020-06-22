// circulo.h
// hereda de figura
// se compone de punto

# ifndef CIRCULO_H
# define CIRCULO_H

# include "figura.h"
# include "punto.h"

using namespace std;

class circulo : public figura {

private:
	punto c; // centro
	int r;   // radio
public:
	circulo();

	
	void establecer_r(int);
	void establecer_x(int X){
		c.establecer_x(X);
	}
	int obtener_r() const;
	int obtener_x() const {
		return c.obtener_x();
	}
	
	virtual void imprimir();
	
	~circulo(){};
};		

#endif











