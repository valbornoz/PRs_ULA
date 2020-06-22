#include <stdio.h>
//analogo de c
#include <iostream>

using namespace std;

int main()
{
	int x,y;
	float f;
	char c;
	char cadena[100];
	char *cad;
	

	//parte de c
	printf("HOLA\n");
	scanf("%d",&x);
	printf("%d Hola %d\n",x,x);

	//parte de C++
	/*std::cin >> y;
	std::cout<<"Hola" << std::endl;
	std::cout << y << std::endl;*/

	cin >> y;
	cout<<"Hola " << y << endl << "Hola " << y << endl;
	cout << y << endl;

	cout<<"Leemos un float: ";
	cin>>f;
	cout<<f<<endl;

	cout<<"Leemos un char: ";
	cin>>c;
	cout<<c<<endl;

	cout<<"Leemos una cadena: ";
	cin>>cadena;
//	getline(cin,cadena);
	cout<<cadena<<endl;

	cout << endl;
	int i=0;
	while(i<10)
	{
		cout<<i<<endl;
		i++;	//i = i+1;
	}
	cout << endl;
	int j = 0;
	do
	{
		cout<<j<<endl;
		j++;
	}while(j<10);

	cout << endl;

	for(int h = 0;h<10;h++)
	{
		cout<<h<<endl;
	}

	return 0;
}
