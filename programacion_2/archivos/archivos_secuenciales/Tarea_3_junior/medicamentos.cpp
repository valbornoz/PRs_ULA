#include "iostream"
#include "fstream"

using namespace std;

main(){

	string codigo, nombre;
	float presio;
	int n, A=65, a=97;
	ofstream medi;
	ifstream leer;

	cout<<"cuantos medicamentos desea ingresar?"<<endl;
	cin>>n;

	medi.open("aux.txt",ios::app);

	if(!medi){
		cout<<"ERROR al abrir el archibo !"<<endl;
	}
	else{

		for(int i=0; i<n; i++){
			cout<<"medicamento "<<i+1<<endl;
			cout<<"ingrese codigo del medicamento "<<i+1<<endl;
			cin.ignore();
			getline(cin,codigo);
			cout<<"ingrese nombre del medicamento "<<i+1<<endl;
			getline(cin,nombre);
			cout<<"que presio tiene el medicamento "<<i+1<<" en Bs.F"<<endl;
			cin>>presio;
			cout<<endl;
	
			medi<<codigo<<"~"<<nombre<<"~"<<presio<<endl;
		}
	}
	medi.close();

// orden alfabetico**************************************************************************

	leer.open("aux.txt");

	if(!leer){
		cout<<"ERROR al abrir el archibo !"<<endl;
	}
	else{

		medi.open("medicamentos.txt",ios::app);

		for(int i=0; i<=24; i++){
			while(getline(leer,codigo,'~') and getline(leer,nombre,'~') and leer>>presio){

					if(nombre[0]==A or nombre[0]==a){
						medi<<codigo<<"~"<<nombre<<"~"<<presio<<endl;
					}
			}

			leer.close();
			leer.open("aux.txt");

			A++;
			a++;
			cout<<endl<<"A= "<<A<<endl<<"a= "<<a<<endl;

		}
		cout<<endl;
	}
	leer.close();


medi.close();

//**********************************************************************************************

	leer.open("medicamentos.txt");

	if(!leer){
		cout<<"ERROR al abrir el archibo !"<<endl;
	}
	else{
		cout<<endl;
		cout<<"DATOS DEL ARCHIBO:"<<endl<<endl;
		while(getline(leer,codigo,'~') and getline(leer,nombre,'~') and leer>>presio){
			cout<<codigo<<" "<<nombre<<" "<<presio;
		}
		cout<<endl;
	}
	leer.close();

}
