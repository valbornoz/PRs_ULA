#include "Automovil.h"

using namespace std;

Automovil::Automovil(){
	numero=0;
	tiempo1=0;
	tiempo2=0;
	tiempo3=0;
	mjrtiempo=0;
}

Automovil::Automovil(int n, float t1, float t2, float t3, float mt){
	numero=n;
	tiempo1=t1;
	tiempo2=t2;
	tiempo3=t3;
	mjrtiempo=mt;
}

Automovil::Automovil(const Automovil &a){
	numero=a.numero;
	tiempo1=a.tiempo1;
	tiempo2=a.tiempo2;
	tiempo3=a.tiempo3;
	mjrtiempo=a.mjrtiempo;
}
	
void Automovil::asignar_numero(int n){
	if(n>0){
	numero=n;
	}
	else{
	numero=0;
	}
}	

void Automovil::asignar_tiempo1(float t1){
	if(t1>0){	
	tiempo1=t1;
	}
	else{
	tiempo1=0;
	}
}	

void Automovil::asignar_tiempo2(float t2){
	if(t2>0){	
	tiempo2=t2;
	}
	else{
	tiempo2=0;
	}
}

void Automovil::asignar_tiempo3(float t3){
	if(t3>0){	
	tiempo3=t3;
	}
	else{
	tiempo3=0;
	}
}

void Automovil::asignar_mjrtiempo(float mt){
	mjrtiempo=mt;
}

int Automovil::ver_numero(){
	return numero;
}
	
float Automovil::ver_tiempo1(){
	return tiempo1;
}
	
float Automovil::ver_tiempo2(){
	return tiempo2;
}
	
float Automovil::ver_tiempo3(){
	return tiempo3;
}
	
float Automovil::ver_mjrtiempo(){
	return mjrtiempo;
}

void Automovil::calcular_MT(){
	mjrtiempo=tiempo1;
	if(mjrtiempo>tiempo2){
		mjrtiempo=tiempo2;
	}
	else{
		if(mjrtiempo>tiempo3){
			mjrtiempo=tiempo3;
		}
	}

	if(mjrtiempo>tiempo3){
		mjrtiempo=tiempo3;
	}

	asignar_mjrtiempo(mjrtiempo);

}

Automovil::~Automovil(){
}


