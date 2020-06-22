#include <iostream>
#include "pila.h"

int main() {
	Pila<int> p1;
	p1.push(4);
	p1.push(3);
	p1.push(2);
	p1.push(1);
	cout << "Dato : " << p1.tope() << endl;
	p1.pop();
	cout << "Dato : " << p1.tope() << endl;
	p1.pop();
	cout << "Dato : " << p1.tope() << endl;
	p1.pop();
	cout << "Dato : " << p1.tope() << endl;
	p1.pop();
}

