#include "Linea.h"
using namespace std;

main(){
	int n;
	char c;

	cout<<"¿cuantas lineas desea introducir?"<<endl;
	cin>>n;

	Linea *l1 = new Linea[n];

	cout<<"INTRODUZCA LAS LINEAS"<<endl;

	for(int i=0; i<n; i++){
		cout<<"linea "<<i+1<<":"<<endl;
		l1[i].leer();
	}

	cout<<"desea ver los datos introducidos [y/n]?"<<endl;
	cin>>c;

	if(c=='y'||c=='Y'){
		for(int i=0; i<n; i++){
			cout<<"linea "<<i+1<<":"<<endl;
			l1[i].mostrar();
		}

	}

}
