#include "persona.h"

using namespace std;

int main(){


	bool sexo;
	Persona p;

	p.asignarEdad(15);
	p.asignarSexo(false);
	p.asignarSueldo(614.00);

	Persona p2(15,true,1200.75);

	Persona p3(p2);
	
	cout<<"Edad de la persona 1: "<<p.verEdad()<<endl;
	sexo = p.verSexo();

	if (sexo == true){
		cout<<"El sexo de la persona 1 es masculino"<<endl;
	}else{
		cout<<"El sexo de la persona 1 es femenino"<<endl;
	}

	cout<<"Sueldo de la persona 1: "<<p.verSueldo()<<endl;
	
	cout<<"Edad de la persona 3 "<<p3.verEdad()<<endl;
	cout<<"Sexo de la persona 3 "<<p3.verSexo()<<endl;
	cout<<"Sueldo de la persona 3 "<<p3.verSueldo()<<endl;

return 0;
}
