#include <iostream>
#include "string.h"
#include "inmueble.h"

Inmueble::Inmueble() {
   strcpy(estado, "");
   strcpy(municipio, "");
   strcpy(parroquia, "");
   strcpy(direccion, "");
   strcpy(cedulaPropietario, "");
}
Inmueble::Inmueble(char *e, char *m, char *p, char *d, char *cP) {
   strcpy(estado, e);
   strcpy(municipio, m);
   strcpy(parroquia, p);
   strcpy(direccion, d);
   strcpy(cedulaPropietario, cP);
}

void Inmueble::getEstado(char * e) {
   strcpy(e,estado);
}
void Inmueble::setEstado(char * e){
   strcpy(estado,e);
}

void Inmueble::getMunicipio(char * m) {
   strcpy(m,municipio);
}
void Inmueble::setMunicipio(char * m){
   strcpy(municipio, m);
}

void Inmueble::getParroquia(char * p) {
   strcpy(p,parroquia);
}
void Inmueble::setParroquia(char * p){
   strcpy(parroquia, p);
}

void Inmueble::getDireccion(char *d){
   strcpy(d,direccion);
}
void Inmueble::setDireccion(char *d){
   strcpy(direccion, d);
}

void Inmueble::getCedulaPropietario(char *cP){
   strcpy(cP,cedulaPropietario);
}
void Inmueble::setCedulaPropietario(char *cP){
   strcpy(cedulaPropietario, cP);
}

void Inmueble::showAll(){
   cout << endl << "Estado: " << estado << endl;
   cout << "Municipio: " << municipio << endl;
   cout << "Parroquia: " << parroquia << endl;
   cout << "Direccion: " << direccion << endl;
   cout << "Cedula del propietario: " << cedulaPropietario << endl << endl;           
}

