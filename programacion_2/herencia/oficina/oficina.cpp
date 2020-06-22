#include <iostream>
#include "string.h"
#include "oficina.h"

Oficina::Oficina():Inmueble() {
   amoblada = 0;
   condicion = 0;
   nroDespachos = 0;
   puestosEstacionamiento = 0;
}

Oficina::Oficina(char *e, char *m, char *p, char *d, char *cP, int am, 
                 int co, int nd, int pe):Inmueble(e,m,p,d,cP) {
   amoblada = am;
   condicion = co;
   nroDespachos = nd;
   puestosEstacionamiento = pe;
}

int Oficina::getAmoblada() {
   return amoblada;
}
void Oficina::setAmoblada(int a) {
   amoblada = a;
}

int Oficina::getCondicion() {
   return condicion;
}
void Oficina::setCondicion(int c) {
   condicion = c;
}

int Oficina::getNroDespachos() {
   return nroDespachos;
}
void Oficina::setNroDespachos(int nd) {
   nroDespachos = nd;
}

int Oficina::getPuestosEstacionamiento() {
   return puestosEstacionamiento;
}
void Oficina::setPuestosEstacionamiento(int pe) {
   puestosEstacionamiento = pe;
}

void Oficina::showAll(){
   cout << "Amoblada = " << amoblada << endl;
   cout << "Condicion = " << condicion << endl;
   cout << "Nro. de despachos = " << nroDespachos << endl;
   cout << "Puestos de estacionamiento = " << puestosEstacionamiento << endl;         
}

