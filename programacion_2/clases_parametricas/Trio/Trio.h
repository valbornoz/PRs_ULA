#include <iostream>
using namespace std;

template <class T>
class Trio {
	private:
		T primero;
		T segundo;
		T tercero;		
	public:
		Trio();		
		Trio(T pri, T seg, T ter);
		void setPrimero(T pri);
		void setSegundo(T seg);
		void setTercero(T ter);		
		T getPrimero();
		T getSegundo();		
		T getTercero();
		void mostrarTrio();
};

template <class T> Trio<T>::Trio() {
   primero = segundo = tercero = ' ';
}

template <class T> Trio<T>::Trio(T pri, T seg, T ter) {
	primero = pri;
	segundo = seg;
   tercero = ter;
}

template <class T> void Trio<T>::setPrimero(T pri) {
	primero = pri;
}

template <class T> void Trio<T>::setSegundo(T seg) {
	segundo = seg;
}

template <class T> void Trio<T>::setTercero(T ter) {
	tercero = ter;
}

template <class T> T Trio<T>::getPrimero() {
	return primero;
}

template <class T> T Trio<T>::getSegundo() {
	return segundo;
}

template <class T> T Trio<T>::getTercero() {
	return tercero;
}

template <class T> void Trio<T>::mostrarTrio() {
	cout << endl;
   cout << primero << " - " << segundo << " - " << tercero;
   cout << endl << endl;
}
