
//archivo libro.h
//definicion de la clase

#include <iostream>
#include <string>
using namespace std;


class Libro {
private:
 
  string Titulo;
  int Cantpaginas;
  int Codigo;

 public:
  Libro();
  void establecerTitulo(string);
  void establecerPaginas(int);
  void establecerCodigo(int);
  void imprime();
 
};



