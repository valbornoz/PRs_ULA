/*
Realizar un programa en C++ que declare un registro strClase; 
con los campos materia, carrera, semestre, profesor y nroAlumnos, 
y utilice (asignación y consulta) esta estructura en el programa 
principal.
*/
#include <iostream>
using namespace std;

struct strClase {
   char materia[30];
   char carrera[80];
   char semestre[4];
   int nroAlumnos;
};

int main(){
   struct strClase est;

   cout << "Nombre de la materia: ";
   cin >> est.materia;
   
   cout << "Nombre de la carrera: ";
   cin >> est.carrera;
   
   cout << "Semestre [X-00]: ";
   cin >> est.semestre;
      
   cout << "Número de alumnos: ";         
   cin >> est.nroAlumnos; 
     
   cout << endl << endl << "Datos registrados: " << endl<<endl;
   cout << "Materia " << est.materia << ", de la carrera ";
   cout << est.carrera << ", pertenece al semestre " << est.semestre;
   cout << " y cuenta con " << est.nroAlumnos << " alumnos." << endl;
}
