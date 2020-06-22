#include <iostream>
using namespace std;

template <class T>
class Par {
	private:
		T primero;
		T segundo;
	public:
		Par();		
		Par(T pri, T seg);
		void setPrimero(T pri);
		void setSegundo(T seg);
		T getPrimero();
		T getSegundo();
		void mostrarPar();
};

template <class T> Par<T>::Par() {
}

template <class T> Par<T>::Par(T pri, T seg) {
	primero = pri;
	segundo = seg;
}

template <class T> void Par<T>::setPrimero(T pri) {
	primero = pri;
}

template <class T> void Par<T>::setSegundo(T seg) {
	segundo = seg;
}

template <class T> T Par<T>::getPrimero() {
	return primero;
}

template <class T> T Par<T>::getSegundo() {
	return segundo;
}

template <class T> void Par<T>::mostrarPar() {
	cout << endl << primero << " - " << segundo << endl;
}
