#include "iostream"

using namespace std;

struct Fecha{
	int dia;
	int mes;
	int anio;
};

struct Falla{
	char ubicacion[20];
	int tipo;
	struct Fecha fecha;
};

int nfallas(struct Falla *f1, int n);

main(){
	int n, h;

	cout<<"cuantas fallas decea introducir?"<<endl;
	cin>>n;

	struct Falla *f1 = new struct Falla[n];

	for(int i=0; i<n; i++){
		cout<<"donde ocurrio la falla "<<i+1<<"?"<<endl;
		cin>>f1[i].ubicacion;
		cout<<"de que tipo fue la falla "<<i+1<<"?"<<endl;
		cin>>f1[i].tipo;
		cout<<"cuando ocurrio la falla "<<i+1<<"?"<<endl;
		cin>>f1[i].fecha.dia>>f1[i].fecha.mes>>f1[i].fecha.anio;

	}

	h=nfallas(f1,n);

	cout<<"se produjeron "<< h <<" fallas de tipo 2 en enero de 2012"<<endl;

delete [] f1;
}

int nfallas(struct Falla *f1, int n){
		int h=0;

	for(int i=0; i<n; i++){
		if(f1[i].fecha.mes==1 and f1[i].fecha.anio==2012 and f1[i].tipo==2){		
			h++;
		}
	}

	return h;
}




