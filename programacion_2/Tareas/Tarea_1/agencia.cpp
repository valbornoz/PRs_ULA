#include<iostream>
#include<string>

using namespace std;

struct Agencia{
	string nombre;
	int nclientes;
	int ntaquillas;
	string horario;
};

void ingresar(struct Agencia *a, int n){
	for(int i=0; i<n; i++){
		cout<<"como se llama la agencia "<<i+1<<endl;
		cin>>a[i].nombre;
		cout<<"cuantos clientes tiene la agencia "<<a[i].nombre<<endl;
		cin>>a[i].nclientes;
		cout<<"cuantas taquillas tiene la agencia "<<a[i].nombre<<endl;
		cin>>a[i].ntaquillas;
		cout<<"cual es el horario de la agencia "<<a[i].nombre<<endl;
		cin>>a[i].horario;
		cout<<endl<<endl;;
	}
}

void mostrar(struct Agencia *a, int n){
	for(int i=0; i<n; i++){
		cout<<endl;
		cout<<"PARA LA AGENCIA "<<i+1<<":"<<endl<<endl;
		cout<<"nombre: "<<a[i].nombre<<endl;
		cout<<"numero de clientes: "<<a[i].nclientes<<endl;
		cout<<"numero de taquillas: "<<a[i].ntaquillas<<endl;
		cout<<"horario: "<<a[i].horario<<endl;
	}
}

void clientes(struct Agencia *a, int n){

	cout<<"IMPORTANTE: las siguentes agencias tienen mas de 10000 clientes"<<endl;

	for(int i=0; i<n; i++){
		if(a[i].nclientes>10000){
		cout<<"Agencia "<<a[i].nombre<<endl;
		}
	}
}

main(){
	int n;
	char c;

	cout<<"cuantas agencias desea registrar?"<<endl;
	cin>>n;

	struct Agencia *a = new struct Agencia[n];

	ingresar(a,n);

	if(n!=0){
	cout<<"desea mostrar las agencias ingresadas [y/n]?"<<endl;
	cin>>c;
		if(c=='y'){
			mostrar(a,n);
		}
	}
	cout<<endl<<endl;
	clientes(a,n);

delete []a;
}
