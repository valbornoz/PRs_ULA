/*Clase carro*/
#include<iostream>

using namespace std;

//funcion que devuelve verdadero si son iguales las palabras y falso si son diferentes
bool compara_palabras(char a[],char b[])
{
  //comparamos el tamaño de cada palabra
  if(strlen(a)!=strlen(b))//tienen longitudes distintas.
    return false;
  
  //comparamos cada unos de sus caracteres
  for (int i=0;i<strlen(a);i++)
    if (a[i] != b[i])
      return false;
  
  return true;
}


#ifndef _CARRO
#define _CARRO

//clase carro
class carro
{

  //miembros datos
 public:
  char placa[10];
  char modelo[15];
  char marca[15];
  char color[15];

  //miembros metodos
 public:
  carro();//constructor por defecto
  void asigna_placa(char[]);//asignar placa
  void asigna_modelo(char[]);//asigna modelo
  void asigna_marca(char[]);//asigna marca
  void asigna_color(char[]);//asigna color
  char* obtener_placa();//devuelve placa
  char* obtener_modelo();//devuelve modelo
  char* obtener_marca();//devuelve marca
  char* obtener_color();//devuelve color
  char* obtener_campo_clave();//devuelve el campo clave placa
  friend ostream & operator << (ostream &, carro &);//sobreescribir operador de salida
  friend void operator >> (istream &, const carro &);//sobreescribir operador de entrada
  carro& operator = (const carro&);//sobrecarga del operador de asignacion
  friend bool operator == ( carro&,  carro&);//sobrecarga igual
  ~carro(){};//destructor


};//fin clase 


carro::carro()//constructor
{
  
  strcpy(this->placa,"0000000");
  strcpy(this->modelo,"ninguno");
  strcpy(this->color,"ninguno");
  strcpy(this->marca,"ninguno");
  
}

void carro::asigna_placa(char x[])//asigna valor
{
  strcpy(this->placa,x);
}

void carro::asigna_marca(char x[])//asigna valor
{
  strcpy(this->marca,x);
}

void carro::asigna_modelo(char x[])//asigna valor
{
  strcpy(this->modelo,x);
}

void carro::asigna_color(char x[])//asigna valor
{
  strcpy(this->color,x);
}

char* carro::obtener_placa()//devuelve el valor
{
  return this->placa;
}

char* carro::obtener_marca()//devuelve el valor
{
  return this->marca;
}

char* carro::obtener_modelo()//devuelve el valor
{
  return this->modelo;
}

char* carro::obtener_color()//devuelve el valor
{
  return this->color;
}

char* carro::obtener_campo_clave()//devuelve el valor
{
  return this->placa;
}

ostream & operator << (ostream &salida, carro &x)//sobreescribir operador de salida
{

  salida<<endl<<"Marca: "<<x.obtener_marca()<<endl<<"Modelo: "<<x.obtener_modelo()<<endl<<"Color: "<<x.obtener_color()<<endl<<"Placa: "<<x.obtener_placa()<<endl;

  return salida;
}
void operator >> (istream &entrada, carro &x)//sobreescribir operador de entrada
{

  char pla[10];
  char mo[15];
  char mar[15];
  char co[15];

  cout<<"Introduzca la marca del carro: ";
  cin>>mar;
  cout<<"Introduzca el modelo del carro: ";
  cin>>mo;
  cout<<"Introduzca el color del carro: ";
  cin>>co;
  cout<<"Introduzca la placa del carro: ";
  cin>>pla;
  cout<<endl;
  x.asigna_placa(pla);
  x.asigna_marca(mar);
  x.asigna_modelo(mo);
  x.asigna_color(co);
  
}

//sobrecarga del operador de asignacion
carro& carro::operator = (const carro &ho)
{
  
  strcpy(this->placa,ho.placa);
  strcpy(this->modelo,ho.modelo);
  strcpy(this->color,ho.color);
  strcpy(this->marca,ho.marca);

  return *this;  
  
}

//sobrecarga igual
bool operator == ( carro &ho1,  carro &ho2)
{

  if(compara_palabras(ho1.placa,ho2.placa))
    {
      return true;
    }
  else
    {
      return false;
    }

} 



#endif
