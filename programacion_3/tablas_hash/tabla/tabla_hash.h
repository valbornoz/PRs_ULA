#ifndef TABLA_HASH
#define TABLA_HASH

#include "lista_doble.h"

template <class T> class tabla_hash {
	protected:
		long tam;
		lista_doble<T>* v;
	public:
		tabla_hash();
		tabla_hash( long);
		~tabla_hash();
		void inicializa( long);
		T* busca(T&);
		int agrega(const T&);
		int elimina(const T&);
		virtual  long hash(const T&) = 0;
		class intervalo {};
};

template <class T> tabla_hash<T>::tabla_hash(){

	tam = 0;
	v = 0;
}

template <class T> tabla_hash<T>::tabla_hash( long n){
	if (n < 0)
		throw intervalo();

	tam = n;
	v = new lista_doble<T>[tam];
}

template <class T> tabla_hash<T>::~tabla_hash() {
	
	for( long i=0 ; i < tam; i++) 
		v[i].~lista_doble();

	delete[] v;
}

template <class T> void  tabla_hash<T>::inicializa( long n){
	if (n < 0)
		throw intervalo();

	tam = n;
	v = new lista_doble<T>[tam];
}

template <class T> T* tabla_hash<T>::busca(T& dato){
	 long pos;
	

	pos = hash(dato);

	if ((pos < 0) || (pos >= tam ))
		throw intervalo();
	
	if ( v[pos].busca(dato) )
		return( &dato );
	else
		return ((T *)0);
}

template <class T> int tabla_hash<T>::agrega(const T& dato) {
	 long pos;
	int res;

	pos = hash(dato);

	if ((pos < 0) || (pos >= tam ))
		throw intervalo();

	res = v[pos].add(dato);
	
	return (res);
}

template <class T> int tabla_hash<T>::elimina(const T& dato) {
	 long pos;
	int res;

	pos = hash(dato);

	if ((pos < 0) || (pos >= tam ))
		throw intervalo();

	res = v[pos].elimina(dato);
	
	return (res);
}
		

#endif


