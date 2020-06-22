//******************************************************************
//
// Luis Santiago 2011
// 21.181.829	   	
// Clase claseInventario 
/*******************************************************************/
#ifndef INVENTARIO_h
#define INVENTARIO_h
#include <iostream>
#include <fstream>

class claseInventario{
private:
	std::fstream inventario;
	std::string descripcion;
        std::string codigo;
        std::string stock;
        std::string precio;
public:
	std::string verDescripcion(int);
        std::string verCodigo(int);
        std::string verStock(int);
        std::string verPrecio(int);
	void cambiarDescripcion(std::string,int);
	void cambiarCodigo(std::string,int);
	void cambiarStock(std::string,int);
	void cambiarPrecio(std::string,int);
	
};
#endif
