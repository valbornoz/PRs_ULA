/******************************************************************************/
/*       Implantación del TDA Archivo Secuencial Paramétrico                  */
/******************************************************************************/
#include<iostream.h>
#include<string.h>
#include <fstream.h>
#include <iomanip.h>
#include <stdio.h>

// Es una implantación Paramétrica

template <class T> class archivo_sec {

	char *nombre;
	fstream file;

public:

	   archivo_sec(void);
	   archivo_sec(char *);
	   ~archivo_sec();
	   char *get_nombre() { return nombre; }
	   void asigna_nombre(char *);
	   int cerrar();
	   int crear(char *);
	   int abrir(int);
	   int renombrar(const char *);
	   int remover(char*);
	   T& escribir(T &);
	   T& leer(T &);
	   void insertar( T &);
	   int eliminar(archivo_sec&,T &);
};

/******************************************************************************/
/*       Implantación de los métodos del  TDA Archivo Secuencial Paramétrico                             */
/******************************************************************************/

// Es una implantación Paramétrica

template <class T> archivo_sec<T>::archivo_sec(void) {
	char *x="prueba.dat";
	strcpy ( nombre = new char [strlen(x)+1], x);
}

template <class T> archivo_sec<T>::archivo_sec(char *a) {
	
	strcpy( nombre = new char [strlen(a)+1], a);
}

template <class T> archivo_sec<T>::~archivo_sec() {

	delete [] nombre;
}

template <class T> void archivo_sec<T> :: asigna_nombre(char *b) {

	strcpy(nombre=new char[strlen(b) + 1],b);

}

template <class T> int archivo_sec<T> :: cerrar(){

	file.close();
    return(!file.fail());
}


template <class T> int archivo_sec<T> :: abrir(int modo){

	file.open(nombre , modo );
	return(!file.fail());
}

template <class T> int archivo_sec<T> :: crear(char *a){

	asigna_nombre(a);
	file.open(a ,ios :: out | ios::app);
	return (!file.fail());
}


template <class T> int archivo_sec<T> :: renombrar(const char *a){

	return (rename(nombre,a)); 
}

template <class T> int archivo_sec<T> :: remover(char* name){

	return (remove(name)); 
}

template <class T> T& archivo_sec<T> :: leer(T &p){

	file>>p;
	return (p);
}

template <class T> T& archivo_sec<T> :: escribir(T &p){

	file<<p;
	return (p);
}
	

template <class T> void archivo_sec<T> :: insertar(T &ins){
	cout << "entre\n";
	T reg;
	archivo_sec aux;
	file.open(nombre, ios::in);
	aux.crear("aux.dat");
	file>>reg;
	while(reg<ins && !file.eof()){
		aux.escribir(reg);
		file>>reg;
	}

	aux.escribir(ins);
	while(!file.eof()){
		aux.escribir(reg);
		file>>reg;
	}

	file.close();
	aux.cerrar();
	char *x= new char[30];
	strcpy(x,nombre);
	remove(nombre);
	aux.renombrar(x);
	
}

template <class T> int archivo_sec<T> :: eliminar(archivo_sec& aux,T &elim){
	
	T reg;
	int encontrado = 0;
	archivo_sec aux("aux");
	file.open(nombre,ios::in);
	aux.abrir(ios::out);
	file>>reg;
	while(!file.eof()){
		if(reg==elim)
			file>>reg;
			encontrado = 1;
		else{
			aux.escribir(reg);
			file>>reg;
		}
	}

	file.close();
	aux.cerrar();
	char *x= new char[30];
	strcpy(x,nombre);
    remove(nombre);
	aux.renombrar(x);
	return(encontrado);
}


