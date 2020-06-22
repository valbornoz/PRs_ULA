#include <iostream>
using namespace std;

int main() {
   char nombre[20];
   int i=0;
   
   cout << "Introduzca su nombre: ";
   cin >> nombre;
   while(nombre[i]!='\0') {
      i++;
   }
   cout << nombre << " tiene " << i << " letras." << endl;
}

    
