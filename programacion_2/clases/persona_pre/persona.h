#ifndef PERSONA_H
#define PERSONA_H
#include<iostream>

class Persona{

	private:
	/* Atributos */
	int Edad;
	bool Sexo;
	float Sueldo;
	
	/* Metodos */
	public:
	int verEdad();
	void asignarEdad(int);
	bool verSexo();
	void asignarSexo(bool);
	float verSueldo();
	void asignarSueldo(float);
	
	/* Constructores */			
	
		// Por defecto
	Persona();
	
		// Por parametro
	Persona(int,bool,float);

		// Por copia
	Persona(const Persona &);

	/* Destructor */

	~Persona();

};

#endif
