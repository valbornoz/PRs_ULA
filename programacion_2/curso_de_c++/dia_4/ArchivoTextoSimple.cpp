#include <iostream>
#include <fstream>
using namespace std;

int main()
{

	string cadena;

	ifstream lectura;	//solo maneja archivo para lectura
	ofstream escritura;	//solo maneja archivo para escritura
	fstream archivo;	//maneja el archivo para escritura o lectura

	//escribir en un archivo
	/*escritura.open("Texto.txt");	//sobreescribir
	
	escritura << "epale" << endl << endl <<endl;
	
	escritura.close();
	
	//cin>>cadena;
	getline(cin,cadena);
	
	escritura.open("Texto.txt",ios::app);	//continuar escribiendo al final del archivo
	
	escritura << "continuamos " << cadena << endl;
	
	escritura.close();*/

	/*escritura.open("Texto.txt",ios::app);

	getline(cin,cadena);
	while(cadena != "salir")
	{
		escritura << cadena <<10<< endl;
		getline(cin,cadena);
	}

	escritura.close();*/

	lectura.open("Texto.txt");

	if(!lectura)
	{
		cout<<"NO abrio el Archivo"<<endl;
	}
	else
	{
		string palabra;
		/*while(lectura>>palabra)		//leer palabra por palabra
		{
			cout << palabra << endl;
		}*/
		
		//forma de los profesores
		/*lectura>>palabra;
		while(!lectura.eof())
		{
			cout << palabra << endl;
			lectura>>palabra;
		}*/
		/*while(getline(lectura,palabra))		//leer linea por linea
		{
			cout << palabra << endl;
		}*/
		
		int cedula;
		string nombre;
		string apellido;
		float nota;
		/*while(lectura>>cedula and lectura>>nombre and lectura>>apellido and lectura>>nota)		//leer palabra por palabra
		{
			cout << nombre <<" "<<nota << endl;
		}*/
		while(lectura>>cedula and getline(lectura,nombre,'#') and getline(lectura,apellido,'#') and lectura>>nota)		//leer palabra por palabra
		{
			cout << nombre <<" "<<nota << endl;
		}

		lectura.close();
	}	

	return 0;
}
