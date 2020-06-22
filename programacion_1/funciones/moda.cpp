#include <iostream>
using namespace std;

int moda(int vector[20]);

int main(){

	int v[20];

	int i=0,mod;

	cout<<"introduzca los valores"<<endl;

	while(i!=20){
		cin>>v[i];
		i++;
	}

	mod=moda(v);

	cout<<"la moda es: "<<mod<<endl;

	return 0;
}
int moda(int vector[20]){

	int i=0, max, j=0;
	int contador[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			if(vector[i]==vector[j])
				contador[i]++;
		}
	}

	max=0;
	for(i=0; i<20; i++){
		if(contador[max]<contador[i])
			max=i;
	}

	for(i=0; i<20; i++){
		if(contador[i]==contador[max])
			if(vector[i]!=vector[max])
				cout<<vector[i]<<endl;
	}

	return vector[max];

}
