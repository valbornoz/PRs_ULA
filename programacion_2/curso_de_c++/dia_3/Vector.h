/*Clase Vector
Realizada por:
Erik Velasquez*/

#ifndef _VECTOR
#define _VECTOR
#include<iostream>

using namespace std;


template<class T> class Vector
{
	public:
		T * vec;					//puntero a el elemento tipo T
		int size;					//numero de elementos de tipo T almacenados


	//constructor por omision
	Vector()
	{
		vec=NULL;					
		size=0;						
	};

	//destructor
	~Vector()
	{
		delete [] vec;
	};
	
	//constructor por copia
	Vector(Vector<T> & v)
	{	
		vec=v->vec;
		size=v->size;
	};
	
	//acceder a un elemento del vector
	T & access(int pos)
	{
		T garbageData;
		if(pos>=0 and pos<size)
			return vec[pos];
		else	
			return garbageData;
	};

	//devuelve el tamaño del vector
	int getSize()
	{
		return size;
	};

	//devuelve la posicion donde se encuentra el elemento
	int findPos(const T &data)
	{
		for(int i=0;i<size;i++)
		{
			if(data==vec[i])
				return i;	
		}
	
		return -1;
	};
	
	//sobrecarga del operador []
	T & operator [] (const int i)
	{
		return access(i);
	};

	//insertar un elemento en la ultima posicion
	void insert(T & data)
	{
		T * aux;
		aux=vec;
		vec= new T[size +1];
		for(int i=0;i<size;i++)
			vec[i]=aux[i];

		vec[size]=data;
		size++;
		delete []aux;
	};
	void removeLast()
	{
		T * aux;
		aux=vec;
		if(size>0)
		{
			vec= new T[size -1];
			for(int i=0;i<size-1;i++)
				vec[i]=aux[i];

			size--;
			delete []aux;
		}
	};
	
	//remover un elemento cualquiera
	void remove(T & data)
	{
		if(findPos(data)==-1)
			return;
		else{
			int pos=this->findPos(data);
			T * aux;
			aux=vec;
			vec=new T[size-1];
			for(int i=0;i<pos;i++)
				vec[i]=aux[i];
			for(int i=(pos+1);i<size;i++)
				vec[i-1]=aux[i];

			delete [] aux;
			size--;
		}
	};

};//fin clase Vector



#endif 
