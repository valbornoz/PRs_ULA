#include "iostream"

using namespace std;

struct Clase{

	char materia[20];
	char carrera[20];
	int semestre;
	char profesor[20];
	int nalumnos;

};

main(){
	struct Clase clase1;

	cout<<endl;
	cout<<"**introdusca los datos de la clase**"<<endl<<endl;

	cout<<"MATERIA: "<<endl;
	cin>>clase1.materia;
	cout<<"CARRERA: "<<endl;
	cin>>clase1.carrera;
	cout<<"SEMESTRE: "<<endl;
	cin>>clase1.semestre;
	cout<<"PROFESOR: "<<endl;
	cin>>clase1.profesor;
	cout<<"CANTIDAD DE ALUMNOS: "<<endl;
	cin>>clase1.nalumnos;
	cout<<endl;

	cout<<"Datos introducidos: "<<endl<<endl;

	cout<<clase1.materia<<endl;
	cout<<clase1.carrera<<endl;
	cout<<clase1.semestre<<endl;
	cout<<clase1.profesor<<endl;
	cout<<clase1.nalumnos<<" alumnos"<<endl;
	

}
