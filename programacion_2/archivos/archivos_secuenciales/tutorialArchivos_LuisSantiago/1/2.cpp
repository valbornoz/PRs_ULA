/*
Luis Santiago 21.181.829
Universidad De Los Andes
-------------------------Como abrir un archivo con un nombre obtenido por teclado(solo si el archivo existe)
*/
#include <fstream>
#include <iostream>

using namespace std;

int main(){

	ifstream archivo;		//declarar un manejador de archivo lectura;
	string nombre;			
	
	getline(cin,nombre);		
	archivo.open(nombre.c_str());	//se abre el archivo con nombre obtenido por teclado(lo abre solamente si ya existe)
	archivo.close();
	return (0);
}
