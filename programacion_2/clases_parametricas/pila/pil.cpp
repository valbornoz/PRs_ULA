#include "pila.h"

int main() {
	Pila p1;
	p1.push(4);
	p1 << 8;
	p1 << 20;
	p1 << 1;
	cout << "Dato : " << p1.tope() << endl;
	p1.pop();
	cout << "Dato : " << p1.tope() << endl;
	p1.pop();
	cout << "Dato : " << p1.tope() << endl;
	p1.pop();
	cout << "Dato : " << p1.tope() << endl;
	p1.pop();

}
