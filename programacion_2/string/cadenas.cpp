#include <iostream>
#include "string.h"
using namespace std;

/*
int main() {
   char nombre[10];
   cout << nombre << endl;
}
*/

/*
int main() {
   char nombre[10] = "Marcos";
   cout << nombre << endl;
}
*/
/*
int main() {
   char nombre[10];
   nombre = "Marcos";
   cout << nombre << endl;
}
*/
/*
int main() {
   char nombre[10];
   strcpy(nombre,"Marcos");
   cout << nombre << endl;
}
*/
/*
int main() {
   char nombre[10];
   strcpy(nombre,"Marcos Machado");
   cout << nombre << endl;
}
*/

/*int main() {
   char nombre[10];
   strncpy(nombre,"Marcos Machado",6);
   //nombre[9]='\0';
   cout << nombre << endl;
}
*/
/*
int main() {
   char nombre[20] = "Marcos";
   strcat(nombre," Machado");
   cout << nombre << endl;
}
*/
/*
int main() {
   char nombre[10] = "Marcos";
   strncat(nombre," Machado",3);
   cout << nombre << endl;
}
*/
/*
int main() {
   char nombre1[10] = "CASA";
   char nombre2[10] = "cASA";
   if (strcmp(nombre1,nombre2)) {
      cout << "Si, por supuesto!" << endl;
   } else {
      cout << "Tas loco!" << endl;
   }
}
*/
/*
int main() {
   char texto[] = "Algun escrito";
   cout << "El escrito tiene " << strlen(texto) << " letras." << endl;
}
*/
/*
int main() {
   cout << "H\no\nl\na" << endl;   
}
*/
/*
int main() {
   char nombre[5];
   cin >> nombre;  //Introducir "Eutanasio"
   cout << nombre << endl;
}
*/

int main(){
   char nombreYapellido[30];
   cin >> nombreYapellido; //Introducir "Jose Escalante"
   cout << nombreYapellido << endl;   
}

/*
int main(){
   char nombreYapellido[10];
   cin.getline(nombreYapellido,10); //Introducir "Jose Escalante"
   cout << nombreYapellido << endl;   
}
*/

