#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

using namespace std;

int main(){

	int buscar, aux1, bandera=0;
	string cad, aux;
	ifstream entrada;

	cout<< "Indique el numero de usuario que desea buscar"<<endl;
	cin>> buscar;
	entrada.open("Usuarios.txt");
	if(!entrada.fail()){	
		while(!entrada.eof()){
			getline(entrada,cad,'/');
			getline(entrada,aux);
			if(entrada.fail()){				
				break;
			}else{
				aux1 = atoi(cad.c_str());
				if(aux1 == buscar){
					cout <<"El usuario es:" << aux << endl;
					bandera = 1;
				}
			}
		}
	if(bandera == 0){
		cout << "El codigo de usuario que busca no existe"<<endl;
	}
	}else{
		cout<< "Error en la apertura de los archivos"<<endl;
	}

	return 0;
}
