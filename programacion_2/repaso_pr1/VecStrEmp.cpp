/*
Crear un programa en lenguaje C++ que defina un vector de 20 elementos. 
Los elementos serán de tipo estructura, y la estructura tendrá Nombre, apellido, 
cédula y salario. Codificar las funciones necesarias para ingresar datos a la 
estructura y mostrar estos datos.

Para el ejercicio anterior, agregar una función que liste el nombre de los 
empleados con sueldo mayor a 1000 Bs.
*/

#include <iostream>
using namespace std;

struct strEmpl{
   char nombre[20];
   char apellido[20];
   int cedula;
   float salario;
};


void lectura(struct strEmpl *nom, int n) {
   int i=0;
   
   cout << "**************************************" << endl;
   cout << "* INTRODUCCION DE DATOS DE EMPLEADOS *" << endl;
   cout << "**************************************" << endl;
   
   for(i=0; i<n; i++) {
      cout << "Empleado " << i+1 << ":" << endl;
      cout << "Nombre y apellido: ";
      cin >> nom[i].nombre >> nom[i].apellido;
      cout << "Cedula: ";
      cin >> nom[i].cedula;
      cout << "Salario: ";
      cin >> nom[i].salario; 
      cout << endl;     
   }
   cout << endl;
}

void mostrar(struct strEmpl *nom, int n) {
   int i=0;
   
  
   cout << "*********************************************" << endl;
   cout << "* E M P L E A D O S   R E G I S T R A D O S *" << endl;
   cout << "*********************************************" << endl;
   
   for(i=0; i<n; i++) {
      cout << "Empleado " << i+1 << ":" << endl;
      cout << nom[i].nombre << " " << nom[i].apellido << ", C.I. ";
      cout << nom[i].cedula << ", Salario: " << nom[i].salario << endl;
   }
   cout << "*********************************************" << endl;
}

void sM1000(struct strEmpl *nom, int n) {
   int i=0;
   

   cout << "*******************************************" << endl;
   cout << "* EMPLEADOS CON SUELDO MAYOR A 1000 Bs.F. *" << endl;
   cout << "*******************************************" << endl;
   
   for(i=0; i<n; i++) {
      if (nom[i].salario > 1000) {
         cout << nom[i].nombre << " " << nom[i].apellido;
         cout << ", C.I. " << nom[i].cedula << endl;
      }      
   }
   cout << "*******************************************" << endl;
}

int main(){
   struct strEmpl nomina[20];
   int n;
   
   cout << "Cantidad de empleados a ingresar: ";
   cin >> n;
   
   lectura(nomina, n);
   mostrar(nomina, n);
   sM1000(nomina, n);
}















/*void sM1000(struct strEmpl *nom, int n) {
   int i=0;
   

   cout << "*******************************************" << endl;
   cout << "* EMPLEADOS CON SUELDO MAYOR A 1000 Bs.F. *" << endl;
   cout << "*******************************************" << endl;
   
   for(i=0; i<n; i++) {
      if (nom[i].salario > 1000) {
         cout << nom[i].nombre << " " << nom[i].apellido;
         cout << ", C.I. " << nom[i].cedula << endl;
      }      
   }
   cout << "*******************************************" << endl;
}
*/
