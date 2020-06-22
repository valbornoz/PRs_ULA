#include "Libro.h"
#include <iostream>
#include <string>


using namespace std;

int main()
{
  int cod, pag;
  string titulo;
 
  Libro L1;
  cout <<"Introduzca el Titulo del Libro: "<< endl;
  cin>>titulo;
  cout <<"Introduzca el Codigo: "<< endl;
  cin>>cod;
  cout <<"Introduzca el Número de Paginas: "<< endl;
  cin>>pag;
  L1.establecerCodigo(cod);
  L1.establecerPaginas(pag);
  L1.establecerTitulo(titulo);
  L1.imprime();
}
