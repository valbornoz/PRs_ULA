#include<iostream>
#include<string>
using namespace std;

struct Hotel{

	char nombre[20];
	char apellido[20];
	int cedula;
	char cargo[20];
};

void ingresar(struct Hotel *H, int n)
{
	int i = 0;
	
		cout<<"************************************************"<<endl;
		cout<<"              EMPLEADOS A REGISTRAR             "<<endl;
		cout<<"************************************************"<<endl;

	for(i=0;i<n;i++)
	{
		
		cout<<endl;
		cout<<"Empleado "<<i+1<<" :"<<endl;
		cout<<"Introduzca el nombre del empleado: ";
		cin>>H[i].nombre;
		cout<<"Introduzca el apellido del empleado: ";
		cin>>H[i].apellido;
		cout<<"Introduzca la cedula del empleado: ";
		cin>>H[i].cedula;
		cout<<"Introduzca el cargo ( Administrador, Recepcionista o Botones): ";
		cin>>H[i].cargo;
		cout<<endl; 
	}
}

void mostrar(struct Hotel *H, int n)	
{
	
	int i=0;
	
		cout<<"************************************************"<<endl;
		cout<<"              EMPLEADOS REGISTRADOS             "<<endl;
		cout<<"************************************************"<<endl;
	
	for(i=0;i<n;i++)
	{
		cout<<endl;
		cout<<"EMPLEADO "<<i+1<<":"<<endl;	
		cout<<"NOMBRE: "<<H[i].nombre<<endl;
		cout<<"APELLIDO: "<<H[i].apellido<<endl;
		cout<<"C.I: "<<H[i].cedula<<endl;
		cout<<"CARGO: "<<H[i].cargo<<endl;
		cout<<endl;
	}
}

void cm15mill(struct Hotel *H, int n)
{
	int i=0;
	
		cout<<"************************************************"<<endl;
		cout<<"     EMPLEADOS CON C.I MAYOR A 15 MILLONES      "<<endl;
		cout<<"************************************************"<<endl;
	
	for(i=0;i<n;i++)
	{
		if(H[i].cedula > 15000000)
		{
			cout<<"EMPLEADO "<<i+1<<":"<<endl;	
			cout<<"NOMBRE: "<<H[i].nombre<<endl;
			cout<<"APELLIDO: "<<H[i].apellido<<endl;
			cout<<"C.I: "<<H[i].cedula<<endl;
			cout<<"CARGO: "<<H[i].cargo<<endl;
			cout<<endl;		
		}
	}
}
int main(){

	int n;
	cout<<"¿Cuantos empleados desea registrar?: ";
	cin>>n;

	struct Hotel *H = new struct Hotel[n];
	ingresar(H,n);
	mostrar(H,n);
	cm15mill(H,n);
	
delete []H;
return 0;
}



