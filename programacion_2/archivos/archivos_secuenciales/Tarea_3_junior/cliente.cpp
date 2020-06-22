#include "iostream"
#include "fstream"

using namespace std;

main(){

	string nombre, apellido;
	int n, cedula, dia, mes, anio;
	ofstream escri;
	ifstream leer;

	cout<<"cuantos clientes desea ingresar?"<<endl;
	cin>>n;

	escri.open("aux.txt");

	if(!escri){
		cout<<"ERROR al abrir el archibo !"<<endl;
	}
	else{

		for(int i=0; i<n; i++){
			cout<<"cliente "<<i+1<<endl;
			cout<<"cual es la C.I. del cliente "<<i+1<<endl;
			cin>>cedula;
			cout<<"ingrese nombre del cliente "<<i+1<<endl;
			cin.ignore();
			getline(cin,nombre);
			cout<<"ingrese apellido del cliente "<<i+1<<endl;
			getline(cin,apellido);
			cout<<"ultima compra del cliente "<<i+1<<" dd mm aaaa"<<endl;
			cin>>dia>>mes>>anio;
			
			cout<<endl;
	
			escri<<nombre<<" ~"<<apellido<<" ~"<<dia<<"/"<<mes<<"/"<<anio<<" "<<cedula<<endl;
		}
	}
	escri.close();

//	Depurar


	leer.open("aux.txt");
	if(!leer){
		cout<<"ERROR al abrir el archibo aux!"<<endl;
	}
	else{

	escri.open("clientes.txt",ios::app);
		if(!escri){
			cout<<"ERROR al abrir el archibo clientes!"<<endl;
		}
		else{
			string dia2, mes2;
		
			while(getline(leer,nombre,'~') and getline(leer,apellido,'~') and getline(leer,dia2,'/') and getline(leer,mes2,'/') and leer>>anio and leer>>cedula){
	
				if(anio>=2010){
					escri<<nombre<<" ~"<<apellido<<" ~"<<dia2<<" /"<<mes2<<" /"<<anio<<" "<<cedula<<endl;
				}
			}
		escri.close();
		}
	leer.close();
	}



}
