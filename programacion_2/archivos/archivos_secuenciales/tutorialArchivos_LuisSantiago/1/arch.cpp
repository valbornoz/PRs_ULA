#include <iostream>
#include <fstream>
#include <string>

#include <cstdlib>
int main(){
/*
	std::ifstream archivo1;
	std::string linea1, linea2, linea3, linea4, linea5;
	double a;
	float z[7], mayor=0;
	int i=0;
	archivo1.open("./numeros.txt");
	while(!archivo1.eof())
	{

		std::getline(archivo1,linea1,'|');
		std::getline(archivo1,linea2,'|');
		std::getline(archivo1,linea3,'|');
		std::getline(archivo1,linea4,'|');
		std::getline(archivo1,linea5,'\n');

		a=(atof(linea3.c_str())+atof(linea4.c_str())+atof(linea5.c_str()))/3;
		if(archivo1.fail())
			break;
		z[i]=a;
		i++;
	}
	std::cout<<linea2<<"\n";
	std::cout<<"promedio es:"<<a<<"\n";
	mayor=z[0];
	for(int j=1;j<7;j++){
		if(z[j]>mayor) mayor=z[j];
	}
	std::cout<<"el mayor promedio es"<<mayor<<"\n";
	archivo1.close();
*/




	std::ofstream archivo1;
	int x;
	std::string y, z;
	z="archivo1.txt";
	
	std::cout<<"cuantos nombres desea agregar?";
	std::cin>>x;
	archivo1.open(z.c_str());
	for(int i=0;i<x;i++){
		std::cout<<"dame el nombre numero:"<<i;
		std::cin>>y;
		archivo1<<y<<"\n";
	}
	archivo1.close();
	return 0;
}
