// circulo.cpp

# include "circulo.h"

circulo::circulo() {
	r = 0;
}

void circulo::establecer_r(int R) {
	r = R;
}

int circulo::obtener_r() const {
	return r;
}

void circulo::imprimir() {
	cout << " Circulo con:\n"
	     << " Centro en (" << c.obtener_x() << ";" << c.obtener_y() << ")\n"
	     << " Radio: " << r << endl << endl
	     << " Nombre: " << nombre << endl << endl;
}
