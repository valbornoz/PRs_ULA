#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string>

using namespace std;

int main(){

	string nombre, apellido,aux, cad1, cad2, edadC, sueldoC, cedulaC;
	int edad, cedula;
	float sueldo=0, sueldoT=0;

	ifstream entrada;
	ofstream salida;
	entrada.open("entrada.txt");
	if(!entrada.good()){
		cout<< "Error al aperturar el archivo"<<endl;
	}else{

		while(getline(entrada,aux,',') and getline(entrada,aux,',') and getline(entrada,aux,',') and getline(entrada,aux,',') and getline(entrada,aux) and !entrada.eof()){
				
			sueldo = atof(aux.c_str());
			sueldoT += sueldo;
		}

		cout << "El monto total a pagar este mes es: " << sueldoT << endl;
	}
	entrada.close();
	
	// otro programa cambia una columna

	entrada.open("entrada.txt");
	salida.open("salida.txt");

	if(!entrada.good() and !salida.good()){
		cout<< "Error al aperturar los archivos"<<endl;
	}else{

		while(getline(entrada,nombre,',') and getline(entrada,apellido,',') and getline(entrada,cedulaC,',') and getline(entrada,edadC,',') and getline(entrada,sueldoC) and !entrada.eof()){
				
			salida << cedulaC << "," << nombre << "," << apellido << "," << edadC << "," << sueldoC << endl;
		}

	}

	entrada.close();
	salida.close();

	// otro programa que muestra en el archivo de salida los mayores de 19 años

	entrada.open("entrada.txt");
	ofstream salida2;	
	salida2.open("salida2.txt");

	if(!entrada.good() and !salida2.good()){
		cout<< "Error al aperturar los archivos"<<endl;
	}else{

		while(getline(entrada,nombre,',') and getline(entrada,apellido,',') and getline(entrada,cedulaC,',') and getline(entrada,edadC,',') and getline(entrada,sueldoC) and !entrada.eof()){
		
		edad = atoi(edadC.c_str());
	
		if(edad >= 20){
			salida2  << nombre << "," << apellido << "," << cedulaC << "," << edadC << "," << sueldoC << endl;
		}
		
		}

	}

	entrada.close();
	salida2.close();

	// Palindro (incompleto error con los if )

	int largo, j;
	entrada.open("entrada2.txt");
	salida.open("salida3.txt");
	
	if(!entrada.good() and !salida.good()){
		cout << "Error al procesar los archivos"<<endl;
	}else{
		while(getline(entrada,cad1,',') and getline(entrada,cad2,',') and !entrada.eof()){
			
			largo = cad1.length();
		if(cad1.size() == cad2.size()){
			j = largo -1;
			for( int i=0; i<largo ; i++){
				if (cad1[i]==cad2[j]){
					if(i==largo-1){
						salida << cad1 << " " << cad2 << endl;
					}
				}else{
					break;
				}
			j--;
			}
		}
		}	
	}

	entrada.close();
	salida.close();
	return 0;
}
