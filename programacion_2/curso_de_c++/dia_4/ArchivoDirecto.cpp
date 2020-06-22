#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int x = 4;
	fstream escritura;
	escritura.open("archivo.dat",ios::out | ios::binary );

	escritura.seekp(12);	
	
	escritura.write(reinterpret_cast<char*>(&x),sizeof(x));
	
	escritura.close();

	fstream lectura;
	lectura.open("archivo.dat",ios::in | ios::binary);
	
	if(!lectura)
	{
		cout << "No abrio el Archivo" << endl;
	}
	else
	{
		int data;
		lectura.seekg(10);
		lectura.read(reinterpret_cast<char*>(&data),sizeof(data));
		cout << data << endl;
		lectura.close();
		//getline(xx,ve,'%')
	}
	


	return 0;
}
