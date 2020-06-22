#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string>

using namespace std;

int main(){

	ifstream entrada;
	ofstream salida;
	entrada.open("entrada2.txt");
	salida.open("salida3.txt");

	string aux1, aux2;
	int largo;

	while(!entrada.eof()){
	
		getline(entrada,aux1,","); 
		getline(entrada,aux2);
	/*
		largo = aux1.length();
		if(aux1.size() == aux2.size()){
			for( int i=0;int j= largo-1; i<largo ; i++; j--){
				if (aux1[i]==aux2[j]){
					if(i==aux1.size()-1){
						salida << aux1 << " " << aux2 << endl;
					}
				}else{
					break;
				}
			}
		}
*/
	}

	entrada.close();
	salida.close();
	

	return 0;
}
