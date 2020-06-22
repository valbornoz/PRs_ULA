#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct RegistroBanco{

	int numerodecuenta;
	float saldo;

};

int main(){

	fstream creditoSalida("credito.dat", ios::in | ios::out | ios::binary);

	if(!creditoSalida){
		cout<<"ERROR!"<<endl;
		return 0;
	}

	RegistroBanco cliente;

	cout<<"escriba el numero de cuenta entre 1 y 100"<<endl;
	cin>>cliente.numerodecuenta;

	cout<<"escriba el saldo"<<endl;
	cin>>cliente.saldo;

	
	creditoSalida.seekp((cliente.numerodecuenta-1)*sizeof(RegistroBanco), ios::beg);


	creditoSalida.write(reinterpret_cast< const char* >(&cliente), sizeof(RegistroBanco));


	return 0;
}
