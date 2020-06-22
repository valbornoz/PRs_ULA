/*Practica de archivo de acceso Directo*/
#include<iostream>
#include<fstream>
#include"hora.h"
using namespace std;




int main()
{
  //variables
  bool terminar=true;
  int op=0;
  //variable que contiene la cantidad de registros del archivo
  int tama=0;

  fstream archi;
 
  fstream leer;
  
  
  //abrimos el archivo de registros para lectura
  leer.open("registro.dat",ios::in);
  
  //verificamos que se pudo abrir
  if(!leer)
    {
      cout<<"NO SE PUDO ABRIR EL ARCHIVO DE REGISTROS"<<endl;
      getchar();
      getchar();
    }
  else
    {
      
      hora temp;
      leer.read( reinterpret_cast<char*>(&temp), sizeof( hora ) );
      
      //contamos cada registro del archivo
      while(leer.eof()!=1)
	{
	  tama++;
	  leer.read( reinterpret_cast<char*>(&temp), sizeof( hora ) );
	  
	}

      //cerramos el archivo
      leer.close();
    } 
  
  

  
 //menu principal
 do
    {


      system("clear");
      cout<<"1. Llenar el Archivo de Registros"<<endl<<"2. Consultar un Registro del Archivo"<<endl<<"3. Ver el numero de registros actuales en el archivo"<<endl<<"4. Salir"<<endl;
      cout<<"Opccion: ";
      cin>>op;
      
      
      //estructura del menu
      switch(op)
	{
	  
	  //llenar el archivo de registros
	case 1:
	  {
	    
	    //abrimos el archivo de registros para escribir
	    archi.open("registro.dat",ios::out|ios::app);
	    
	    //verificamos que se pudo abrir
	    if(!archi)
	      {
		cout<<"NO SE PUDO ABRIR EL ARCHIVO DE REGISTROS"<<endl;
	      }
	    else
	      {
		
		
		//variable que me indica si procede o no ingresando registros
		int op1=0;
		int lugar=0;

		do
		  {
		    //llenamos el registro
		    hora tem;
		    cin>>tem;

		    //lugar donde se escribira el archivo
		    lugar = tama * sizeof( hora );
		    archi.seekp(lugar);

		    //escribimos la informacion el el registro
		    archi.write( reinterpret_cast<char*>(&tem), sizeof( hora ) );
		    tama++;
		    //verificamos si desea seguir ingresando canciones
		    cout<<endl<<"Desea ingresar otro registro si(1) no(0)"<<endl;
		    do
		      {
			cin>>op1;
		      }
		    while((op1!=0) && (op1!=1));
		  }
		while(op1!=0);	
		
		
		archi.close();
	      }
	    cout<<endl<<"Se almacenaron Exitosamente"<<endl;
	    getchar();
	    getchar();
	    break;
	  }

	  //revisar un registro del archivo de manera directa
	case 2:
	  {

	    //variables internas
	    int consultar=0;

	    //leemos el registro a consultar
	    do
	      {
		cout<<"Introduzca el numero del registro a consultar"<<endl;
		cin>>consultar;
	      }
	    while(consultar<1);

	    //evaluamos que el numero a consultar este entre el rango permitido
	    if(consultar>tama)
	      {
		cout<<endl<<"El numero del registro no se encuentra en el archivo"<<endl;
	      }
	    else
	      {

		//abrimos el archivo de registro para lectura
		leer.open("registro.dat",ios::in);
		
		//verificamos que se pudo abrir
		if(!leer)
		  {
		    cout<<"NO SE PUDO ABRIR EL ARCHIVO DE REGISTROS"<<endl;
		  }
		else
		  {
		    
		    hora te;
		    int posi=0;
		    consultar=consultar-1;
		    posi=consultar * sizeof( hora );
		    leer.seekg(posi);
		    leer.read( reinterpret_cast<char*>(&te), sizeof( hora ) );
		    cout << te;	
		      

		    //cerramos el archivo
		    leer.close();
		  }
		
	      }
	    
	    
	    getchar();
	    getchar();
	    break;
	  }
	  //ver el numero de registros que posee el archivo
	case 3:
	  {
	    cout<<"El numero de registros actualmente es: "<<tama<<endl;
	    getchar();
	    getchar();

	    break;
	  }


	  //salir del programa
	case 4:
	  {
	    cout<<endl<<"Gracias por usar el sistema"<<endl;
	    getchar();
	    getchar();
	    terminar=false;

	    break;
	  }

	  //opcion invalida
	default:
	  {

	    cout<<endl<<"Opcion Invalida"<<endl;
	    getchar();
	    getchar();
	    break;
	  }


	}
      
    }
  while(terminar);

  return 0;
}
