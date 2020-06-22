#include<iostream>
#include<stdio.h>

using namespace std;

//creacion de las estructuras de datos o registros

typedef struct
{
  int hora, min, seg;

}hora;

typedef struct
{
  char intensidad_luz;
  float distancia;
  char color[10];
  char nombre[20];
  hora h;

}datos;


//declaraciones de prototipos


void llenar(datos *);




//cuerpo del programa

int main()
{

  int n,i,j;

  //declaramos el tamaño de la estructura nxn
  cout<<"\nIntroduzca el tamaño de la estructura de datos nxn" << endl; 
  cin >> n;

  //creamos la estructura nxn
  datos infor [n][n];



  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
	{

	  //llamamos a la funcion llenar
	  llenar(&infor[i][j]);

	}
    }
  cout <<n << endl;
  cout<< infor[0][0].nombre <<endl;
  return 0;
}


//procedimiento que llena la estructura
void llenar(datos *dat)
{
 
  cout<< "\nIntroduzca el nombre: " <<endl;
  cin>> dat->nombre;

}
