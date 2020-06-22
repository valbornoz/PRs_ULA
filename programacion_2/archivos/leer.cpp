#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct RegistroBanco{

	int numerodecuenta;
	float saldo;

};

int main(){

	int n;

	ifstream creditoEntrada("credito.dat", ios::in | ios::binary);

	if(!creditoEntrada){
		cout<<"ERROR!"<<endl;
		return 0;
	}

	RegistroBanco cliente;

	cout<<"indique numero de cuenta"<<endl;
	cin>>n;

	n--;

	creditoEntrada.seekg(n*sizeof(RegistroBanco), ios::beg);

	
	creditoEntrada.read(reinterpret_cast<char*>(&cliente), sizeof(RegistroBanco));

	cout<<"datos del cliente: "<<cliente.numerodecuenta<<" "<<cliente.saldo<<endl;

	return 0;
}
