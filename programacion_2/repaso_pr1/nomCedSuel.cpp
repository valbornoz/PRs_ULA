#include <iostream>
using namespace std;

void f(char *n, int *c, float *s) {
   cout << "Nombre: ";
   cin >> n;
   cout << "Cédula: ";
   cin >> *c;
   cout << "Sueldo: ";
   cin >> *s;
}

int main(){
   char nombre[20];
   int cedula;
   float sueldo;
   
   f(nombre,&cedula,&sueldo);
   cout << nombre << ", " << cedula << ", " << sueldo << endl;
}
