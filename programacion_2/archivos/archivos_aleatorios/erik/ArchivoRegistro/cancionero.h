/*clase cancionero
  posee los atributos y metodos principales para trabajar con las canciones*/

#include<iostream>
#include"hora.h"
using namespace std;

#ifndef _CANCIONERO
#define _CANCIONERO

//clase cancionero
class cancionero
{
  //miembros datos de la clase
 private:
  char nombre[30];//nombre de la cancion a escuchar
  char cantante[30];//nombre del cantante que canta la cancion
  hora h;//hora en la que se quiere escuchar la cancion

  //miembros metodos de la clase
 public:
  cancionero();//constructor por defecto
  cancionero(char[],char[],hora);//constructor parametrico
  void asignar_nombre(char[]);//asigna el nombre de la cancion
  void asignar_cantante(char[]);//asigna el nombre del cantante
  void asignar_hora(hora);//asigna la hora a la cual se quiere escuchar la cancion
  char* obtener_nombre();//devuelve el nombre de la cancion
  char* obtener_cantante();//devuelve el nombre del cantante
  hora obtener_hora();//devuelve la hora en la que se quiere tocar la cancion
  cancionero& operator = (const cancionero &ho);//sobrecarga del operador igual
  friend ostream& operator << (ostream&, const cancionero&);//sobrecarga del operador de salida
  friend void operator >> (istream&, cancionero&);//sobrecarga del operador de entrada
  ~cancionero(){};//destructor de la clase

};//fin clase cancionero

//constructor por defecto
cancionero::cancionero()
{
  for(int i=0;i<30;i++)
  {
    nombre[i]=' ';
    cantante[i]=' ';
  }
}

//constructor parametrico
cancionero::cancionero(char nom[],char can[],hora ho)
{
  for(int i=0;i<strlen(nom);i++)
    this->nombre[i]=nom[i];
  for(int j=0;j<strlen(can);j++)
    this->cantante[j]=can[j];
  
  this->h=ho;
}

//asignar nombre de la cancion
void cancionero::asignar_nombre(char nom[])
{
  int i;
  for(i=0;i<strlen(nom);i++)
    this->nombre[i]=nom[i];
}

//asignar nombre del cantante
void cancionero::asignar_cantante(char can[])
{
  int i;
  for(i=0;i<strlen(can);i++)
    this->cantante[i]=can[i];
}

//asignar hora a la cual se quiere tocar la cancion
void cancionero::asignar_hora(hora ho)
{
  this->h=ho;
}

//obtener nombre de la cancion
char* cancionero::obtener_nombre()
{
  return nombre;
}

//obtener nombre del cantante
char* cancionero::obtener_cantante()
{
  return cantante;
}

//obtener hora a la cual se quiere tocar la cancion
hora cancionero::obtener_hora()
{
  return this->h;
}

//sobrecarga del operador de salida
ostream & operator << (ostream &salida, const cancionero &c)
{
  salida<<"Autor: "<<c.cantante<<endl;
  salida<<"Cancion: "<<c.nombre<<endl;
  salida<<"Hora a la que se desea tocar: "<<endl;
  salida<<c.h;
  return salida;

}

//sobrecarga del operador de entrada
void operator >> (istream &e, cancionero &c)
{

  char nom[30],can[30];
  hora ho;
  cout<<"Introduzca el nombre de la cancion: ";
  cin>>nom;
  cout<<"Introduzca el Autor: ";
  cin>>can;
  cout<<"Introduzca la hora a la cual quiere escuchar la cancion: "<<endl<<"La hora esta definida para ser hora militar"<<endl;
  cin>>ho;
  c.asignar_nombre(nom);
  c.asignar_cantante(can);
  c.asignar_hora(ho);

}

//sobrecarga del operador de asignacion
cancionero& cancionero::operator = (const cancionero &ho)
{
  int i,j;
  //damos los valores
  for(i=0;i<strlen(ho.nombre);i++)
    this->nombre[i]=ho.nombre[i];

  for(j=0;j<strlen(ho.cantante);j++)
    this->cantante[j]=ho.cantante[j];

  this->h = ho.h;
  return *this;  
  
}

#endif
