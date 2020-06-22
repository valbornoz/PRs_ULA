#include<iostream>
#include<string>
using namespace std;

struct strFecha {
   int d,m,a;
};

struct Barco{

	char nombre[20];
        char tipo[20];
        float mts;
        struct strFecha fechaen;
        struct strFecha fechasa;
	int tripulacion;
};

void ingresar(struct Barco *H, int n)
{
	int i = 0;
	
		cout<<"************************************************"<<endl;
		cout<<"              Barco A REGISTRAR             "<<endl;
		cout<<"************************************************"<<endl;

	for(i=0;i<n;i++)
	{
		
		cout<<endl;
		cout<<"Barco "<<i+1<<" :"<<endl;
		cout<<"Introduzca el nombre del barco: ";
		cin>>H[i].nombre;
		cout<<"Introduzca el Tipo (Yate, Chalana, Trasatlantico, Gamarra):  ";
		cin>>H[i].tipo;
		cout<<"Introduzca los metros de Eslora: ";
		cin>>H[i].mts;
                cout << "Fecha de entrada al Puerto: ";
                cin >> H[i].fechaen.d >> H[i].fechaen.m >> H[i].fechaen.a;
                cout << "Fecha de Salida del Puerto: ";
                cin >> H[i].fechasa.d >> H[i].fechasa.m >> H[i].fechasa.a;
		cout<<"Número de Tripulantes: ";
		cin>>H[i].tripulacion;
		cout<<endl; 
	}
}

void mostrar(struct Barco *H, int n)	
{
	
	int i=0;
	
		cout<<"************************************************"<<endl;
		cout<<"              Barcos REGISTRADOS             "<<endl;
		cout<<"************************************************"<<endl;
	
	for(i=0;i<n;i++)
	{
		cout<<endl;
		cout<<"Barco "<<i+1<<":"<<endl;	
		cout<<"Nombre: "<<H[i].nombre<<endl;
		cout<<"Tipo: "<<H[i].tipo<<endl;
		cout<<"Metros: "<<H[i].mts<<endl;
		cout<<"Fecha de Entrada: "<<H[i].fechaen.d << H[i].fechaen.m << H[i].fechaen.a<<endl;
                cout<<"Fecha de Salida: "<<H[i].fechasa.d << H[i].fechasa.m << H[i].fechasa.a<<endl;
                cout<<"Número de Tripulantes: "<<H[i].tripulacion<<endl;
		cout<<endl;
	}
}

void grande(struct Barco *H, int n)
{
	int i=0;
	
		cout<<"************************************************"<<endl;
		cout<<"     Barcos Grandes Eslora mayor a 100 mts      "<<endl;
		cout<<"************************************************"<<endl;
	
	for(i=0;i<n;i++)
	{
		if(H[i].mts > 100)
		{
			cout<<endl;
		        cout<<"Barco "<<i+1<<":"<<endl;	
		        cout<<"Nombre: "<<H[i].nombre<<endl;
		        cout<<"Tipo: "<<H[i].tipo<<endl;
		        cout<<"Metros: "<<H[i].mts<<endl;
		        cout<<"Fecha de Entrada: "<<H[i].fechaen.d << H[i].fechaen.m << H[i].fechaen.a<<endl;
                        cout<<"Fecha de Salida: "<<H[i].fechasa.d << H[i].fechasa.m << H[i].fechasa.a<<endl;
                        cout<<"Número de Tripulantes: "<<H[i].tripulacion<<endl;
		        cout<<endl;		
		}
	}
}

int main(){

	int n;
		cout<<"¿Cuantos barcos desea registrar?: ";
	cin>>n;

	struct Barco *H = new struct Barco[n];
	ingresar(H,n);
	mostrar(H,n);
	grande(H,n);
	
delete []H;
return 0;
}



