#include<iostream>
#include<fstream>
#include"cancionero.h"
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





int main()
{

  //variables globales del programa
  int op,terminar=1;
  //menu principal del programa
  do
    {

      system("clear");
      cout<<"MENU"<<endl<<"1. Llenar Canciones del dia"<<endl<<"2. Crear el archivo con las canciones que se tocaran el dia siguiente"<<endl<<"3. Ver archivos asociados"<<endl<<"4. Salir"<<endl<<"Opcion: ";
      cin>>op;

      switch(op)
	{

	  //llenar el archivo canciones
	case 1:
	  {
	    //declaraciones de variables internas

	    fstream escribir;

	    //abrimos el archivo de canciones para escritura
	    escribir.open("canciones.dat",ios::out);
	    
	    //validamos que se haya abierto el archivo
	    if(!escribir)
	      {
		cout<<"NO SE PUDO ABRIR EL ARCHIVO DE CANCIONES"<<endl;
	      }
	    else
	      {
		//variable que me indica si procede o no ingresando canciones
		int op1=0;
		do
		  {
		    //llenamos el registro
		    cancionero tem;
		    cin>>tem;
		    //escribimos la informacion el el registro
		    escribir.write( reinterpret_cast<char*>(&tem), sizeof( cancionero ) );

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
	    break;
	  }

	  //crear archivo de canciones del dia siguiente
	case 2:
	  {


	    //medimos la cantidad de registros que posee el archivo

	    int cant=0;
	    int *aescribir;
	    fstream general;
	    cancionero *ordenado;
	    cancionero *nuevo;
	    fstream can_dia;

	    general.open("canciones.dat", ios::in);
	    //verificamos
	    if(!general)
	      {
		cout<<"NO SE PUDO ABRIR EL ARCHIVO DE CANCIONES"<<endl;
	      }
	    else
	      {

		cancionero x;
		general.read( reinterpret_cast<char*>(&x), sizeof( cancionero ) );
		
		//leeemos el archivo y lo mostramos hasta el final
		while(general.eof()!=1)
		  {
		    cant++;
		    general.read( reinterpret_cast<char*>(&x), sizeof( cancionero ) );
		    
		  }
		
		general.close();
	      }


	    //deacuerdo a la cantidad de registros creamos un vector dinamico para ordenarlo
	    if(cant!=0)
	      {
		ordenado=new cancionero[cant];

		//llenamos el vector dinamico
		general.open("canciones.dat", ios::in);
		//verificamos
		if(!general)
		  {
		    cout<<"NO SE PUDO ABRIR EL ARCHIVO DE CANCIONES"<<endl;
		  }
		else
		  {
		    int i=0;

		    //llenamos el vector dinamico
		    general.read( reinterpret_cast<char*>(&ordenado[i]), sizeof( cancionero ) );
		    
		    //leeemos el archivo y lo mostramos hasta el final
		    while(general.eof()!=1)
		      {
			i++;
			general.read( reinterpret_cast<char*>(&ordenado[i]), sizeof( cancionero ) );
			
		      }
		    
		    general.close();
		  }
		
		//variables necesarias para ordenar el archivo
		cancionero temporal;
		hora h1,h2;

		//creamos la burbuja para ordenarlo
		for(int h=0;h<cant;h++)
		  {
		    for(int p=0;p<cant-1;p++)
		      {
			//verificamos las horas de cada uno a comparar
			h1=ordenado[p].obtener_hora();
			h2=ordenado[p+1].obtener_hora();
			//verificamos si las horas son menores
			if(h2<h1)
			  {

			    //hacemos los cambios necesarios
			    temporal.asignar_nombre(ordenado[p+1].obtener_nombre());
			    temporal.asignar_cantante(ordenado[p+1].obtener_cantante());
			    temporal.asignar_hora(ordenado[p+1].obtener_hora());

			    ordenado[p+1].asignar_nombre(ordenado[p].obtener_nombre());
			    ordenado[p+1].asignar_cantante(ordenado[p].obtener_cantante());
			    ordenado[p+1].asignar_hora(ordenado[p].obtener_hora());

			    ordenado[p].asignar_nombre(temporal.obtener_nombre());
			    ordenado[p].asignar_cantante(temporal.obtener_cantante());
			    ordenado[p].asignar_hora(temporal.obtener_hora());
			  }

		      }
		  }

		//escribimos nuevamente el archivo
		general.open("canciones.dat",ios::out);
		//verificamos
		if(!general)
		  {
		    cout<<"NO SE PUDO ABRIR EL ARCHIVO DE CANCIONES"<<endl;
		  }
		else
		  {
		    for(int h=0;h<cant;h++)
		      {
			//escribimos la informacion el el registro
			general.write( reinterpret_cast<char*>(&ordenado[h]), sizeof( cancionero ) );
		      }
		    delete [] ordenado;
		    general.close();
		  }
	      }

	    //creamos el nuevo archivo cancionero del dia
	    //verificamos que la cantidad de registros sea mayor que 0
	    if(cant!=0)
	      {

		//creamos un vector dinamico con los valores actuales del archivo
		nuevo=new cancionero[cant];
		int tama=cant;
		aescribir=new int [cant];

		//llenamos el vector dinamico
		general.open("canciones.dat", ios::in);
		//verificamos
		if(!general)
		  {
		    cout<<"NO SE PUDO ABRIR EL ARCHIVO DE CANCIONES"<<endl;
		  }
		else
		  {
		    int i=0;

		    //llenamos el vector dinamico
		    general.read( reinterpret_cast<char*>(&nuevo[i]), sizeof( cancionero ) );
		    
		    //leeemos el archivo y lo mostramos hasta el final
		    while(general.eof()!=1)
		      {
			i++;
			general.read( reinterpret_cast<char*>(&nuevo[i]), sizeof( cancionero ) );
			
		      }
		    
		    general.close();
		  }
		//ya llenado el vector procedemos a hacer las comparaciones

		aescribir[0]=1;
		int comparar=0;
		for(int h=1;h<cant;h++)
		  {

		    //variables que contendran la diferencia de horas
		    int se;
		    hora hor1,hor2,hor3;
		    hor1=nuevo[comparar].obtener_hora();
		    hor2=nuevo[h].obtener_hora();
		    hor3=hor1-hor2;
		    se=hor3.convertir_en_segundos();
		    //verificamos que tengan una diferencia de 2 minutos entre ellos
		    if(se<120)
		      {

			//creamos los que supuestamente no se van a guardar en el archivo 
			aescribir[h]=0;

		      }
		    //mayor 60
		    else
		      {
			aescribir[h]=1;
			comparar=h;

		      }
		  }

		int compa1,compa2,cd;
		for(int p=0;p<cant;p++)
		  {
		    if(aescribir[p]==1)
		      {
			compa1=p;
			cd=p+1;
			while(cd<cant)
			  {
			    if(aescribir[cd]==1)
			      {
				compa2=cd;
				hora horita1,horita2;
				horita1=nuevo[compa1].obtener_hora();
				horita2=nuevo[compa2].obtener_hora();
				if(horita1.obtener_hora()==horita2.obtener_hora())
				  {
				    //comparamos sus nombres
				    if((compara_palabras(nuevo[compa1].obtener_nombre(),nuevo[compa2].obtener_nombre()))&&(compara_palabras(nuevo[compa1].obtener_cantante(),nuevo[compa2].obtener_cantante())))
				      {
					aescribir[compa2]=0;
				      }
				  }


			      }
			    cd++;
			  }

		      }
		  }

		//escribimos la informacion el el archivo cancionero
		can_dia.open("cancionero_del_dia.dat",ios::out);
		//verificamos
		if(!can_dia)
		  {
		    cout<<"NO SE PUDO ABRIR EL ARCHIVO DE CANCIONES"<<endl;
		  }
		else
		  {
		    for(int h=0;h<cant;h++)
		      {
			if(aescribir[h]==1)
			  {
			    //escribimos la informacion el el registro
			    can_dia.write( reinterpret_cast<char*>(&nuevo[h]), sizeof( cancionero ) );
			  }		      
		      }
		    
		    can_dia.close();
		  }






	      }

	    
	    cout<<"Se creo el Archivo Satisfactoriamente"<<endl;

	    getchar();
	    getchar();
	    delete [] nuevo;
	    delete [] aescribir;
	    break;
	  }
	case 3:
	  {

	    //variables internas
	    int terminar3=1;
	    int op3;


	    do
	      {
		
		system("clear");
		cout<<"1. Ver Archivo de canciones"<<endl<<"2. Ver Archivo de las canciones que se van a tocar el otro dia"<<endl<<"3. Volver al menu anterior"<<endl;
		cout<<"Opccion: ";
		cin>>op3;
		switch(op3)
		  {

		    //ver archivo de canciones
		  case 1:
		    {
		      //variables internas
		      fstream leer;


		      //abrimos el archivo de canciones para lectura
		      leer.open("canciones.dat",ios::in);

		      //verificamos que se pudo abrir
		      if(!leer)
			{
			  cout<<"NO SE PUDO ABRIR EL ARCHIVO DE CANCIONES"<<endl;
			}
		      else
			{

			  cancionero temp2;
			  leer.read( reinterpret_cast<char*>(&temp2), sizeof( cancionero ) );
			  
			  //leeemos el archivo y lo mostramos hasta el final
			  while(leer.eof()!=1)
			    {
			      cout << temp2;
			      cout<<endl;
			      leer.read( reinterpret_cast<char*>(&temp2), sizeof( cancionero ) );

			    }
			  //cerramos el archivo
			  leer.close();
			}

		      getchar();
		      getchar();
		      break;
		    }
		  case 2:
		    {

		      //variables internas
		      fstream leer_ca;

		      //abrimos el archivo de canciones para lectura
		      leer_ca.open("cancionero_del_dia.dat",ios::in);

		      //verificamos que se pudo abrir
		      if(!leer_ca)
			{
			  cout<<"NO SE PUDO ABRIR EL ARCHIVO DE CANCIONES"<<endl;
			}
		      else
			{

			  cancionero temp2;
			  leer_ca.read( reinterpret_cast<char*>(&temp2), sizeof( cancionero ) );
			  
			  //leeemos el archivo y lo mostramos hasta el final
			  while(leer_ca.eof()!=1)
			    {
			      cout << temp2;
			      cout<<endl;
			      leer_ca.read( reinterpret_cast<char*>(&temp2), sizeof( cancionero ) );

			    }
			  //cerramos el archivo
			  leer_ca.close();
			}

		      getchar();
		      getchar();

		      break;
		    }
		  case 3:
		    {
		      terminar3=0;
		      break;
		    }
		  default:
		    {
		      cout<<"Opcion invalida"<<endl;
		      getchar();
		      getchar();
		      break;
		    }
		  }
	      }
	    while(terminar3);
	    
	    
	    

	    break;
	  }
	case 4:
	  {
	    cout<<"Gracias por usar el sistema"<<endl;
	    terminar=0;
	    getchar();
	    getchar();
	    break;
	  }
	default:
	  {
	    cout<<"Opcion invalida"<<endl;
	    getchar();
	    getchar();
	    break;
	  }
	}
    }
  while(terminar);


  /*  
  cancionero reg,reg2;
  fstream a;
  
  a.open("texto.dat",ios::out);
  
  
  
  for(int i=0;i<2;i++){
    cin>>reg;
    a.write( reinterpret_cast<char*>(&reg), sizeof( cancionero ) );
  }
  
  a.close();
  a.open("texto.dat",ios::in);
  
  for(int j=0;j<2;j++){
    a.read( reinterpret_cast<char*>(&reg2), sizeof( cancionero ) );
    cout << reg2;
    cout<<endl;
  }
  */

  return 0;
}
