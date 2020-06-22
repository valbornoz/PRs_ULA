
#include "Libro.h"
//#include <iostream>
//#include <string>


Libro::Libro()//constructor
{
  
  Titulo = " ";
  Cantpaginas = 0;
  Codigo = 0;
}
void Libro::establecerTitulo(string p)
{

    Titulo = p;
}
void Libro::establecerPaginas(int cant)
{
  Cantpaginas = cant;
}
void Libro::establecerCodigo(int cod)
{
  Codigo = cod;
}
void Libro::imprime()
{
  cout << "Titulo: " << Titulo << endl;
  cout << "Codigo: " << Codigo << endl;
  cout << "Cant pag: " << Cantpaginas << endl;
}
