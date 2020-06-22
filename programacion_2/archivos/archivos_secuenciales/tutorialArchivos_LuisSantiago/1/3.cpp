/*
Luis Santiago 21.181.829
Universidad De Los Andes
--------------Como abrir un archivo con un nombre obtenido por teclado(solo si el archivo existe) y comprobar el enlace al archivo
*/
#include <fstream>
#include <iostream>

using namespace std;

int main(){

	ifstream archivo;
	string nombre;
	
	getline(cin,nombre);	
	archivo.open(nombre.c_str());
	if(!archivo.good()){			//good() retorna un bool true si se enlazo correctamente el archivo;lo contrario de bad()
		cerr<<"el archivo no pudo abrirse\n";
		return 0;
	}
	else{
		cerr<<"el archivo fue abierto\n";
	}
	archivo.close();
	return (0);
}
