#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(){
	
	ifstream entrada;
	ofstream aux;
	string cadena;
	int cont=0;
	entrada.open("Usuarios.txt");
	aux.open("copia.txt");

	if(!entrada.fail() && !aux.fail()){
		while(!entrada.eof()){
			getline(entrada,cadena);
			if(entrada.fail()){
				break;
			}	
			aux << cadena << endl;
			cont++;	
		}

		cout << "Introduzca el nombre de nuevo usuario"<<endl;
		getline(cin,cadena);
		aux << cont <<"/"<< cadena<< endl;
	
		entrada.close();
		aux.close();

		ifstream entrada1;
		ofstream aux1;

		entrada1.open("copia.txt");
		aux1.open("Usuarios.txt");

		if(!entrada1.fail() && !aux1.fail()){
			while(!entrada1.eof()){
				getline(entrada1,cadena);
				if(entrada1.fail()){
				break;
				}	
			aux1 << cadena <<endl;	
			}
		}
	entrada1.close();
	aux1.close();

	}else{
		cout << "Error en la apertura de los archivos"<<endl;
	}


	return 0;
}
