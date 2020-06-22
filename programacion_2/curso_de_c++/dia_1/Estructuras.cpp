#include <iostream>
using namespace std;

struct hora
{
	int m;
	int s;
	int h;
};

struct fecha
{
	int d;
	int m;
	int a;
};

struct dia_actual
{
	hora h;
	fecha f;

};

struct Punto
{
	int x;	//coordenada x
	int y;	//coordenada y
};

void imprimirPunto(Punto pu)
{
	cout << pu.x << " " << pu.y << endl;
}

int main()
{
	Punto p;

	Punto vector [10];
	
	p.x = 10;
	p.y = 15;
	
	imprimirPunto(p);
	//cout << p.x << " " << p.y << endl;

	for(int i = 0; i <10;i++)
	{
		vector[i].x = i;
		vector[i].y = i;
	}	
	for(int i = 0; i <10;i++)
	{
		imprimirPunto(vector[i]);
		//cout << vector[i].x << " " << vector[i].y << endl;
	}


	//dia _actual
	dia_actual dia;



	dia.h.m=2;
	dia.h.s=2;
	dia.h.h=2;
	dia.f.d=2;
	dia.f.m=2;
	dia.f.a=2;
	

	return 0;
}
