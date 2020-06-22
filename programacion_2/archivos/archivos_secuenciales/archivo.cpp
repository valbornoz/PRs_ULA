#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;
	struct Fecha 
	{	
		int dd;
		int mmm;
		int aaaa;
	};

int main (){

	Fecha f1;
	string nombre,apellido,direccion,telefono,celular;
	int cedula;


	ifstream lectura;    //lectura
	ofstream escritura;  //escritura
	fstream archivo;     //lectura y escritura

escritura.open("Usuario.txt",ios::app);
cout<<"introduce nombre"<<endl;
cin>>nombre;

cout<<"introduce apellido"<<endl;
cin>>apellido;

cout<<"introduce cedula"<<endl;
cin>>cedula;

cout<<"direccion"<<endl;
cin.ignore();
getline(cin,direccion)	;

cout<<"telefono de casa"<<endl;

cin>>telefono;

cout<<"introduce celular"<<endl;
cin>>celular;

cout<<"Fecha de nacimiento"<<endl;
cin>>f1.dd>>f1.mmm>>f1.aaaa;

#include <time.h> /* time_t, struct tm, time, localtime, strftime */

time_t rawtime;
struct tm * timeinfo;
char dia [10];
char mes [10];
char anio [10];

time (&rawtime);
timeinfo = localtime (&rawtime);

strftime (dia,10,"%d",timeinfo);
strftime (mes,10,"/%m",timeinfo);
strftime (anio,10,"/%Y",timeinfo);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	int cedula2, i=8;
	char aux1;
	string codigo;

	srand(time(NULL));

	while(i--){

	aux1=rand()%94+33;

		if(aux1==44){
			aux1=aux1-1;
		}
	codigo=codigo+aux1;

	}
	cedula2=cedula-1342111; 

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

cout<<"***************************++++++++++++++++++++++++++++++"<<endl;
cout<<"Fecha de inscripcion"<<"          "<<"y su codigo ID es"<<endl;

cout<<dia<<mes<<anio<<"                       "<<cedula2<<codigo<<endl;
cout<<"***************************++++++++++++++++++++++++++++++"<<endl;


escritura<<cedula2<<codigo<<", "<<nombre<<", "<<apellido<<", "<<cedula<<", "<<direccion<<", "<<telefono<<", "<<celular<<", "<<f1.dd<<"/"<<f1.mmm<<"/"<<f1.aaaa<<", "<<dia<<mes<<anio<<", "<<"00/00/00"<<", "<<"00/00/00"<<endl;

escritura.close();


return  (0);
}
