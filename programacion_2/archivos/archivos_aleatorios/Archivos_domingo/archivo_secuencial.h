#include <fstream.h>
#include <iomanip.h>
#include <stdio.h>
#include <string.h>

template <class T> class archivo_sec {

	char *nombre;
	fstream file;

public:

	   archivo_sec();
           archivo_sec(char *);
	   ~archivo_sec();
	   char *get_nombre() { return nombre; }
	   void  asigna_nombre(char *);
	   int cerrar();
         virtual void crear() { file.open(nombre, ios::noreplace | ios::out );     file<<endl; file.close();}
         int fin() { return file.eof(); }
	   int crear(char *);
	   int abrir(int);
	   int renombrar(const char *);
	   int remover(char*);
	   T& escribir(T &);
	   T& leer(T &);
	   int insertar( T &);
         void imprimir();
	   int eliminar(T &);
};


template <class T> archivo_sec<T> :: archivo_sec() {
	char *x="xx.dat";
	strcpy ( nombre = new char [strlen(x)+1], x);
}

template <class T> archivo_sec<T> :: archivo_sec(char *a) {
	
	strcpy( nombre = new char [strlen(a)+1], a);
}

template <class T> archivo_sec<T> :: ~archivo_sec() {

	delete [] nombre;
}

template <class T> void archivo_sec<T> :: asigna_nombre(char *b) {

	strcpy(nombre=new char[strlen(b) + 1],b);

}

template <class T> int archivo_sec<T> :: cerrar(){

	file.close();
    return(!file.fail());
}


template <class T> int archivo_sec<T> :: abrir(int modo){ //a.abrir(ios::out)

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
        file<<endl;
	return (p);
}
template <class T> int archivo_sec<T> :: insertar(T &ins){
	
	T reg;
	archivo_sec<T> aux;
        file.open( nombre , ios::in) ;
	aux.crear("aux.tmp");
        leer(reg);     
      while( reg<ins && !file.eof()) {
 
           aux.escribir(reg);
           leer(reg);
      }
       aux.escribir(ins);
     
     while(!file.eof()) {
                          aux.escribir(reg);
                          leer(reg);
    }

     file.close();
     aux.cerrar();
     remove(nombre);
     aux.renombrar(nombre);
  }
 

template <class T> int archivo_sec<T> :: eliminar(T &elim){
	
	T reg;
	int encontrado = 0;
	archivo_sec<T> aux("aux.tmp" );
	file.open(nombre,ios::in);
	aux.abrir(ios::out);
	file>>reg;
	while(!file.eof()){
		if(reg==elim)
                {      
                        elim = reg;
		 	file>>reg;
			encontrado = 1; }
		else{
			aux.escribir(reg);
			file>>reg;
		}
	}

	file.close();
	aux.cerrar();
        remove(nombre);
	aux.renombrar(nombre);
	return(encontrado);
}



template <class T> void archivo_sec<T> :: imprimir() {

T reg;

abrir(ios::in);

   while(!fin)
    {
      leer(reg);
      cout<<reg<<endl;
    }

   cerrar();

 }


      


