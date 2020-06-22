#include <iostream>
using namespace std;

int main(){

	int a,b,aux;
	int* c, *d;

	cin>>a>>b;
	cout<<"a: "<<a<<"b: "<<b<<endl;

	c=&a;
	d=&b;

	aux=a;

	*c=b;
	*d=aux;

	cout<<"a: "<<a<<"b: "<<b<<endl;

	return 0;
}
