#include <iostream>
using namespace std;

class Trio {
	private:
		char primero;
		char segundo;
		char tercero;		
	public:
		Trio();		
		Trio(char pri, char seg, char ter);
		void setPrimero(char pri);
		void setSegundo(char seg);
		void setTercero(char ter);		
		char getPrimero();
		char getSegundo();		
		char getTercero();
		void mostrarTrio();
};

Trio::Trio() {
   primero = segundo = tercero = ' ';
}

Trio::Trio(char pri, char seg, char ter) {
	primero = pri;
	segundo = seg;
   tercero = ter;
}

void Trio::setPrimero(char pri) {
	primero = pri;
}

void Trio::setSegundo(char seg) {
	segundo = seg;
}

void Trio::setTercero(char ter) {
	tercero = ter;
}

char Trio::getPrimero() {
	return primero;
}

char Trio::getSegundo() {
	return segundo;
}

char Trio::getTercero() {
	return tercero;
}

void Trio::mostrarTrio() {
	cout << endl;
   cout << primero << " - " << segundo << " - " << tercero;
   cout << endl << endl;
}

