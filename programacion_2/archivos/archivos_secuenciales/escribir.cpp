/* Programa que escribe sobre un archivo texto */

#include <iostream>
#include <fstream> 
#include <string>
using namespace std;

int main () {
    ofstream archSalida;
    archSalida.open("salida.txt", ios::app);
    char texto[80];
    int i=0;
    char cRespuesta;
    
    do {
       cout << "Linea " << i+1 << ":" << endl;
       cin.getline(texto,80);
        
       archSalida << texto << endl;
       
       cout << "Desea continuar escribiendo? (S/N): ";
       cin >> cRespuesta;
       i++;
       getchar();       
    }while ((cRespuesta!='N')&&(cRespuesta!='n'));
    
    archSalida.close();
}

