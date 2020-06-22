#include "iostream"

using namespace std;

float pro(int n, float *no){
	float s=0;

	for(int i=0; i<n; i++){
		cout<<"nota del estudiante "<<i+1<<": ";
		cin>>no[i];

		s=no[i]+s;
	}

	return s;
}

main(){
	int n; 
	float s;

	cout<<"cuantos alumnos decea ingresar?"<<endl;
	cin>>n;

	float *notas = new float[n];

	s=pro(n,notas);

	cout<<"el promedio de las notas ingresadas es: "<<s/n<<endl;

	delete [] notas;

}
