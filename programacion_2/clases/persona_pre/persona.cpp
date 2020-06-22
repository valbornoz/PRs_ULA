#include"persona.h"

	/* Definicion de la clase persona */

	/* Contructores */

	// por defecto

Persona::Persona(){
	this->Edad = 0;
	this->Sexo = false;
	this->Sueldo = 0;
}
	
	// por parametros

Persona::Persona(int Edad, bool b, float c){
	if (Edad > 0){
		this->Edad = Edad;	
	}else{
		std::cout<<"Error al introducir la edad"<<std::endl; 
		this->Edad = 0;
	}	
	this->Sexo = b;
	this->Sueldo = c;
}

	// por copia

Persona::Persona(const Persona &p){
	this->Edad = p.Edad;
	this->Sexo = p.Sexo;
	this->Sueldo = p.Sueldo;
}

	/*Observadores Modificadores*/

	int Persona::verEdad(){
		return (this->Edad);
	}

	void Persona::asignarEdad(int e){
		this->Edad = e;
	}

	bool Persona::verSexo(){
		return (this->Sexo);
	}

	void Persona::asignarSexo(bool s){
		this->Sexo= s;		
	}

	float Persona::verSueldo(){
		return(this->Sueldo);
	}

	void Persona::asignarSueldo(float s){
		this->Sueldo = s;
	}

	// Destructor

	Persona::~Persona(){
		
	}
