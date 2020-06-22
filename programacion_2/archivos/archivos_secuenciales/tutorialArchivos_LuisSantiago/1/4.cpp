/*
Luis Santiago 21.181.829
Universidad De Los Andes
-------------------------Como abrir un archivo con un nombre obtenido por teclado(solo si el archivo existe)
*/
#include <fstream>
#include <iostream>

using namespace std;

int main(){

	ifstream archivo;
	string nombre,texto;
	
	//getline(cin,nombre);	
	archivo.open(/*nombre.c_str()*/"./texto");
	if(!archivo.good()){
		cerr<<"el archivo no pudo abrirse\n";
		
		return 0;
	}
	else{
		cerr<<"el archivo fue abierto\n";
	}

	while(!archivo.eof()){
		getline(archivo,texto);
		if(archivo.fail()){	//para que no escriba la ultima linea en blanco		
			archivo.close();
			return 1;
		}
		cout<<texto<<"\n";
	}

	archivo.close();
	return (0);
}
