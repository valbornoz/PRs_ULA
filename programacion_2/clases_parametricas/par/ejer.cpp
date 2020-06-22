#include <iostream>
#include "Par.h"


int main() {
	Par<int> par1;
	par1.setPrimero(5);
	par1.setSegundo(10);
	par1.mostrarPar();

	Par<float> *par2 = new Par<float>(3.4, 7.8);
	par2->mostrarPar();
	delete par2;
}
