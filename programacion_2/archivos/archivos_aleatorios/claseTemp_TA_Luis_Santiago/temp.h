/*Luis Santiago 21.181.829
  Universidad de los Andes
*/
#ifndef TEMP_h
#define TEMP_h
#include <iostream>
#include <fstream>

class temp{
private:
	std::fstream archivo; //manejador de archivo
	int codigo;		//codigo a escribir en el archivo no texto
public:
	temp();
	~temp();
	int verCodigo();
	void cambiarCodigo(int);

};
#endif
