#include<iostream>
#include<fstream>
#include "carro.h"

using namespace std;

int main()
{
 

  //declaraciones de variables internas

  fstream escribir;
  
  //abrimos el archivo de canciones para escritura
  escribir.open("carros_secuencial.dat",ios::out|ios::app);
  
  //validamos que se haya abierto el archivo
  if(!escribir)
    {
      cout<<"NO SE PUDO ABRIR EL ARCHIVO DE CARROS SECUENCIAL"<<endl;
    }
  else
    {
      //variable que me indica si procede o no ingresando canciones
      int op1=0;
      do
	{
	  //llenamos el registro
	  carro tem;
	  cin>>tem;
	  //escribimos la informacion el el registro
	  escribir.write( reinterpret_cast<char*>(&tem), sizeof( carro ) );
	  
	  //verificamos si desea seguir ingresando canciones
	  cout<<endl<<"Desea ingresar otra cancion si(1) no(0)"<<endl;
	  cin>>op1;
	  
	}
      while(op1!=0);		
      
      
      //cerramos el archivo
      escribir.close();
      
    }
  
  getchar();
  getchar();


  return 0;
}
