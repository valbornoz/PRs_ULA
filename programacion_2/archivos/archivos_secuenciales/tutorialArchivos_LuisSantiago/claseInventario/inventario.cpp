//****************************************************************************
//
// Luis Santiago 2011
// 21.181.829		   	
// Definicion de Clase claseInventario

/*****************************************************************************/
#include "inventario.h"
#include <cstdlib>
#include<iomanip>

std::string claseInventario::verDescripcion(int posicion){
        this->descripcion="";					
	this->inventario.open("inventario.txt",std::ios_base::in );//abrimos el archivo modo lectura 
	if(!this->inventario.good()){return this->descripcion;} //verificamos "buena conexion"
	std::string descrip, cod, stck, prec;			//declaracion de variables auxiliares para ir iterando sobre el archivo
	for(int i=0;i<=posicion;i++){
		std::getline(this->inventario,descrip,';');	//leemos cada bloque hasta el ; lo almacenamos
		std::getline(this->inventario,cod,';');		//hasta el numero de linea "posicion" donde se rompe el ciclo y 
		std::getline(this->inventario,stck,';');	//tendremos en las variables auxiliares las cadenas a buscar
		std::getline(this->inventario,prec,'\n');	
		if(this->inventario.fail())			
			break;
	}
	this->inventario.close();				//cerramos el archivo
	this->descripcion=descrip;				
	return this->descripcion;				//retornamos la descripcion
}
std::string claseInventario::verCodigo(int posicion){
        this->codigo="";
	this->inventario.open("inventario.txt",std::ios_base::in );
	if(!this->inventario.good()){return this->codigo;}
	std::string descrip, cod, stck, prec;
	for(int i=0;i<=posicion;i++){
		std::getline(this->inventario,descrip,';');
		std::getline(this->inventario,cod,';');
		std::getline(this->inventario,stck,';');
		std::getline(this->inventario,prec,'\n');
		this->codigo=atoi(cod.c_str());
		if(this->inventario.fail())
			break;
	}
        this->codigo=cod;
	this->inventario.close();
	return this->codigo;	
}
std::string claseInventario::verStock(int posicion){
        this->stock="";
	this->inventario.open("inventario.txt",std::ios_base::in );
	if(!this->inventario.good()){return this->codigo;}
	std::string descrip, cod, stck, prec;
	for(int i=0;i<=posicion;i++){
		std::getline(this->inventario,descrip,';');
		std::getline(this->inventario,cod,';');
		std::getline(this->inventario,stck,';');
		std::getline(this->inventario,prec,'\n');
		if(this->inventario.fail())
			break;
	}
	this->inventario.close();
        this->stock=stck;
	return this->stock;
}
std::string claseInventario::verPrecio(int posicion){
        this->precio="";
	this->inventario.open("inventario.txt",std::ios_base::in);
	if(!this->inventario.good()){return this->precio;}
	std::string descrip, cod, stck, prec;
	for(int i=0;i<=posicion;i++){
		std::getline(this->inventario,descrip,';');
		std::getline(this->inventario,cod,';');
		std::getline(this->inventario,stck,';');
		std::getline(this->inventario,prec,'\n');
		if(this->inventario.fail())
			break;
	}
	this->inventario.close();
        this->precio=prec;
	return this->precio;

}
void claseInventario::cambiarDescripcion(std::string descripcion,int posicion){	
	this->inventario.open("inventario.txt",std::ios_base::out | std::ios_base::in);//abrimos el archivo 
	if(!this->inventario.good()){std::cout<<"error";return ;}			//verificamos apertura correcta
	this->inventario.seekp(posicion*(40*sizeof(char)));//posicionamos el puntero en la linea correcta saltandonos posicion veces la longitud de cada 								     linea
	this->inventario<<std::setw(20)<<std::setfill(' ')<<descripcion.substr (0,20)<<';';//ajustamos la escritura para conservar el formato del archivo
	this->inventario.close();
}
void claseInventario::cambiarCodigo(std::string codigo,int posicion){
	this->inventario.open("inventario.txt",std::ios_base::out | std::ios_base::in);
	if(!this->inventario.good()){std::cout<<"error";return ;}
	int x=atof(codigo.c_str());
	this->inventario.seekp((posicion*(40*sizeof(char)))+(21*sizeof(char)));	//posicionamos el puntero en la linea correcta saltandonos posicion veces 											la longitud de cada linea y el atributo anterior que media 20 posiciones 											char + el separador
	this->inventario<<std::setw(5)<<std::setfill(' ')<<x<<';';
	this->inventario.close();
}
void claseInventario::cambiarStock(std::string stock,int posicion){
	this->inventario.open("inventario.txt",std::ios_base::out | std::ios_base::in);
	if(!this->inventario.good()){std::cout<<"error";return ;}
	int x=atof(stock.c_str());
	this->inventario.seekp((posicion*(40*sizeof(char)))+(27*sizeof(char)));	
	this->inventario<<std::setw(5)<<std::setfill(' ')<<x<<';';
	this->inventario.close();
}
void claseInventario::cambiarPrecio(std::string precio,int posicion){
	this->inventario.open("inventario.txt",std::ios_base::out | std::ios_base::in);
	if(!this->inventario.good()){std::cout<<"error";return ;}
	float x=atof(precio.c_str());
	this->inventario.seekp((posicion*(40*sizeof(char)))+(33*sizeof(char)));	
	this->inventario<<std::fixed<<std::setw(6)<<std::setprecision(2)<<x<<"\n";
	this->inventario.close();
}

