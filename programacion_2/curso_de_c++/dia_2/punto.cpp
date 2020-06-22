// punto.cpp

# include "punto.h"

punto::punto() {
	x = 0;
	y = 0;
}

void punto::establecer_x(int X) {
	x = X;
}

void punto::establecer_y(int Y) {
	y = Y;
}

int punto::obtener_x() const {
	return x;
}

int punto::obtener_y() const {
	return y;
}
