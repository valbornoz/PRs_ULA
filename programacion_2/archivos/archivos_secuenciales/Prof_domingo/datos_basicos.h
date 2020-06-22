// Ejemplo que muestra la especificaci�n de una clase.

#include<iostream.h>
#include<string.h>

/**************************************************************/
// Especficaci�n de la clase Persona con datos  B�sicos.........
/**************************************************************/

class  persona  {
	char  	 *nombre, *apellido, *cedula;
	char	 *direccion;

   /* definici�n de las funciones Miembros */

	public:     /* palabra reservada, de aqu� en adelante todo es p�blico */
	persona(void);
	persona(char *, char *, char *, char *, char *, char *, char *, char *);
	void asigna_nombre(char *nombre_nuevo);
	void asigna_apellido(char *apellido_nuevo);
	void asigna_cedula(char *cedula_nueva);
	void asigna_direccion(char  *direccion_nueva);
	const char * obtener_nombre( )const {return nombre;}
	const char * obtener_cedula( ) const {return cedula;}
	const char * obtener_apellido( )const {return apellido;}
	const char * obtener_direccion( ) const {return direccion;}
	friend void operator<<(ostream &s,const persona &p);
	friend void operator>>(istream &e,persona &p);
	int operator < (const persona &p);
	persona& persona::operator=(persona &p);
	~persona(void);

};

