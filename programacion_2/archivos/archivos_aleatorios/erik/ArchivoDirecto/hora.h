/*Clase hora*/
#include<iostream>

using namespace std;

#ifndef _HORA
#define _HORA

//clase hora
class hora
{

  //miembros datos
 private:
  int h, m, s;

  //miembros metodos
 public:
  hora();//constructor por defecto
  hora(int,int,int);//constructor parametrico
  void asigna_hora(int);//asignar hora
  void asigna_minutos(int);//asigna minutos
  void asigna_segundos(int);//asigna segundos
  int obtener_hora();//devuelve hora
  int obtener_minutos();//devuelve minutos
  int obtener_segundos();//deuelve segundos
  int convertir_en_segundos();//devuelve la hora actual en segundos
  friend ostream & operator << (ostream &,const hora &);//sobreescribir operador de salida
  friend bool operator < (const hora&, const hora&);//menor
  friend bool operator > (const hora&, const hora&);//mayor
  friend void operator >> (istream &, const hora &);//sobreescribir operador de entrada
  hora& operator = (const hora&);//sobrecarga del operador de asignacion
  friend hora operator - (const hora&,const hora&);//sobrecarga del resta
  friend hora operator + (const hora&,const hora&);//sobrecarga del suma
  friend bool operator == (const hora&, const hora&);//sobrecarga igual
  friend bool operator != (const hora&, const hora&);//sobrecarga distinto
  ~hora(){};//destructor


};//fin clase hora


//constructor por defecto
hora::hora()
{

  this->h=0;
  this->m=0;
  this->s=0;

}

//constructor parametrico
hora::hora(int hora,int min,int seg)
{
  this->h=hora;
  this->m=min;
  this->s=seg;
}

//asignar hora
void hora::asigna_hora(int hora)
{
  this->h=hora;
}

//asignar minutos
void hora::asigna_minutos(int min)
{
  this->m=min;
}

//asignar seg
void hora::asigna_segundos(int seg)
{
  this->s=seg;
}

//obtener hora
int hora::obtener_hora()
{
  return this->h;
}

//obtener minutos
int hora::obtener_minutos()
{
  return this->m;
}

//obtener segundos
int hora::obtener_segundos()
{
  return this->s;
}

//convertir en segundos
int hora::convertir_en_segundos()
{
  long int segundos_totales;
  //asignamos los segundos actuales
  segundos_totales = this->s;

  //asignamos los segundos por cada hora
  segundos_totales = segundos_totales + (this->h * 3600);

  //asignamos los segundos por cada minuto
  segundos_totales = segundos_totales + (this->m * 60);
  return segundos_totales;

}

//sobreescribir operador de salida
ostream & operator << (ostream &salida, const hora &ho)
{

  int hora,min,seg;
  hora=ho.h;
  min=ho.m;
  seg=ho.s;
  salida<<"Hora: "<<hora<<":"<<min<<":"<<seg<<endl;

  return salida;
} 

//sobreescribir operador de entrada
void operator >> (istream &e, hora&ho)
{
  int hora,min,seg;
  //validamos que la hora este entre 0 y 23
  do
    {
      cout<<"Hora: ";cin>>hora;
    }
  while(hora<0 || hora>23);

  //validamos que los minutos esten entre o y 59
  do
    {
      cout<<"Minutos: ";cin>>min;
    }
  while(min<0 || min>59);

  //validamos que los segundos esten entre o y 59
  do
    {
      cout<<"Segundos: ";cin>>seg;
    }
  while(seg<0 || seg>59);

  //asignamos los valores
  ho.asigna_hora(hora);
  ho.asigna_minutos(min);
  ho.asigna_segundos(seg);

}

//sobrecarga del operador de asignacion
hora& hora::operator = (const hora &ho)
{
  
  //damos los valores
  this->h = ho.h;
  this->m = ho.m;
  this->s = ho.s;
  return *this;  
  
}

//sobrecarga del resta
  hora operator - (const hora &ho1,const hora &ho2)
{
  hora hor;

  //restamos los vlores
  hor.h = ho1.h - ho2.h;
  hor.m = ho1.m - ho2.m;
  hor.s = ho1.s - ho2.s;

  //verificamos que no den valores negativos
  if(hor.h<0)
    hor.h = hor.h * -1;

  if(hor.m<0)
    hor.m = hor.m * -1;

  if(hor.s<0)
    hor.s = hor.s * -1;

  return hor;

}

hora operator + (const hora &ho1,const hora &ho2)//sobrecarga del suma
{
  hora hor;

  //daoms los valores
  hor.h = ho1.h + ho2.h;

  //validamos que los segundos esten en el rango permitido
  if((ho1.s + ho2.s) > 59)
    {
      hor.s = ((ho1.s + ho2.s)-60);
      hor.m = ((ho1.m + ho2.m)+1);
    }
  else
    {
      hor.s = (ho1.s + ho2.s);
    }

  //validamos que los minutos esten en el rango
  if((ho1.m + ho2.m) > 59)
    {
      hor.m = ((ho1.m + ho2.m)-60);
      hor.h = ((ho1.h + ho2.h)+1);
    }
  else
    {
      hor.m = (ho1.m + ho2.m);
    }

  return hor;

} 

//sobrecarga igual
bool operator == (const hora &ho1, const hora &ho2)
{

  if((ho1.h == ho2.h)&&(ho1.m == ho2.m)&&(ho1.s == ho2.s))
    {
      return true;
    }
  else
    {
      return false;
    }

} 

//sobrecarga distinto
bool operator != (const hora &ho1, const hora &ho2)
{

  if((ho1.h == ho2.h)&&(ho1.m == ho2.m)&&(ho1.s == ho2.s))
    {
      return false;
    }
  else
    {
      return true;
    }

}

//menor
bool operator < (const hora &ho1, const hora &ho2)
{

  //validamos que la hora sea menor
  if(ho1.h < ho2.h)
    {
      return true;
    }
  else
    {
      //si las horas son iguales
      if(ho1.h == ho2.h)
	{
	  //si los minutos son menores
	  if(ho1.m < ho2.m)
	    {
	      return true;
	    }
	  else
	    {
	      //si los minutos son iguales
	      if(ho1.m == ho2.m)
		{
		  //si los segundos son menores
		  if(ho1.s < ho2.s)
		    {
		      return true;
		    }
		  //los dos son iguales
		  else
		    {
		      return false;
		    }
		}
	      else
		{
		  return false;
		}
	    }
	}
      else
	{
	  return false;
	}
    }

}

//mayor
bool operator > (const hora &ho1, const hora &ho2)
{

  //si la hora es mayor
  if(ho1.h > ho2.h)
    {
      return true;
    }
  else
    {
      //si la hora es igual
      if(ho1.h == ho2.h)
	{
	  //si los minutos son mayores
	  if(ho1.m > ho2.m)
	    {
	      return true;
	    }
	  else
	    {
	      //si los minutos son iguales
	      if(ho1.m == ho2.m)
		{
		  //si los segundos son mayores
		  if(ho1.s > ho2.s)
		    {
		      return true;
		    }
		  //las dos horas son iguales
		  else
		    {
		      return false;
		    }
		}
	      else
		{
		  return false;
		}
	    }
	}
      else
	{
	  return false;
	}
    }

}


#endif
