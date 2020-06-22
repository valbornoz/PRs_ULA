#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct RegistroBanco{

	int numerodecuenta;
	float saldo;

};

int main(){

	ofstream creditoSalida("credito.dat", ios::out | ios::binary);

	if(!creditoSalida){
		cout<<"ERROR!"<<endl;
		return 0;
	}

	RegistroBanco cliente;
	cliente.numerodecuenta=0;
	cliente.saldo=0;

	for(int i=0; i<100; i++)
		creditoSalida.write(reinterpret_cast< const char* >(&cliente), sizeof(RegistroBanco));


	return 0;
}
