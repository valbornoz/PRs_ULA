#include "Banco.h"
using namespace std;

Banco::Banco(){
	nombreb=" ";
	nombrea=" ";
	fecha.d=0;
	fecha.m=0;
	fecha.a=0;
	ciudad=" ";
	direccion=" ";
	nombreg=" ";
	apellidog=" ";
	cedulag=" ";
}

Banco::Banco(string nb, string na, Fecha f, string cid, string dir, string ng, string ag, string cg){
	nombreb=nb;
	nombrea=na;
	fecha.d=f.d;
	fecha.m=f.m;
	fecha.a=f.a;
	ciudad=cid;
	direccion=dir;
	nombreg=ng;
	apellidog=ag;
	cedulag=cg;
}

Banco::Banco(const Banco &b){
	nombreb=b.nombreb;
	nombrea=b.nombrea;
	fecha=b.fecha;
	ciudad=b.ciudad;
	direccion=b.direccion;
	nombreg=b.nombreg;
	apellidog=b.apellidog;
	cedulag=b.cedulag;
}

void Banco::setnombreb(string nb){
	nombreb=nb;
}

void Banco::setnombrea(string na){
	nombrea=na;
}

void Banco::setfecha(Fecha f){
	if(f.d<0||f.d>31){
		cout<<"ERROR al introducir fecha"<<endl;
		fecha.d=0;
	}
	else{
		fecha.d=f.d;
	}

	if(f.m<0||f.m>12){
		cout<<"ERROR al introducir fecha"<<endl;
		fecha.m=0;
	}
	else{
		fecha.m=f.m;
	}

	if(f.a<0){
		cout<<"ERROR al introducir fecha"<<endl;
		fecha.a=0;
	}
	else{
		fecha.a=f.a;
	}
}
	
void Banco::setciudad(string cid){
	ciudad=cid;
}

void Banco::setdireccion(string dir){
	direccion=dir;
}
	
void Banco::setnombreg(string ng){
	nombreg=ng;
}

void Banco::setapellidog(string ag){
	apellidog=ag;
}
	
void Banco::setcedulag(string cg){
	cedulag=cg;
}

string Banco::getnombreb(){
	return nombreb;
}

string Banco::getnombrea(){
	return nombrea;
}
	
Fecha Banco::getfecha(){
	return fecha;
}
	
string Banco::getciudad(){
	return ciudad;
}

string Banco::getdireccion(){
	return direccion;
}

string Banco::getnombreg(){
	return nombreg;
}

string Banco::getapellidog(){
	return apellidog;
}

string Banco::getcedulag(){
	return cedulag;
}

void Banco::lectura(int n){

	string nb, na, cid, dir, ng, ag, cg;
	Fecha f;

for(int i=0; i<n; i++){
	cout<<"para el banco "<<i+1<<":"<<endl<<endl;
	cout<<"cual es el nombre del banco?"<<endl;
	cin>>nb;
	cout<<"cual es el nombre de la agencia?"<<endl;
	cin>>na;
	cout<<"cual fue la fecha de creacion del banco?"<<endl;
	cin>>f.d>>f.m>>f.a;
	cout<<"en que ciudad se encuentra el banco?"<<endl;
	cin>>cid;
	cout<<"cual es la direccion del banco?"<<endl;
	cin>>dir;
	cout<<"cual es el nombre del gerente del banco?"<<endl;
	cin>>ng;
	cout<<"cual es el apellido del gerente del banco?"<<endl;
	cin>>ag;
	cout<<"cual es la cedula del gerente del banco?"<<endl;
	cin>>cg;

	setnombreb(nb);
	setnombrea(na);
	setfecha(f);
	setciudad(cid);
	setdireccion(dir);
	setnombreg(ng);
	setapellidog(ag);
	setcedulag(cg);

	}

}
	
void Banco::mostrar(int n){

	for(int i=0; i<n; i++){
		cout<<endl;
	cout<<"nombre del banco "<<i+1<<":"<<nombreb<<endl;
	cout<<"nombre de la agencia "<<i+1<<":"<<nombrea<<endl;
	cout<<"fecha de creacion del banco "<<i+1<<":"<<fecha.d<<fecha.m<<fecha.a<<endl;
	cout<<"ciudad en que se encuentra el banco "<<i+1<<":"<<ciudad<<endl;
	cout<<"direccion del banco "<<i+1<<":"<<direccion<<endl;
	cout<<"nombre del gerente del banco "<<i+1<<":"<<nombreg<<endl;
	cout<<"apellido del gerente del banco "<<i+1<<":"<<apellidog<<endl;
	cout<<"cedula del gerente del banco "<<i+1<<":"<<cedulag<<endl;
	}

}

Banco::~Banco(){
}
