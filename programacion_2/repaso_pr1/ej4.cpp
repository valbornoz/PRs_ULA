#include "iostream"

using namespace std;

struct Persona{

	char nombre[20];
	char apellido[20];
	int cedula;
	float salario;

};

void asignacion(struct Persona* p1, int n);
void busca1000(struct Persona* p1, int n);

main(){
	int n;
	struct Persona p1[20];

	cout<<"cuantas personas decea introducir?"<<endl;
	cin>>n;

	asignacion(p1, n);
	busca1000(p1, n);

}

void asignacion(struct Persona *p1, int n){

	for(int i=0; i<n; i++){

	cout<<"nombre de la persona numero "<<i+1<<":"<<endl;
	cin>>p1[i].nombre;
	cout<<"apellido de la persona numero "<<i+1<<":"<<endl;
	cin>>p1[i].apellido;
	cout<<"cedula de la persona numero "<<i+1<<":"<<endl;
	cin>>p1[i].cedula;
	cout<<"salario de la persona numero "<<i+1<<":"<<endl;
	cin>>p1[i].salario;
	cout<<endl;
	}

	cout<<endl<<endl;
	cout<<"Datos introducidos: "<<endl<<endl;

	for(int i=0; i<n; i++){

	cout<<"nombre de la persona numero "<<i+1<<": "<<p1[i].nombre<<endl;
	cout<<"apellido de la persona numero "<<i+1<<": "<<p1[i].apellido<<endl;
	cout<<"cedula de la persona numero "<<i+1<<": "<<p1[i].cedula<<endl;
	cout<<"salario de la persona numero "<<i+1<<": "<<p1[i].salario<<endl;
	cout<<endl;

	}
	cout<<endl<<endl;
}

void busca1000(struct Persona* p1, int n){

	cout<<"las siguientes personas tienen sueldo mayor a 1000 BS: "<<endl;

	for(int i=0; i<n; i++){
		if(p1[i].salario>1000){
			cout<<p1[i].nombre<<" "<<p1[i].apellido<<endl;
		}
	}
}
