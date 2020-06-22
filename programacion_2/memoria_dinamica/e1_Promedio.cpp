/*
Realizar un programa en C++ que almacene las calificaciones de 
los alumnos de una secci�n y pase este vector a una funci�n que 
calcule el promedio de las calificaciones. El programa solicitar� 
la cantidad de alumnos que tiene la secci�n y no desperdiciar� 
espacio de memoria en el arreglo. Es decir, se debe realizar 
asignaci�n din�mica de memoria al crear el vector.
*/
#include <iostream>
using namespace std;

float promedio(int n, int *vN) {
   int i, suma = 0;
   float p;
   
   for(i=0;i<n;i++) {
      suma = suma + vN[i];
   }
   p = (float)suma / n;
   return p;
}

int main() {
   int *vNotas;
   int n,i;
   
   cout << "Ingrese la cantidad de estudiantes: ";
   cin >> n;
   
   vNotas = new int[n];
   
   for(i=0;i<n;i++){
      cout << "Nota del alumno " << i+1 << ": ";
      cin >> vNotas[i];
   }
   
   float p = promedio(n,vNotas);
   cout << "El promedio es: " << p << endl;
   delete [] vNotas;
   return 0;
}
