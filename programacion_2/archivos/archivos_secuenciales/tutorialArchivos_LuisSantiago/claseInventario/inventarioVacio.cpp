#include <iostream>
#include <fstream>
#include<string>
#include<iomanip>

int main(){
	std::ofstream archivo;
	std::string descripcion="nombre del producto.";
	int stock=0,codigo=-1;
	float precio=0.0;
	
	archivo.open("inventario.txt");
	for(int i=0;i<1000;i++){
		archivo<<std::setw(20)<<std::setfill(' ')<<descripcion<<";";
		archivo<<std::setw(5)<<std::setfill(' ')<<codigo<<";";
		archivo<<std::setw(5)<<std::setfill(' ')<<stock<<";";
		archivo<<std::fixed<<std::setw(6)<<std::setprecision(2)<<precio<<"\n";
	}
	archivo.close();
}
