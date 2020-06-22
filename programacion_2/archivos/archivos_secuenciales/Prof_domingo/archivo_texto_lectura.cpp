#include <iostream.h>
#include <fstream.h>
void main() {
	ifstream archivo_inv("Inventario.dat");
	if (!archivo_inv) 
	   cout << " No se puede aperturar el archivo inventario";	
	else {
		char articulo[20],costo[20];
	
		while (!archivo_inv.eof()) {
			archivo_inv >> articulo >> costo;
			cout << articulo << " " << costo << "\n";
		}
		archivo_inv.close();
	}

}
