#include <iostream>
using namespace std;


int main()
{
	int x;
	x = 5;
	cout << "Valor: " << x << endl;
	cout << "Tamano: " << sizeof(x) << endl;
	cout << "Direccion: " << &x << endl;

	//declarar punteros
	int *p;

	p = &x;

	cout << "Valor: " << p << endl;
	cout << "Puntero: " << *p << endl;
	cout << "Tamano: " << sizeof(p) << endl;
	cout << "Direccion: " << &p << endl;

	//modifico el valor de x
	*p = 10;
	cout << "Valor: " << x << endl;

	int vec[10];

	int *punt;
	 punt = vec;
	for(int i = 0;i<10;i++)
	{
		punt[i]=i;
	}
	for(int i = 0;i<10;i++)
	{
		cout << punt[i] <<endl;
	}	

	//para reservar memoria
	// new
	
	int *que;
	
	que = new int[10];


	//matrices
	int m[10][10];
	int **ma;
	ma = new int*[10];
	for(int i = 0;i<10;i++)
	{
		ma[i] = new int[10];
	}

	int **mane;
	mane = ma;
	for(int i = 0;i<10;i++)
	{
		for(int j = 0;j<10;j++)
		{
			mane[i][j] = 0;
		}
	}	
	for(int i = 0;i<10;i++)
	{
		for(int j = 0;j<10;j++)
		{
			cout << mane[i][j] <<" ";
		}
		cout << endl;
	}
	return 0;
}










