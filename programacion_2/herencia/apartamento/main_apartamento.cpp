#include <iostream>
#include "string.h"
#include"apartamento.h"
using namespace std;


int main(){

	int n;
	apartamento *a;


	int i;
	
	cout << "Cuántos apartamentos desea registrar? ";
        cin >> n;

	
	a = new apartamento[n];

	for( i=0; i<n; i++){

	a[i].lectura();
	
}

	cout << " " <<endl;
	cout<<" Los datos ingresados son" << endl;

	for( i=0; i<n; i++){

	a[i].mostrar();
	
}

	
	delete[] a;	


return 0;
}
