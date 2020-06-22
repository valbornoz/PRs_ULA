/*Programa que permite leer desde un archivo texto */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
   ifstream archivo;                //("archivo.txt", ios::in);
   archivo.open("archivo.txt", ios::in);
   string texto;
   
	int i=0;
	
	if(archivo.fail())
		cout << "No se pudo abrir el archivo" << endl;
	else{
		while(!archivo.eof()){
         getline(archivo, texto);
			i=i+1;
			cout << "Parrafo " << i << ": " << texto << endl; //En caso de leer por palabra estariamos imprimiendo la Palabra i.
		}
	}
	cout << endl << "Nro de Parrafos: " << i << endl;
	archivo.close();
	return 0;
}
