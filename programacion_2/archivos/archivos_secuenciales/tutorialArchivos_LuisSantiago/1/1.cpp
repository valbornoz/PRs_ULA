/*
Luis Santiago 21.181.829
Universidad De Los Andes
----------------------------------Como crear un archivo y asignarle el nombre obtenido por teclado
*/

#include <fstream>			// biblioteca de manejadores de archivos
#include <string>
#include <iostream>
using namespace std;
int main(){

	ofstream archivo;//declaracion de ofstream manejador de archivo escritura
	string linea;	//cadena que almacena el nombre que le vamos a asignar al archivo que vamos a crear
	//cin>>linea;			//recibe por teclado el nombre que se le asignara al archivo, pero solo la primera palabra
	getline(cin,linea);		//recibe por teclado el nombre que se le asignara al archivo (la linea completa)
	archivo.open(linea.c_str());	//se abre el archivo con el nombre que le asignamos(convirtiendo linea de tipo string a char *), si no existe lo crea.
	archivo<<"hola mundo"<<endl;
	archivo.close();		//cerramos el archivo

	return 0;
}


//como crear un archivo 
/*	archivo.open("./archivo1.txt");	abrimos un archivo con un nombre asignado directamente
	getline(cin,linea);		almacenamos una linea ingresada por teclado en un string "linea".	
	archivo<<linea;			guardamos en el archivo abierto "archivo1.txt" lo que hay almacenado en "linea"
	archivo.close();
*/
