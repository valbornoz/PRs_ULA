//******************************************************************
//
// Luis Santiago 2011
// 21.181.829	   	
// Prueba Clase claseInventario 
/*******************************************************************/

#include <inventario.h>

int main(){
	int x=0;
	claseInventario almacen;
	std::string p="crema dental colgate 500mg",s="sal al gusto";
	std::cout<<almacen.verDescripcion(x)<<" "<<almacen.verCodigo(x)<<" "<<almacen.verStock(x)<<" "<<almacen.verPrecio(x)<<"\n";
	std::cout<<almacen.verDescripcion(3)<<" "<<almacen.verCodigo(3)<<" "<<almacen.verStock(3)<<" "<<almacen.verPrecio(3)<<"\n";
	std::string precio,stock,codigo,descripcion;
	std::cout<<"descripcion ";
	getline(std::cin,descripcion);
	std::cout<<"codigo ";
	std::cin>>codigo;
	std::cout<<"precio ";
	std::cin>>precio;
	std::cout<<"stock ";
	std::cin>>stock;
	almacen.cambiarDescripcion(descripcion,x);
	almacen.cambiarCodigo(codigo,x);
	almacen.cambiarStock(stock,x);
	almacen.cambiarPrecio(precio,x);
	std::cout<<almacen.verDescripcion(x)<<" "<<almacen.verCodigo(x)<<" "<<almacen.verStock(x)<<" "<<almacen.verPrecio(x)<<"\n";
	std::cout<<almacen.verDescripcion(3)<<" "<<almacen.verCodigo(3)<<" "<<almacen.verStock(3)<<" "<<almacen.verPrecio(3)<<"\n";
	return 0;
}
