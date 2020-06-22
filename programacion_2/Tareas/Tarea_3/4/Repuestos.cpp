#include "Repuestos.h"

using namespace std;

Repuestos::Repuestos(){
	codigo=0;
}

Repuestos::Repuestos(int c){
	codigo=c;
}

Repuestos::~Repuestos(){
}

void Repuestos::asignar_codigo(int c){
	codigo=c;
}

int Repuestos::ver_codigo(){
	return codigo;
}

void Repuestos::Depurar(int codi){

	string nombre, marca, modelo, anio, dato;
	ofstream escri;
	ifstream leer;

	leer.open("aux.txt");
	if(!leer){
		cout<<"ERROR al abrir el archivo aux!"<<endl;
	}
	else{

	escri.open("duplicado.txt",ios::app);

		if(!escri){
			cout<<"ERROR al abrir el archivo clientes!"<<endl;
		}
		else{
		
			while(getline(leer,nombre,'~') and getline(leer,marca,'~') and getline(leer,modelo,'~') and  getline(leer,dato,'~') and  getline(leer,anio)){
				int a;
				a=atoi(dato.c_str());
				if(codi==a){
					escri<<nombre<<"~"<<marca<<"~"<<modelo<<"~"<<dato<<"~"<<anio<<endl;
				}

			}
		}
		escri.close();

	leer.close();
	}

}


