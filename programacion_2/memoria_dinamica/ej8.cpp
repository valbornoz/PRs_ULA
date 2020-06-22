#include "iostream"
#include "string"

using namespace std;

struct Hotel{

	string nombre;
	string apellido;
	int cedula;
	string cargo;

};

void ingresar(struct Hotel *h, int n){

	for(int i=0; i<n; i++){
	cout<<"introduzca nombre: "<<endl;
	cin.ignore();
	getline(cin,h[i].nombre);
	cout<<"introduzca apellido: "<<endl;
	getline(cin,h[i].apellido);
	cout<<"introduzca numero de cedula: "<<endl;
	cin>>h[i].cedula;
	cout<<"introduzca cargo(Administrador, Recepcionista, Botones): "<<endl;
	cin.ignore();
	getline(cin,h[i].cargo);
	}

}

void mostrar(struct Hotel *h, int n){

	for(int i=0; i<n; i++){
	cout<<"nombre del empleado "<<i+1<<": "<<h[i].nombre<<endl;
	cout<<"apellido del empleado "<<i+1<<": "<<h[i].apellido<<endl;
	cout<<"cedula del empleado "<<i+1<<": "<<h[i].cedula<<endl;
	cout<<"cargo del empleado "<<i+1<<": "<<h[i].cargo<<endl;

	}

}

void listar(struct Hotel *h, int n){

	for(int i=0;i<n;i++){
	
		if(h[i].cedula>15000000)
			cout<<"el empleado "<<h[i].nombre<<" "<<h[i].apellido<<" tiene cedula mayor a 15 millones"<<endl;
	}
}

main(){

	int n;
	cout<<"cuantos trabajadores desea registrar?"<<endl;
	cin>>n;

	struct Hotel *h = new struct Hotel[n];

	ingresar(h,n);
	mostrar(h,n);
	listar(h,n);

delete []h;

}
