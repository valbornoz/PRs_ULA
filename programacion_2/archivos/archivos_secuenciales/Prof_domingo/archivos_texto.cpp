#include <iostream.h>
#include <fstream.h>
void main() {
	ofstream archivo_inv("Inventario.dat");
	if (!archivo_inv)
	   cout << "No se puede aperturar el archivo inventario";	
	else{
	   archivo_inv << "Radios" << " " << "19.000,95" << "\n";
	   archivo_inv << "Tostadoras" << " " << "20.000,95"  << "\n";
	   archivo_inv << "Lavadoras" << " " << "50.000,00";
	   archivo_inv.close();
	}
}
