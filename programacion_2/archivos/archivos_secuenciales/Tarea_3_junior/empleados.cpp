#include "iostream"
#include "fstream"

using namespace std;

int main(){

	string nombre;
	string apellido;
	string cargo;
	int n, edad;
	ofstream escri, escri2;
	ifstream leer;

	cout<<"cuantos empleados desea ingresar?"<<endl;
	cin>>n;

	escri.open("empleados.txt",ios::app);

	if(!escri){
		cout<<"ERROR al abrir el archibo !"<<endl;
	}
	else{

		for(int i=0; i<n; i++){
			cout<<"empleado "<<i+1<<endl;
			cout<<"ingrese nombre del empleado "<<i+1<<endl;
			cin.ignore();
			getline(cin,nombre);
			cout<<"ingrese apellido del empleado "<<i+1<<endl;
			getline(cin,apellido);
			cout<<"que cargo tiene el empleado "<<i+1<<endl;
			cin.ignore();
			getline(cin,cargo);
			cout<<"que edad tiene el empleado "<<i+1<<endl;
			cin>>edad;
			cout<<endl;
	
			escri<<nombre<<" ~"<<apellido<<" ~"<<cargo<<" ~"<<edad<<endl;
		}
	}
	escri.close();

//	jovenes y adultos


	

	leer.open("empleados.txt");
	if(!leer){
		cout<<"ERROR al abrir el archibo !"<<endl;
	}
	else{

	escri.open("joven.txt");
	escri2.open("adulto.txt");
		
		while(getline(leer,nombre,'~') and getline(leer,apellido,'~') and getline(leer,cargo,'~') and leer>>edad){
	
			if(edad<25){
				escri<<nombre<<" ~"<<apellido<<" ~"<<cargo<<" ~"<<edad;
			}

			if(edad>=30 and edad<=49){
				escri2<<nombre<<" ~"<<apellido<<" ~"<<cargo<<" ~"<<edad;
			}
		}

	escri.close();
	escri2.close();
	}

	
	leer.close();			

	return 0;

}
