// figura.cpp

# include "figura.h"

void figura::establecer_nombre(string n) {
	nombre = n;
}

string figura::obtener_nombre() const {
	return nombre;
}
