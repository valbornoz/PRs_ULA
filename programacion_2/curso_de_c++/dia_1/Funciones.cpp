#include <iostream>
using namespace std;

//definiendola directamente
void imprimirHola()
{
	cout << "hola" << endl;
}

//definicion del prototipo
void imprimirPrototipo();

//paso por copia
void impirmirEntero(int e)
{
	cout << e <<endl;
}
//paso por referencia
void leerEntero(int *p)
{
	//cin>>*p;
	cout << p << endl;
	cout << *p << endl;
	cin >> *p;
}

void imprimirVector(int * vec,int tam)
{
	for(int i = 0; i< tam;i++)
	{
		cout << vec[i] << endl;
	}
}


void imprimirVector2(int  vec[],int tam)
{
	for(int i = 0; i< tam;i++)
	{
		cout << vec[i] << endl;
	}
}

int main()
{
	imprimirHola();
	imprimirPrototipo();
	int x = 10;
	leerEntero(&x);
	impirmirEntero(x);

	int vector[10];
	for(int i = 0; i< 10;i++)
	{
		vector[i]=0;
	}
	imprimirVector(vector,10);
	imprimirVector2(vector,10);

	return 0;
}


//codigo del prototipo
void imprimirPrototipo()
{
	cout << "hola" << endl;
}
