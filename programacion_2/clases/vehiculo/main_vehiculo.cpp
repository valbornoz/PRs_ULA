#include "vehiculo.h"

using namespace std;

main(){

	string t, ma, mo;
	int n, a;

	cout<<"cual es el tipo del vehiculo?"<<endl;
	cin>>t;
	cout<<"cual es la marca del vehiculo?"<<endl;
	cin>>ma;
	cout<<"cual es el modelo del vehiculo?"<<endl;
	cin>>mo;
	cout<<"cuantos ejes posee el vehiculo?"<<endl;
	cin>>n;
	cout<<"de que año es el vehiculo?"<<endl;
	cin>>a;


	Vehiculo v1(t, ma, mo, n, a);

	v1.imprime();

}
