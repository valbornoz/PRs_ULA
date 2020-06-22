/*Luis Santiago 21.181.829
  Universidad de los Andes
*/
#include "temp.h"
temp::temp(){};

temp::~temp(){};

int temp::verCodigo(){
	this->archivo.open("temp.dat",std::ios_base::in | std::ios::binary);	//abrimos el archivo en modo binario y modo lectura
	if(this->archivo.bad()){return 1;}					//verificamos la apertura exitosa
	this->archivo.read((char*)&this->codigo,sizeof(int));//read(char* s, streamsize n) hacemos casting sobre el atributo e indicamos tamamo del bloque
	this->archivo.close();
	return this->codigo;
}
void temp::cambiarCodigo(int codigo){
	this->archivo.open("temp.dat",std::ios_base::out | std::ios::binary);  //abrimos el archivo en modo binario y modo lectura
	if(!this->archivo.good()){return;}					//verificamos la apertura exitosa
	this->archivo.write((char*)&codigo,sizeof(int));//write(char* s, streamsize n) hacemos casting sobre el atributo e indicamos tamamo del bloque
	this->archivo.close();
}
