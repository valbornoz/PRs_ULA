/*******************************************************************/
/* Ejemplo que muestra la implantación de los métodos de una clase.*/
/*******************************************************************/
#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include"datos_basicos.h"
/*****************************************************************/
// implantación de los métodos de la clase persona básica
/******************************************************************/

persona::persona(void){
       strcpy(nombre=new char [30],"Domingo");
       strcpy(apellido=new char [30],"Hernandez");
       strcpy(cedula=new char [13],"v.-8.333.439");
       strcpy(direccion=new char [80],"Calle 32 ");
}

persona::persona(char *nomb,char *apell, char *ced, char *sex, char *d, char *m, char *a, char *direcc ){
       strcpy(nombre=new char [strlen(nomb)+1],nomb);
       strcpy(apellido=new char [strlen(apell)+1],apell);
       strcpy(cedula=new char [strlen(ced)+1],ced);
       strcpy(direccion=new char [strlen(direcc)+1],direcc);
 }
persona:: ~persona(void){
		delete [] nombre;
		delete [] apellido;
		delete [] cedula;
		delete [] direccion;
		}

void persona::asigna_nombre(char *nombre_nuevo){
	strcpy(nombre=new char [strlen(nombre_nuevo)+1],nombre_nuevo);
}

void persona::asigna_apellido(char *apellido_nuevo){
	strcpy(apellido=new char [strlen(apellido_nuevo)+1],apellido_nuevo);
}

void persona::asigna_cedula(char *cedula_nueva){
	strcpy(cedula=new char [strlen(cedula_nueva)+1],cedula_nueva);
}


void persona::asigna_direccion(char  *direccion_nueva){
	strcpy(direccion=new char [strlen(direccion_nueva)+1],direccion_nueva);
}

// Sobrecarga de los operadores cout y cin

void operator <<(ostream &salida, const persona &p){
	salida << p.obtener_nombre() << " ";
	salida << p.obtener_apellido() << " ";
	salida << p.obtener_cedula() << " ";
	salida << p.obtener_direccion() << "\n";
}

void operator>>(istream &e, persona &p) {
	char nom[30],apell[30],ced[15],dire[50];
	cin >> nom;
	cin >> apell;
	cin >> ced;
	cin>> dire;
	p.asigna_nombre(nom);
	p.asigna_apellido(apell);
	p.asigna_cedula(ced);
	p.asigna_direccion(dire);
}

int persona::operator <(const persona &p){
	if (strcmp(nombre,p.obtener_nombre())<0)
		return 1;
	else
		return 0;
}

persona& persona::operator=(persona &p){
	strcpy(nombre=new char [strlen(p.obtener_nombre())+1],p.obtener_nombre());
    strcpy(apellido=new char [strlen(p.obtener_apellido())+1],p.obtener_apellido());
    strcpy(cedula=new char [strlen(p.obtener_cedula())+1],p.obtener_cedula());
    strcpy(direccion=new char [strlen(p.obtener_direccion())+1],p.obtener_direccion());
	return *this;
}
