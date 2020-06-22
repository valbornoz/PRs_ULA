#include <iostream>
#include "math.h"

using namespace std;

template <class T>

class Punto {
    
     private:

		T x;
                T y;

     public: 
     		Punto();
     		Punto (T a, T b);
     		~Punto();
     		void setX(T ex);
                void setY(T ey);
                void mostrarPunto();
                void sumaPunto(T t, T z);
		Punto<T> suma(Punto<T>, Punto<T>); 
};

template <class T> Punto<T>::Punto(){
x=0.0;
y=0.0;
}

template <class T> Punto<T>::Punto(T a, T b){
x=a;
y=b;
}

template <class T> Punto<T>::~Punto(){
}

template <class T> void Punto<T>::setX(T ex){
x=ex;
}

template <class T> void Punto<T>::setY(T ey){
y=ey;
}

template <class T> void Punto<T>::mostrarPunto(){
cout<<endl;
cout <<"("<<x<<","<<y<<")"<< endl;
}

template <class T> void Punto<T>::sumaPunto(T t, T z){
T k;
k=t+z;
cout << "La suma de "<<t<<" + "<<z<<" = " <<k<<endl;
}

template <class T> Punto<T> Punto<T>::suma(Punto a, Punto b){
Punto<T> p;

	this->x= (a.x + b.x);
	this->y= (a.y + b.y);

return p;
}
 


      
     


