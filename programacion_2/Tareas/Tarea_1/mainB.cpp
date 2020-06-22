#include "Banco.h"
using namespace std;

main(){
	int n;
	char c;

	cout<<"cuantos bancos desea registrar?"<<endl;
	cin>>n;

	Banco b;
	b.lectura(n);

	cout<<"desea mostrar la informacion de los bancos ingresados [y/n]?"<<endl;
	cin>>c;
		if(c=='y'){
			b.mostrar(n);
		}
	



}
