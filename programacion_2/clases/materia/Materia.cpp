#include "Materia.h" 


materia::materia()
  {
	nombrema = " ";
	nombrepr = " ";
	apellidopr = " ";
	aula = " ";
	nrosec = 0;
	nroest = 0;
  }

materia::materia(string nm, string np, string ap, string a, int ns, int ne)
  {
	nombrema = nm;
	nombrepr = np;
	apellidopr = ap;
	aula = a;
	nrosec = ns;
	nroest = ne;
  }

void materia::setnombrema(string nm)
  {
	std::cout<<std::endl;
	std::cout<<" Nombre de la materia: ";
	std::cin>>nombrema;
  }

void materia::setnombrepr(string np)
  {
	std::cout<<std::endl;
	std::cout<<" Nombre del profesor: ";
	std::cin>>nombrepr;
  }

void materia::setapellidopr(string ap)
  {
	std::cout<<std::endl;
	std::cout<<" Apellido del profesor: ";
	std::cin>>apellidopr;
  }

void materia::setaula(string a)
  {
	std::cout<<std::endl;
	std::cout<<" Nro del Aula: ";
	std::cin>>aula;
  }

void materia::setnrosec(int ns)
  {
	std::cout<<std::endl;
	std::cout<<" Numero de sección: ";
	std::cin>>nrosec;
  }

void materia::setnroest(int ne)
  {
	std::cout<<std::endl;
	std::cout<<" Numero de estudiantes: ";
	std::cin>>nroest;
  }

	
string materia::getnombrema()
  {
	std::cout<<std::endl;
	std::cout<<"Nombre de la Materia: "<<nombrema<<std::endl;
	std::cout<<std::endl;
	return nombrema;
  }

string materia::getnombrepr()
  {
	std::cout<<std::endl;
	std::cout<<"Nombre del Profesor: "<<nombrepr<<std::endl;
	std::cout<<std::endl;
	return nombrepr;
  }

string materia::getapellidopr()
  {
	std::cout<<std::endl;
	std::cout<<"Apellido del Profesor: "<<apellidopr<<std::endl;
	std::cout<<std::endl;
	return apellidopr;
  }

string materia::getaula()
  {
	std::cout<<std::endl;
	std::cout<<"Aula: "<<aula<<std::endl;
	std::cout<<std::endl;
	return aula;
  }

int materia::getnrosec()
  {
	std::cout<<std::endl;
	std::cout<<"Numero de sección: "<<nrosec<<std::endl;
	std::cout<<std::endl;
	return nrosec;
  }

int materia::getnroest()
  {
	std::cout<<std::endl;
	std::cout<<"Numero de estudiantes: "<<nroest<<std::endl;
	std::cout<<std::endl;
	return nroest;
  }

//LECTURA POR TECLADO DE TODOS LO CAMPOS

  void materia::lectura(string nm, string np, string ap, string a, int ns, int ne)
  {
	
	std::cout<<"*******************************************"<<endl;
	std::cout<<"           INTRODUCCION DE DATOS           "<<endl;
	std::cout<<"*******************************************"<<endl;
	std::cout<<std::endl;
	std::cout<<"Introduzca el Nombre de la materia: ";
	std::cin>>nombrema;
	std::cout<<"Introduzca el Nombre del profesor:";
	std::cin>>nombrepr;
	std::cout<<"Introduzca el apellido del profesor:";
	std::cin>>apellidopr;
	std::cout<<"Introduzca el Aula: ";
	std::cin>>aula;
	std::cout<<"Introduzca el Numero de sección: ";
	std::cin>>nrosec;
	std::cout<<"Introduzca el Numero de estudiantes: ";
	std::cin>>nroest;
  }

//MUESTRA POR PANTALLA LOS VALORES DE TODOS LOS CAMPOS DE LA CLASE
	
  void materia::mostrar()
  {
	//int nrosec, nroest;	
	std::cout<<"*******************************************"<<endl;
	std::cout<<"           DATOS GUARDADOS                 "<<endl;
	std::cout<<"*******************************************"<<endl;
	std::cout<<std::endl;
	std::cout<<std::endl;	
	std::cout<<"Nombre de la materia: "<<nombrema<<std::endl;
	std::cout<<"Nombre del profesor: "<<nombrepr<<std::endl;
	std::cout<<"Apellido del profesor: "<<apellidopr<<std::endl;
	std::cout<<"Aula: "<<aula<<std::endl;
	std::cout<<"Numero de sección: "<<nrosec<<std::endl;
	std::cout<<"Numero de estudiantes: "<<nroest<<std::endl;
	std::cout<<std::endl;
	
	
  }
		

materia::~materia() {
   
}




